kentSrc = ../../..
include ../../../inc/common.mk

L += -lm $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/${MACHTYPE}
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = dupedInTable.o

dupedInTable: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/dupedInTable $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/dupedInTable${EXE}

clean::
	rm -f ${O}
