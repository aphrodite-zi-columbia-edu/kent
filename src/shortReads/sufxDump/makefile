kentSrc = ../..
include ../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkweb.a

O = sufxDump.o

sufxDump: $O ${MYLIBS}
	${CC} ${COPT} -o ${BINDIR}/sufxDump $O ${MYLIBS} $L
	${STRIP} ${BINDIR}/sufxDump${EXE}

clean:
	rm -f $O
