kentSrc = ../..
include ../../inc/common.mk

L += -lm -ldl -lm
MYLIBDIR = ../../lib/${MACHTYPE}
MYLIBS =  ${MYLIBDIR}/jkweb.a

all:
	@for D in ${DIRS} x; do \
	  if test "$$D" != "x" ; then \
	    ( cd $$D && echo $$D && ${MAKE}  ) ;\
	    x=$$? ; if [ $$x -ne 0 ]; then exit $$x ; fi \
	    fi ;\
	done

DIRS = \
    agxToTxg \
    bedToTxEdges \
    txAbFragFind \
    txBedToGraph \
    txOrtho \
    txPslFilter \
    txPslToBed \
    txReadRa \
    txWalk \
    txgAddEvidence \
    txgAnalyze \
    txgGoodEdges \
    txgToAgx \
    txgToXml \
    txgTrim

clean:
	@for D in ${DIRS} x; do \
	  if test "$$D" != "x" ; then \
	    ( cd $$D && echo $$D && ${MAKE} clean ) ;\
	    x=$$? ; if [ $$x -ne 0 ]; then exit $$x ; fi \
	    fi ;\
	done

compile:
	@for D in ${DIRS} x; do \
	  if test "$$D" != "x" ; then \
	    ( cd $$D && echo $$D && ${MAKE} compile ) ;\
	    x=$$? ; if [ $$x -ne 0 ]; then exit $$x ; fi \
	    fi ;\
	done
