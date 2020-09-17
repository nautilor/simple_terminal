#include <vte/vte.h>
#include "config/config.h"
#include "util/util.h"

static gboolean window_key_event(GtkWindow *window, GdkEventKey *event);   // keyboard events for the main window
static gboolean term_key_event(VteTerminal *terminal, GdkEventKey *event); // keyboard events for the single terminal
static void decrease_font(VteTerminal *terminal);                          // decrease font for the single terminal
static void increase_font(VteTerminal *terminal);                          // decrease font for the single terminal
static void create_terminal();                                             // create a new terminal widget
static void cycle_terminal(GtkWindow *window, int terminal);               // cycle to previous/next terminal widget
static void quit();                                                        // close the application

int main(int argc, char *argv[]) {

    GtkWindow *window;
    
    // initialise GTK, window
    gtk_init(&argc, &argv);
    window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_title(GTK_WINDOW(window), TITLE);
    gtk_window_set_default_size(GTK_WINDOW(window), W, H);

    // initialize terminal
    create_terminal();
    gtk_container_add(GTK_CONTAINER(window), term[0]);
    
    // exit on close
    g_signal_connect(GTK_WINDOW(window), "destroy", G_CALLBACK(quit), NULL);
   
    // keyboard shortcut support
    g_signal_connect(GTK_WINDOW(window), "key-press-event", G_CALLBACK(window_key_event), NULL);

    // put it together
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
}

static void quit() {
    // It's a brutal solution but it works
    exit(0);
}

static void create_terminal() {
    if (used == MAX_TERM) { return; } // if MAX_TERM it's reached exit the function
    // initialise the terminal
    GtkWidget *terminal;
    terminal = vte_terminal_new();

    // initialise the font
    PangoFontDescription *df;
    df = pango_font_description_new();

    // font settings 
    pango_font_description_set_size(df, FONT_SIZE * PANGO_SCALE);
    pango_font_description_set_weight(df, PANGO_WEIGHT_BOLD);
    pango_font_description_set_family(df, FONT);

    // terminal settings
    vte_terminal_set_rewrap_on_resize(VTE_TERMINAL(terminal), REWRAP);
    vte_terminal_set_mouse_autohide(VTE_TERMINAL(terminal), CURSOR_AH);
    vte_terminal_set_font_scale(VTE_TERMINAL(terminal), FONT_SCALE);
    vte_terminal_set_font(VTE_TERMINAL(terminal), df);
    vte_terminal_set_audible_bell(VTE_TERMINAL(terminal), BELL);

    // 16 color support
    vte_terminal_set_colors(VTE_TERMINAL(terminal), &CLR_GDK(CLR_7), NULL, PALETTE, PALETTE_SIZE);

    // new shell
    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]){ g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    g_strfreev(envp);
    vte_terminal_spawn_async(VTE_TERMINAL(terminal),
        VTE_PTY_DEFAULT, NULL, command, NULL,
        0, NULL, NULL, NULL,
        250, NULL, NULL, NULL);
    
    // events
    g_signal_connect(VTE_TERMINAL(terminal), "child-exited", G_CALLBACK(quit), NULL);
    g_signal_connect(VTE_TERMINAL(terminal), "key-press-event", G_CALLBACK(term_key_event), NULL);
    
    // register the reference to the terminal
    term[used] = g_object_ref(terminal);
    used++;
}

static void cycle_terminal(GtkWindow *window, int terminal) {
    if (terminal < 0 || terminal > MAX_TERM - 1 || term[terminal] == NULL) { terminal = (terminal < current) ? used - 1 : 0; }
    gtk_container_remove(GTK_CONTAINER(window), term[current]);
    gtk_container_add(GTK_CONTAINER(window), term[terminal]);
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_widget_grab_focus(term[terminal]);
    current = terminal;
    gtk_main();
}


static void increase_font(VteTerminal *terminal) {
    vte_terminal_set_font_scale(VTE_TERMINAL(terminal), vte_terminal_get_font_scale(VTE_TERMINAL(terminal))+SCALE_FACTOR);
}

static void decrease_font(VteTerminal *terminal) {
    vte_terminal_set_font_scale(VTE_TERMINAL(terminal), vte_terminal_get_font_scale(VTE_TERMINAL(terminal))-SCALE_FACTOR);
}

gboolean term_key_event(VteTerminal *terminal, GdkEventKey *event) {

    const guint modifiers = event->state & gtk_accelerator_get_default_mod_mask();

    if (modifiers == (MODIFIER)) {
        switch (gdk_keyval_to_lower(event->keyval)) {
            case COPY:          vte_terminal_copy_clipboard_format(terminal, VTE_FORMAT_TEXT); return TRUE;
            case PASTE:         vte_terminal_paste_clipboard(terminal); return TRUE;
            case INCREASE_FONT: increase_font(terminal); return TRUE;
            case DECREASE_FONT: decrease_font(terminal); return TRUE;
            case RESET_FONT:    vte_terminal_set_font_scale(terminal, FONT_SCALE); return TRUE;
            default: return FALSE;
        } 
    }
    return FALSE;
}

static gboolean window_key_event(GtkWindow *window, GdkEventKey *event) {

    const guint modifiers = event->state & gtk_accelerator_get_default_mod_mask();

     if (modifiers == (MODIFIER)) {
        switch (gdk_keyval_to_lower(event->keyval)) {
            case NEW_TERMINAL:      create_terminal(); return TRUE;
            case NEXT_TERMINAL:     cycle_terminal(window, current+1); return TRUE;
            case PREVIOUS_TERMINAL: cycle_terminal(window, current-1); return TRUE;
            default: return FALSE;
       }
     }
    return FALSE;
}
