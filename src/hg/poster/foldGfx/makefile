kentSrc = ../../..
include ../../../inc/common.mk


L += $(MYSQLLIBS) -lm -ldl -lm
MYLIBDIR = ../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = foldGfx.o

foldGfx: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o foldGfx $O $(MYLIBS) $L

lib:
	cd ../../lib && ${MAKE}
	cd ../../../lib && ${MAKE}

clean::
	rm -f ${O} foldGfx
