/* tagToSql - convert tagStorm to a SQL table.  See src/tagStorm/tagStormToTab/tagStormToTab.c
 * for how to use this. */

#include "common.h"
#include "hash.h"
#include "dystring.h"
#include "sqlNum.h"
#include "obscure.h"
#include "tagStorm.h"
#include "tagToSql.h"

struct tagTypeInfo *tagTypeInfoNew(char *name)
/* Return initialized new tagTypeInfo */
{
struct tagTypeInfo *tti;
AllocVar(tti);
tti->name = cloneString(name);
tti->isUnsigned = tti->isInt = tti->isNum = TRUE;
tti->minVal = BIGDOUBLE;
tti->maxVal = -BIGDOUBLE;
return tti;
}

void tagTypeInfoFree(struct tagTypeInfo **pTti)
/* Free up a tagTypeInfo */
{
struct tagTypeInfo *tti = *pTti;
if (tti != NULL)
    {
    freeMem(tti->name);
    freez(pTti);
    }
}

static int tagTypeInfoCmpName(const void *va, const void *vb)
/* Compare two tagTypeInfo's by name field */
{
const struct tagTypeInfo *a = *((struct tagTypeInfo **)va);
const struct tagTypeInfo *b = *((struct tagTypeInfo **)vb);
return strcasecmp(a->name, b->name);
}

static char *tfForInt(int i)
/* Return "T" or "F" depending on whether i is nonzero */
{
if (i)
    return "T";
else
    return "F";
}

void tagTypeInfoDump(struct tagTypeInfo *list, char *fileName)
/* Dump out types to file */
{
FILE *f = mustOpen(fileName, "w");
struct tagTypeInfo *tti;
for (tti = list; tti != NULL; tti = tti->next)
    {
    fprintf(f, "%s\tu=%s, i=%s, n=%s, min=%g, max=%g, chars=%d\n", 
	tti->name, tfForInt(tti->isUnsigned), tfForInt(tti->isInt), tfForInt(tti->isNum), 
	tti->minVal, tti->maxVal, tti->maxChars);
    }
carefulClose(&f);
}

void tagTypeInfoAdd(struct tagTypeInfo *tti, char *val)
/* Fold in information about val into tti. */
{
int len = strlen(val);
if (len > tti->maxChars)
     tti->maxChars = len;
if (!tti->isNum)
    return;

/* Convert to a double and check that it really is a double */
char *end = NULL;
double v = strtod(val, &end);
if (end == val || *end != 0)	// val is not just a floating point number
    {
    tti->maxVal = tti->minVal = 0.0;
    tti->isUnsigned = tti->isInt = tti->isNum = FALSE;
    return;
    }

/* Update min and max */
if (v > tti->maxVal) tti->maxVal = v;
if (v < tti->minVal) tti->minVal = v;

if (tti->isUnsigned)
    {
    if (isAllDigits(val))
	return;
    else
	tti->isUnsigned = FALSE;
    }
if (tti->isInt)
    {
    if (val[0] == '-')
	{
	if (isAllDigits(val+1))
	    return;
	else
	    tti->isInt = FALSE;
	}
    else
	{
	if (isAllDigits(val))
	    return;
	else
	    tti->isInt = FALSE;
	}
    }
}

static void rInfer(struct tagStanza *list, struct hash *hash, struct tagTypeInfo **pList)
/* Traverse recursively updating hash with type of each field. */
{
struct tagStanza *stanza;
for (stanza = list; stanza != NULL; stanza = stanza->next)
    {
    struct slPair *pair;
    for (pair = stanza->tagList; pair != NULL; pair = pair->next)
        {
	char *tag = pair->name;
	char *val = pair->val;
	struct tagTypeInfo *tti = hashFindVal(hash, tag);
	if (tti == NULL)
	     {
	     tti = tagTypeInfoNew(tag);
	     hashAdd(hash, tag, tti);
	     slAddHead(pList, tti);
	     }
	tagTypeInfoAdd(tti, val);
	}
    if (stanza->children)
        rInfer(stanza->children, hash, pList);
    }
}

void tagStormInferTypeInfo(struct tagStorm *tagStorm, 
    struct tagTypeInfo **retList, struct hash **retHash)
/* Go through every tag/value in storm and return a hash that is
 * keyed by tag and a tagTypeInfo as a value */
{
struct hash *hash = hashNew(0);
struct tagTypeInfo *list = NULL;
rInfer(tagStorm->forest, hash, &list);
slSort(&list, tagTypeInfoCmpName);
*retList = list;
*retHash = hash;
}

void tagStormToSqlCreate(struct tagStorm *tagStorm,
    char *tableName, struct tagTypeInfo *ttiList, struct hash *ttiHash,
    char **keyFields, int keyFieldCount, struct dyString *createString)
/* Make a mysql create string out of ttiList/ttiHash, which is gotten from
 * tagStormInferTypeInfo.  Result is in createString */
{
/* Make sure that don't get a name collision in SQL, which is case insensitive in field
 * names. */
struct slName *fieldList = tagStormFieldList(tagStorm);
ensureNamesCaseUnique(fieldList);
slFreeList(&fieldList);

/* Construct create table statement using minimal types */
dyStringPrintf(createString, "CREATE TABLE %s (", tableName);
char *connector = "";
int totalFieldWidth = 0;
struct tagTypeInfo *tti;
for (tti = ttiList; tti != NULL; tti = tti->next)
    {
    int fieldWidth = 0;
    char *sqlType = NULL;
    char sqlTypeBuf[256];
    if (!isSymbolString(tti->name))
        errAbort("Error - database needs work. Somehow symbol %s got in field list\n", tti->name);
    if (tti->isUnsigned)
	{
	long long maxTinyUnsigned = (1<<8)-1;    // Fits in one byte
	long long maxSmallUnsigned = (1<<16)-1;  // Fits in two bytes
	long long maxMediumUnsigned = (1<<24)-1; // Fits in three bytes
	long long maxIntUnsigned = (1LL<<32)-1;  // Fits in four bytes

	if (tti->maxVal <= maxTinyUnsigned)
	    {
	    sqlType = "tinyint unsigned";
	    fieldWidth = 1;
	    }
	else if (tti->maxVal <= maxSmallUnsigned)
	    {
	    sqlType = "smallint unsigned";
	    fieldWidth = 2;
	    }
	else if (tti->maxVal <= maxMediumUnsigned)
	    {
	    sqlType = "mediumint unsigned";
	    fieldWidth = 3;
	    }
	else if (tti->maxVal <= maxIntUnsigned)
	    {
	    sqlType = "int unsigned";
	    fieldWidth = 4;
	    }
	else 
	    {
	    sqlType = "bigint unsigned";
	    fieldWidth = 8;
	    }
	}
    else if (tti->isInt)
        {
	long long minTinyInt = -128, maxTinyInt = 127;  // Fits in one byte
	long long minSmallInt = -32768, maxSmallInt = 32767; // Fits in two bytes
	long long minMediumInt = -8388608, maxMediumInt = 8388607;  // Fits in three bytes
	long long minInt = -2147483648LL, maxInt = 2147483647LL; // Fits in three bytes
	if (tti->minVal >= minTinyInt  && tti->maxVal <= maxTinyInt)
	    {
	    sqlType = "tinyint";
	    fieldWidth = 1;
	    }
	else if (tti->minVal >= minSmallInt  && tti->maxVal <= maxSmallInt)
	    {
	    sqlType = "smallint";
	    fieldWidth = 2;
	    }
	else if (tti->minVal >= minMediumInt  && tti->maxVal <= maxMediumInt)
	    {
	    sqlType = "mediumint";
	    fieldWidth = 3;
	    }
	else if (tti->minVal >= minInt  && tti->maxVal <= maxInt)
	    {
	    sqlType = "int";
	    fieldWidth = 4;
	    }
	else
	    {
	    sqlType = "bigint";
	    fieldWidth = 8;
	    }
	}
    else if (tti->isNum)
        {
	sqlType = "double";
	fieldWidth = 8;
	}
    else
        {
	if (tti->maxChars <= 255)
	    {
	    safef(sqlTypeBuf, sizeof(sqlTypeBuf), "varchar(%d)", tti->maxChars);
	    sqlType = sqlTypeBuf;
	    fieldWidth = tti->maxChars + 1;
	    }
	else
	    {
	    sqlType = "longblob";
	    fieldWidth = 12;   // May be 9-12, not sure how to tell.
	    }
	}
    totalFieldWidth += fieldWidth;
    dyStringPrintf(createString, "\n%s%s %s", connector, tti->name, sqlType);
    connector = ", ";
    }

/* Check that we don't overflow a MySQL MYISAM buffer */
int myisamLimit = 65535;
verbose(2, "totalFieldWidth = %d, limit %d\n", totalFieldWidth, myisamLimit);
if (totalFieldWidth > myisamLimit)   // MYISAM limit
    {
    errAbort("Looks like we are going to have to switch to INNODB for the %s table, rats!",
	tableName);
    }

/* Add in the indexes. */
int i;
for (i=0; i<keyFieldCount; ++i)
    {
    char *key = keyFields[i];
    struct tagTypeInfo *tti = hashFindVal(ttiHash, key);
    if (tti != NULL)
        {
	if (tti->isNum)
	    {
	    dyStringPrintf(createString, "%sINDEX(%s)", connector, key);
	    }
	else
	    {
	    int indexSize = tti->maxChars;
	    if (indexSize > 16)
	        indexSize = 16;
	    dyStringPrintf(createString, "%sINDEX(%s(%d))", connector, key, indexSize);
	    }
	}
    }

/* Close up and return result */
dyStringPrintf(createString, ")");
}

void tagStanzaToSqlInsert(struct tagStanza *stanza, char *table, struct dyString *dy)
/* Put SQL insert statement for stanza into dy. */
{
dyStringPrintf(dy, "insert %s (", table);
struct slPair *tag, *tagList = tagListIncludingParents(stanza);
char *connector = "";
for (tag = tagList; tag != NULL; tag = tag->next)
    {
    dyStringPrintf(dy, "%s%s", connector, tag->name);
    connector = ",";
    }
dyStringPrintf(dy, ") values (");
connector = "";
for (tag = tagList; tag != NULL; tag = tag->next)
    {
    char *escaped = makeEscapedString(tag->val, '"');
    dyStringPrintf(dy, "%s\"%s\"", connector, escaped);
    freeMem(escaped);
    connector = ",";
    }
dyStringPrintf(dy, ")");
slPairFreeList(&tagList);
}

