kentSrc = ../../..
include ../../../inc/common.mk

L += $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = bargeVsMap.o

bargeVsMap: $O 
	${CC} ${COPT} ${CFLAGS} -o ${BINDIR}/bargeVsMap $O $(MYLIBS) $L

clean::
	rm -f ${O}
