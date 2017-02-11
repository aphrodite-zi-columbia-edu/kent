kentSrc = ../..
include ../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../lib/${MACHTYPE}
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = geneOverlap.o

geneOverlap: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/geneOverlap $O $(MYLIBS) $L

clean:
	rm -f $O
