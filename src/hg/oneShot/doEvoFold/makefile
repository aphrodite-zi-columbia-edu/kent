kentSrc = ../../..
include ../../../inc/common.mk

L += -lm $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = doEvoFold.o

doEvoFold: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/doEvoFold $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/doEvoFold${EXE}

clean::
	rm -f ${O}
