# sgdDescription.sql was originally generated by the autoSql program, which also 
# generated sgdDescription.c and sgdDescription.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Description of SGD Genes and Other Features
CREATE TABLE sgdOtherDescription (
    name varchar(16) not null,	# Name in sgdGene or sgdOther table
    type varchar(255) not null,	# Type of feature from gff3 file
    description longblob not null,	# Description of feature
              #Indices
    PRIMARY KEY(name(16))
);
