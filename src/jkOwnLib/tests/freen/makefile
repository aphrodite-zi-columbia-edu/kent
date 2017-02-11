kentSrc = ../../..
include ../../../inc/common.mk

L += $(MYSQLLIBS) -lm -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkOwnLib.a $(MYLIBDIR)/jkweb.a

O = freen.o

hello: freen.o
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/freen $O $(MYLIBS) $L

clean::
	rm -f ${O}
