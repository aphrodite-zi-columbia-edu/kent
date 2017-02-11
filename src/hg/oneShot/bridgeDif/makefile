kentSrc = ../../..
include ../../../inc/common.mk

L += $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = bridgeDif.o

bridgeDif: $O 
	${CC} ${COPT} ${CFLAGS} -o bridgeDif $O $(MYLIBS) $L

clean::
	rm -f ${O}
