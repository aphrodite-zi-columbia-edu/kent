kentSrc = ../../../..
include ../../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = ooMapMend.o

ooMapMend: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/ooMapMend $O $(MYLIBS) $L

clean::
	rm -f ${O}
