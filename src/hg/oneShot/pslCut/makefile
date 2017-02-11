kentSrc = ../../..
include ../../../inc/common.mk

L += $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = pslCut.o

pslCut: $O 
	${CC} ${COPT} ${CFLAGS} -o pslCut $O $(MYLIBS) $L

clean::
	rm -f ${O}
