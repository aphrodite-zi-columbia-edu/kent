kentSrc = ../../..
include ../../../inc/common.mk

L += $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = tempLower.o

tempLower: $O 
	${CC} ${COPT} ${CFLAGS} -o tempLower $O $(MYLIBS) $L

clean::
	rm -f ${O}
