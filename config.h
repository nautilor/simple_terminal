// if you don't want to screw your colors stay away from this
#define CLR_R(x)   (((x) & 0xff0000) >> 16)
#define CLR_G(x)   (((x) & 0x00ff00) >>  8)
#define CLR_B(x)   (((x) & 0x0000ff) >>  0)
#define CLR_16(x)  ((double)(x) / 0xff)
#define CLR_GDK(x) (const GdkRGBA){ .red = CLR_16(CLR_R(x)), \
                                    .green = CLR_16(CLR_G(x)), \
                                    .blue = CLR_16(CLR_B(x)) }

// this is safe to mess with

int WIDTH    =  600;
int HEIGHT   =  400;
int R_FACTOR =    5;                   // window resize factor

#define TITLE        "Simple Terminal"
#define ALT_TITLE    "center_terminal"
#define FONT         "Monospace"
#define FONT_SCALE   0.75
#define SCALE_FACTOR 0.1
#define CURSOR_AH    TRUE               // auto hide the cursor while typing
#define REWRAP       TRUE               // rewrap terminal based on content size
#define BELL         FALSE              // no bell sound

// colors
#define BACKGROUND    0xC1C1C1
#define CLR_0         0x1C1C1C
#define CLR_1         0xD81860
#define CLR_2         0x60FF60
#define CLR_3         0xF9FD75
#define CLR_4         0x4695C8
#define CLR_5         0xA78EDB
#define CLR_6         0x43AFCE
#define CLR_7         0xF3EBE2
#define CLR_8         0x1C1C1C
#define CLR_9         0xD81860
#define CLR_10        0x60FF60
#define CLR_11        0xF9FD75
#define CLR_12        0x4695C8
#define CLR_13        0xA78EDB
#define CLR_14        0x43AFCE
#define CLR_15        0xF3EBE2
#define PALETTE_SIZE  16


const GdkRGBA PALETTE[] = {
    CLR_GDK(CLR_0), CLR_GDK(CLR_1), CLR_GDK(CLR_2), CLR_GDK(CLR_3), CLR_GDK(CLR_4), CLR_GDK(CLR_5),
    CLR_GDK(CLR_6), CLR_GDK(CLR_7), CLR_GDK(CLR_8), CLR_GDK(CLR_9), CLR_GDK(CLR_10), CLR_GDK(CLR_11),
    CLR_GDK(CLR_12), CLR_GDK(CLR_13), CLR_GDK(CLR_14), CLR_GDK(CLR_15) };

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
