kentSrc = ../../..
include ../../../inc/common.mk

L += $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = evalEnds.o

evalEnds: $O 
	${CC} ${COPT} ${CFLAGS} -o evalEnds $O $(MYLIBS) $L

clean::
	rm -f ${O}
