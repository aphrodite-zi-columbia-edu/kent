kentSrc = ../..
include ../../inc/common.mk

L += ${MYSQLLIBS} -lm -ldl -lm
MYLIBDIR = ../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkhgap.a ${MYLIBDIR}/jkweb.a

A = hgSuggest

O = $A.o

include ../../inc/cgi_build_rules.mk

compile: $O
	${CC} -o $A $O ${MYLIBS} ${L}
