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

#endif