kentSrc = ../../..
include ../../../inc/common.mk

L += -lm ${MYSQLLIBS}  -ldl -lm
MYLIBDIR = ../../../lib/${MACHTYPE}
MYLIBS =  $(MYLIBDIR)/jkhgap.a ${MYLIBDIR}/jkweb.a

O = hgGetNrOmimGene.o

hgGetNrOmimGene: $O ${MYLIBS}
	${CC} ${COPT} -o ${BINDIR}/hgGetNrOmimGene $O ${MYLIBS} $L
	${STRIP} ${BINDIR}/hgGetNrOmimGene${EXE}

clean:
	rm -f $O
