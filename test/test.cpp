#include <stdio.h>
#include <iostream>
#include <gtk/gtk.h>

using namespace std;

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_container_set_border_width(GTK_CONTAINER (window), 0);

    gtk_window_set_title(GTK_WINDOW (window), "gtk test");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
