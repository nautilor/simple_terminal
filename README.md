# simple_terminal

This is a simple terminal build around vte using c

Compile with

    $ gcc -O2 -Wall $(pkg-config --cflags vte-2.91) term.c -o term $(pkg-config --libs vte-2.91)

## TODO

- ~~keyboard shortcut for copy/paste~~
- ~~Keyboard shortcut for reset~~
- Keyboard shortcut to increment/decrement/reset font scale
- Ideas not found...
