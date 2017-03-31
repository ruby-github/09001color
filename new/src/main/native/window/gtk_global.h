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
void adjust_font_size(GtkWidget* widget, const std::string family, const std::string sytle,
  const unsigned int size, const unsigned int max_width, const unsigned int max_height);

void set_image(GtkImage* image, const std::string filename);

GtkLabel* create_label(const std::string text);
GtkButton* create_button(const std::string label);
GtkButton* create_button_with_image(const std::string filename, const int width, const int height);
GtkNotebook* create_notebook();

GtkImage* create_image(const std::string filename, const int width, const int height);

#endif