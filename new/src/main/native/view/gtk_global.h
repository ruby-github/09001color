#ifndef __gtk_global_h__
#define __gtk_global_h__

#include <gtk/gtk.h>
#include <string>

void i18n_initialize();

void global_initialize();
void global_free();

const std::string get_resource_file(const std::string name);

const GdkColor* get_color(const std::string color_name);
const GdkColor* get_bg_color();

GtkLabel* create_labe(const std::string text);

GtkButton* create_button();
GtkButton* create_button_with_label(const std::string label);

GtkImage* create_image_from_file(const std::string filename, const int width, const int height);

#endif