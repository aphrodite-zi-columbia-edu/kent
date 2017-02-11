kentSrc = ../../..
include ../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = htTpf.o

htTpf: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/htTpf $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/htTpf${EXE}

clean::
	rm -f ${O}
