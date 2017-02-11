kentSrc = ../../..
include ../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = chainStitch.o

chainStitch: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/chainStitch $O $(MYLIBS) $L
#	${STRIP} ${BINDIR}/chainStitch${EXE}

clean::
	rm -f ${O}
