#ifndef __gtk_global_h__
#define __gtk_global_h__

#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include <string>

void i18n();

const std::string get_resource_file(const std::string name);

const GdkColor* get_color(const std::string color_name);
const GdkColor* get_bg_color();

void set_font(GtkWidget* widget, const std::string family, const std::string sytle, const unsigned int size);

GtkLabel* create_labe(const std::string text);

GtkButton* create_button();
GtkButton* create_button_with_label(const std::string label);

GtkImage* create_image_from_file(const std::string filename, const int width, const int height);

#endif