# simple_terminal

This branch contain an unstable version, don't use it as a daily terminal

Compile with

    $ make

MAKE SURE TO TAKE A LOOK AT `config.h`

## KEYBIND

     Ctrl+Alt+C/V    -> COPY/PASTE
     Ctrl+Alt+P      -> INCREASE FONT
     Ctrl+Alt+O      -> DECREASE FONT
     Ctrl+Alt+I      -> RESET FONT
     Ctrl+Alt+L      -> INCREASE WIDTH
     Ctrl+Alt+J      -> INCREASE HEIGHT
     Ctrl+Alt+H      -> DECREASE WIDTH
     Ctrl+Alt+K      -> DECREASE HEIGHT
     Ctrl+Alt+S      -> STICK/UNSTICK WINDOW
     Ctrl+Alt+A      -> CREATE A NEW TERMINAL
     Ctrl+Alt+N      -> GO TO THE NEXT TERMINAL
     Ctrl+Alt+B      -> GO TO THE PREVIOUS TERMINAL

## TO FIX
With the implementation of terminal switching you can't close the window with `exit` or by simply closing it (it hangs)