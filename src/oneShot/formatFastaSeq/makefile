kentSrc = ../..
include ../../inc/common.mk


L += -lm -ldl -lm
MYLIBDIR = ../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = formatFastaSeq.o

formatFastaSeq: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/formatFastaSeq $O $(MYLIBS) $L

clean::
	rm -f ${O}
