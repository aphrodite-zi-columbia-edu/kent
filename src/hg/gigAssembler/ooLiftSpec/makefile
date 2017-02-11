kentSrc = ../../..
include ../../../inc/common.mk


L +=  -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = ooLiftSpec.o

ooLiftSpec: $O ../../../lib/$(MACHTYPE)/jkweb.a 
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/ooLiftSpec $O $(MYLIBS) $L

clean::
	rm -f ${O}
