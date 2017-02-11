kentSrc = ../../..
include ../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = chimpSuperQuals.o

chimpSuperQuals: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/chimpSuperQuals $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/chimpSuperQuals${EXE}

clean::
	rm -f ${O}
