kentSrc = ../..

include ../../inc/common.mk

L += -lm $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

A = getallpep

O = $A.o

my: compile
	mv $A${EXE} $(HOME)/bin/i386/$A

mgsc: compile
	mv $A${EXE} /usr/local/apache/cgi-bin-mgsc/$A

alpha: compile
	mv $A${EXE} /usr/local/apache/cgi-bin/$A

beta: compile
	mv $A${EXE} /usr/local/apache/cgi-bin-beta/$A

compile: $O 
	${CC} ${COPT} ${CFLAGS} $O $(MYLIBS) $(L) 
	mv ${AOUT} $A${EXE}
#	${STRIP} $A${EXE}
	chmod a+rx $A${EXE}

lib:
	cd ../../lib && ${MAKE}

tags: 
	ctags *.h *.c ../lib/*.c ../inc/*.h ../../lib/*.c ../../inc/*.h

clean::
	rm -f $A $A.o $A${EXE}
