#include <vte/vte.h>
#include "config.h"

static gboolean window_press(GtkWidget *window, GdkEventKey *event);
static gboolean key_press(VteTerminal *terminal, GdkEventKey *event);
static void decrease_font(VteTerminal *terminal);
static void increase_font(VteTerminal *terminal);
static void resize(GtkWidget *window, glong w, glong h);

int main(int argc, char *argv[]) {
    GtkWidget *window, *terminal;
    PangoFontDescription *df;

    // Initialise GTK, window, terminal and font
    gtk_init(&argc, &argv);
    terminal = vte_terminal_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), TITLE);
    df = pango_font_description_new();
    
    // font settings 
    pango_font_description_set_size(df, 10 * PANGO_SCALE);
    pango_font_description_set_weight(df, PANGO_WEIGHT_BOLD);
    pango_font_description_set_family(df, FONT);

    // terminal settings
    vte_terminal_set_rewrap_on_resize(VTE_TERMINAL(terminal), REWRAP);
    vte_terminal_set_mouse_autohide(VTE_TERMINAL(terminal), CURSOR_AH);
    vte_terminal_set_font_scale(VTE_TERMINAL(terminal), FONT_SCALE);
    vte_terminal_set_font(VTE_TERMINAL(terminal), df);
    vte_terminal_set_audible_bell(VTE_TERMINAL(terminal), BELL);
    gtk_widget_set_size_request(window, WIDTH, HEIGHT);
    
    // 16 color support
    vte_terminal_set_colors(VTE_TERMINAL(terminal),
    &CLR_GDK(CLR_7), NULL,
    (const GdkRGBA[]){
        CLR_GDK(CLR_0),
        CLR_GDK(CLR_1),
        CLR_GDK(CLR_2),
        CLR_GDK(CLR_3),
        CLR_GDK(CLR_4),
        CLR_GDK(CLR_5),
        CLR_GDK(CLR_6),
        CLR_GDK(CLR_7),
        CLR_GDK(CLR_8),
        CLR_GDK(CLR_9),
        CLR_GDK(CLR_10),
        CLR_GDK(CLR_11),
        CLR_GDK(CLR_12),
        CLR_GDK(CLR_13),
        CLR_GDK(CLR_14),
        CLR_GDK(CLR_15)}, 16);

    // new shell
    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    g_strfreev(envp);
    vte_terminal_spawn_async(VTE_TERMINAL(terminal),
        VTE_PTY_DEFAULT,
        NULL,
        command,
        NULL,
        0,
        NULL, NULL,
        NULL,
        250, NULL,
        NULL, NULL);

    // exit on close
    g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
    g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);

    // keyboard shortcut support
    g_signal_connect(terminal, "key-press-event", G_CALLBACK(key_press), NULL);
    g_signal_connect(window, "key-press-event", G_CALLBACK(window_press), NULL);

    // put it togheter
    gtk_container_add(GTK_CONTAINER(window), terminal);
    gtk_widget_show_all(window);
    gtk_main();
}

static void resize(GtkWidget *window, glong w, glong h) {
    WIDTH += (WIDTH > 0) ? w : 0;
    HEIGHT += (HEIGHT > 0) ? h : 0;
    gtk_widget_set_size_request(window, WIDTH, HEIGHT);
}

static void increase_font(VteTerminal *terminal) {
    vte_terminal_set_font_scale(VTE_TERMINAL(terminal), vte_terminal_get_font_scale(VTE_TERMINAL(terminal))+SCALE_FACTOR);
}

static void decrease_font(VteTerminal *terminal) {
    vte_terminal_set_font_scale(VTE_TERMINAL(terminal), vte_terminal_get_font_scale(VTE_TERMINAL(terminal))-SCALE_FACTOR);
}

//keyboard input
gboolean key_press(VteTerminal *terminal, GdkEventKey *event) {
    const guint modifiers = event->state & gtk_accelerator_get_default_mod_mask();

    if (modifiers == (GDK_CONTROL_MASK|GDK_MOD1_MASK)) {
        switch (gdk_keyval_to_lower(event->keyval)) {
            case GDK_KEY_c:
                vte_terminal_copy_clipboard_format(VTE_TERMINAL(terminal), VTE_FORMAT_TEXT);
                return TRUE;
            case GDK_KEY_v:
                vte_terminal_paste_clipboard(VTE_TERMINAL(terminal));
                return TRUE;
            case GDK_KEY_p:
                increase_font(VTE_TERMINAL(terminal));
                return TRUE;
            case GDK_KEY_o:
                decrease_font(VTE_TERMINAL(terminal));
                return TRUE;
            case GDK_KEY_i:
                vte_terminal_set_font_scale(VTE_TERMINAL(terminal), FONT_SCALE);
                return TRUE; 
        } 
    }
    return FALSE;
}
static gboolean window_press(GtkWidget *window, GdkEventKey *event) {
    const guint modifiers = event->state & gtk_accelerator_get_default_mod_mask();
     if (modifiers == (GDK_CONTROL_MASK|GDK_MOD1_MASK)) {
        switch (gdk_keyval_to_lower(event->keyval)) {
            case GDK_KEY_h:
                resize(window, -R_FACTOR, 0);
                return TRUE;
            case GDK_KEY_j:
                resize(window, 0, +R_FACTOR);
                return TRUE;
            case GDK_KEY_k:
                resize(window, 0, -R_FACTOR);
                return TRUE;
            case GDK_KEY_l:
                resize(window, +R_FACTOR, 0);
                return TRUE;
        }
     }
 return FALSE;
}


