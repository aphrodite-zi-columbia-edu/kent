kentSrc = ../../../..
include ../../../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = pslSelfJobs.o

pslSelfJobs: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/pslSelfJobs $O $(MYLIBS) $L

lib:
	cd ../../../lib && ${MAKE}
	cd ../../../../lib && ${MAKE}

clean::
	rm -f ${O}
