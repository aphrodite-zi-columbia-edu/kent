kentSrc = ../../..
include ../../../inc/common.mk


L += $(MYSQLLIBS) -lm -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a


O = g2gSeqOverlap.o 

g2gSeqOverlap: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/g2gSeqOverlap $O $(MYLIBS) $L

lib:
	cd ../../../lib && ${MAKE}

clean::
	rm -f ${O}
