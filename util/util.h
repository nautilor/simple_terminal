// used to parse colors
#define CLR_R(x)   (((x) & 0xff0000) >> 16)     
#define CLR_G(x)   (((x) & 0x00ff00) >>  8)
#define CLR_B(x)   (((x) & 0x0000ff) >>  0)
#define CLR_16(x)  ((double)(x) / 0xff)
#define CLR_GDK(x) (const GdkRGBA){ .red = CLR_16(CLR_R(x)), \
                                    .green = CLR_16(CLR_G(x)), \
                                    .blue = CLR_16(CLR_B(x)) }


const GdkRGBA PALETTE[] = {                         // palette color converted from config file
    CLR_GDK(CLR_0), CLR_GDK(CLR_1), CLR_GDK(CLR_2),
    CLR_GDK(CLR_3), CLR_GDK(CLR_4), CLR_GDK(CLR_5),
    CLR_GDK(CLR_6), CLR_GDK(CLR_7), CLR_GDK(CLR_8),
    CLR_GDK(CLR_9), CLR_GDK(CLR_10), CLR_GDK(CLR_11),
    CLR_GDK(CLR_12), CLR_GDK(CLR_13), CLR_GDK(CLR_14), CLR_GDK(CLR_15) };

GtkWidget * term[MAX_TERM];

gboolean sticked = FALSE;                           // used to indicate if window should persist on all workspace
int current = 0;                                    // indicates the current terminal
int used = 0;                                       // indicates how many terminals are open
int W = WIDTH;                                      // WIDTH for the window
int H = HEIGHT;                                     // HEIGHT for the window
int R = R_FACTOR;                                   // resize factor for the window
