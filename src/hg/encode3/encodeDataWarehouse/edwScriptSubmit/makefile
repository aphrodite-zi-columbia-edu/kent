kentSrc = ../../../..
include $(kentSrc)/inc/common.mk

L += -luuid -lm ${MYSQLLIBS} -ldl -lm
MYLIBDIR = $(kentSrc)/lib/${MACHTYPE}
MYLIBS =  ../lib/$(MACHTYPE)/edwlib.a ${MYLIBDIR}/jkhgap.a ${MYLIBDIR}/jkweb.a

A = edwScriptSubmit

O = $A.o 

include $(kentSrc)/inc/cgi_build_rules.mk

compile: $O 
	${CC} $O ${MYLIBS} ${L} 
	mv ${AOUT} $A${EXE}
