CC=gcc
CFLAGS=-Wall `pkg-config --cflags vte-2.91`
LIBS=`pkg-config --libs vte-2.91`
term: term.c
	${CC} -O2 ${CFLAGS} term.c -o term ${LIBS}
