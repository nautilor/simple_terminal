# simple_terminal

This is a simple terminal build around vte using c

# Dependencies

This terminal depends on VTE wich uses GTK

Install it with 

    sudo pacman -S vte3

# Compile

To compile it adjust `config/config.h` and then simply run

    $ make

# Keybindings

Take a look at config/config.h


# Customization

You can customize colors/font/keybindings/etc... in `config/config.h`

For other things you need to modify the `gtk.css` file in your `~/.config` 

## Adding padding

edit the file `~/.config/gtk-3.0/gtk.css` and add

    vte-terminal {
        padding: 20px 20px 20px 20px;
        -VteTerminal-inner-border: 20px 20px 20px 20px;
    }





## TO FIX
~~With the implementation of terminal switching you can't close the window with `exit` or by simply closing it (it hangs)~~ [TO IMPROVE]

## TODO
Possibility to close a single terminal
