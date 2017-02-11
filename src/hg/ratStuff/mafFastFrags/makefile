kentSrc = ../../..
include ../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkweb.a

O = mafFastFrags.o

mafFastFrags: $O ${MYLIBS}
	${CC} ${COPT} -o ${BINDIR}/mafFastFrags $O ${MYLIBS} $L
	${STRIP} ${BINDIR}/mafFastFrags${EXE}

clean:
	rm -f $O
