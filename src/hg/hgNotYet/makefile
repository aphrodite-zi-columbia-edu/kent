kentSrc = ../..
include ../../inc/common.mk

L += -lm ${MYSQLLIBS} -ldl -lm
MYLIBDIR = ../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkhgap.a ${MYLIBDIR}/jkweb.a

A = hgNotYet

O = $A.o

include ../../inc/cgi_build_rules.mk

compile: $O 
	${CC} $O ${MYLIBS} ${L} 
	mv ${AOUT} $A${EXE}
