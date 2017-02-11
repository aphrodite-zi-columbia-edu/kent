kentSrc = ../../../..
include ../../../../inc/common.mk

L += $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = checkEnds.o

checkEnds: $O 
	${CC} ${COPT} ${CFLAGS} -o checkEnds $O $(MYLIBS) $L

clean::
	rm -f ${O}
