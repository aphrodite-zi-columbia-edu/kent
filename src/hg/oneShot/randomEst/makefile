kentSrc = ../../..
include ../../../inc/common.mk

L += -lm $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = randomEst.o

randomEst: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/randomEst $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/randomEst${EXE}

clean::
	rm -f ${O}
