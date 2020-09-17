#define WIDTH         600
#define HEIGHT        400
#define R_FACTOR        5                 // window resize factor

#define TITLE         "Simple Terminal"
#define FONT          "Fantasque Sans Mono"
#define FONT_SIZE     10
#define FONT_SCALE    1                  // Leave this like this
#define SCALE_FACTOR  0.1                // Leave this like this
#define CURSOR_AH     TRUE               // auto hide the cursor while typing
#define REWRAP        TRUE               // rewrap terminal based on content size
#define BELL          FALSE              // no bell sound
#define MAX_TERM      10

// colors
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

#define MODIFIER GDK_CONTROL_MASK|GDK_MOD1_MASK 

#define COPY                GDK_KEY_c
#define PASTE               GDK_KEY_v
#define INCREASE_FONT       GDK_KEY_p
#define DECREASE_FONT       GDK_KEY_o
#define RESET_FONT          GDK_KEY_i
#define NEW_TERMINAL        GDK_KEY_k
#define NEXT_TERMINAL       GDK_KEY_m
#define PREVIOUS_TERMINAL   GDK_KEY_n
