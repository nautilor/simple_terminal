# simple_terminal

This is a simple terminal build around vte using c

# Dependencies

This terminal depends on VTE wich uses GTK

Install it with 

    sudo pacman -S vte3

# Compile

To compile it adjust `config/config.h` and then simply run

    $ make

## Keybindings

Take a look at config/config.h

## TO FIX
~~With the implementation of terminal switching you can't close the window with `exit` or by simply closing it (it hangs)~~ [TO IMPROVE]

## TODO
Possibility to close a single terminal
