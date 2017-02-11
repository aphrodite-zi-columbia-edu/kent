kentSrc = ../../../../..
include ../../../../../inc/common.mk

L += -lm $(MYSQLLIBS) -ldl -lm
MYLIBDIR = ..//../../../../lib/$(MACHTYPE)
MYLIBS =  $(MYLIBDIR)/jkhgap.a $(MYLIBDIR)/jkweb.a

O = doOmimAv.o

all: doOmimAv

doOmimAv: $O $(MYLIBS)
	${CC} ${COPT} ${CFLAGS} -o doOmimAv $O $(MYLIBS) $L

clean::
	rm -f ${O}

install: check-prefix all
	cp doOmimAv ${PREFIX}

check-prefix:
	@test -n "${PREFIX}" || (echo "must specify PREFIX= to install"; exit 1)
