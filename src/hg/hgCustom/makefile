kentSrc = ../..
include ../../inc/common.mk

HG_WARN=-Wall

L += -lm ${MYSQLLIBS} -ldl -lm
MYLIBDIR = ../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkhgap.a $(MYLIBDIR)/jkweb.a

A = hgCustom

O = $A.o

include ../../inc/cgi_build_rules.mk
 
compile: $O
	${CC} -o $A${EXE} -g $O ${MYLIBS} ${L}

