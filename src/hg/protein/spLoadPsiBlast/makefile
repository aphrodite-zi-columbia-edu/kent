kentSrc = ../../..
include ../../../inc/common.mk

L += -lm $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS = $(MYLIBDIR)/jkpbap.a $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = spLoadPsiBlast.o

${BINDIR}/spLoadPsiBlast: $O $(MYLIBS)
	${CC} ${CFLAGS} -o $@ $O $(MYLIBS) $L

clean::
	rm -f ${O}
