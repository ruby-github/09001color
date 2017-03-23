#include <stdio.h>
#include <iostream>
#include <gtk/gtk.h>

using namespace std;

void hello( GtkWidget *widget, gpointer   data ) {
    const gchar *s = gtk_widget_get_name(widget);
    g_print ("ok");
}

void signal_connect(GtkWidget* widget) {
   g_signal_connect (G_OBJECT (widget), "clicked", G_CALLBACK (hello), NULL);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_container_set_border_width (GTK_CONTAINER (window), 0);

    gtk_window_set_title (GTK_WINDOW (window), "gtk test");
    gtk_window_set_default_size(GTK_WINDOW(window),800,600);

    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);

    gint width = 0;
    gint height = 0;

    gtk_window_get_size(GTK_WINDOW (window), &width, &height);

    cout << width << ", " << height << endl;

    GtkWidget* fixed = gtk_fixed_new ();
    gtk_container_add (GTK_CONTAINER (window), fixed);

    GtkWidget* box_1 = gtk_hbox_new(FALSE, 0);
    gtk_widget_set_size_request(box_1, width, height - 100);
    gtk_fixed_put(GTK_FIXED (fixed), box_1, 0, 0);

    GtkWidget* box_2 = gtk_hbox_new(FALSE, 0);
    gtk_widget_set_size_request(box_2, width, 50);
    gtk_fixed_put(GTK_FIXED (fixed), box_2, 0, 500);

    GtkWidget* box_3 = gtk_hbox_new(FALSE, 0);
    gtk_widget_set_size_request(box_3, width, 50);
    gtk_fixed_put(GTK_FIXED (fixed), box_3, 0, 550);


    GtkWidget* button1 = gtk_button_new_with_label("button1");
    gtk_box_pack_start(GTK_BOX(box_1), button1, TRUE, TRUE, 0);

    GtkWidget* button2 = gtk_button_new_with_label("快捷菜单区");
    gtk_box_pack_start(GTK_BOX(box_2), button2, TRUE, TRUE, 0);

    GtkWidget* button3 = gtk_button_new_with_label("帮助信息区");
    gtk_box_pack_start(GTK_BOX(box_3), button3, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
