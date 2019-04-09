// if you don't want to screw your colors stay away from this
#define CLR_R(x)   (((x) & 0xff0000) >> 16)
#define CLR_G(x)   (((x) & 0x00ff00) >>  8)
#define CLR_B(x)   (((x) & 0x0000ff) >>  0)
#define CLR_16(x)  ((double)(x) / 0xff)
#define CLR_GDK(x) (const GdkRGBA){ .red = CLR_16(CLR_R(x)), \
                                    .green = CLR_16(CLR_G(x)), \
                                    .blue = CLR_16(CLR_B(x)) }

// this is safe to mess with

glong WIDTH    =  600;
glong HEIGHT   =  400;
glong R_FACTOR =    5;                   // window resize factor

#define TITLE        "Simple Terminal"
#define FONT         "Monospace"
#define FONT_SCALE   0.75
#define SCALE_FACTOR 0.1
#define CURSOR_AH    TRUE               // auto hide the cursor while typing
#define REWRAP       TRUE               // rewrap terminal based on content size
#define BELL         FALSE              // no bell sound

// colors
#define CLR_0       0x1C1C1C
#define CLR_1       0xD81860
#define CLR_2       0x60FF60
#define CLR_3       0xF9FD75
#define CLR_4       0x4695C8
#define CLR_5       0xA78EDB
#define CLR_6       0x43AFCE
#define CLR_7       0xF3EBE2
#define CLR_8       0x1C1C1C
#define CLR_9       0xD81860
#define CLR_10      0x60FF60
#define CLR_11      0xF9FD75
#define CLR_12      0x4695C8
#define CLR_13      0xA78EDB
#define CLR_14      0x43AFCE
#define CLR_15      0xF3EBE2

/* keyboard keybind 
 *
 * REMOVED FOR NOW CAUSE THEY DO NOT WORK PROPERLY
 * 
 * For the moment you can use:
 *      Ctrl+Alt+C/V    -> COPY/PASTE
 *      CtrlAlt+P       -> INCREASE FONT
 *      Ctrl+Alt+O      -> DECREASE FONT
 *      Ctrl+Alt+I      -> RESET FONT
 *      Ctrl+Alt+L      -> INCREASE WIDTH
 *      Ctrl+Alt+J      -> INCREASE HEIGHT
 *      Ctrl+Alt+H      -> DECREASE WIDTH [NOT WORKING]
 *      Ctrl+Alt+K      -> DECREASE HEIGHT [NOT WORKING]
 * */
