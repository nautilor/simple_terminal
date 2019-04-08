# simple_terminal

Compile with

    $ gcc -O2 -Wall $(pkg-config --cflags vte-2.91) term.c -o term $(pkg-config --libs vte-2.91)
