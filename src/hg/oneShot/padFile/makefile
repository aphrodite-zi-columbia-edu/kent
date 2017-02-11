kentSrc = ../../..
include ../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = padFile.o

padFile: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/padFile $O $(MYLIBS) $L
	${STRIP} ${BINDIR}/padFile${EXE}

clean::
	rm -f ${O}
