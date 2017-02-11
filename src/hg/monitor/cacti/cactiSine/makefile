kentSrc = ../../../..
include ../../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkweb.a

O = cactiSine.o

cactiSine: $O ${MYLIBS}
	${CC} ${COPT} -o ${BINDIR}/cactiSine $O ${MYLIBS} $L
	${STRIP} ${BINDIR}/cactiSine${EXE}

clean:
	rm -f $O
