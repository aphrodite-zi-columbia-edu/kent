kentSrc = ../..
include ../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkhgap.a ${MYLIBDIR}/jkweb.a

O = pslSomeRecords.o

pslSomeRecords: $O ${MYLIBS}
	${CC} ${COPT} -o ${BINDIR}/pslSomeRecords $O ${MYLIBS} $L
	${STRIP} ${BINDIR}/pslSomeRecords${EXE}

clean:
	rm -f $O
