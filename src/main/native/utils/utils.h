#ifndef __UTILS_H__
#define __UTILS_H__

#include <gtk/gtk.h>
#include <iostream>

void i18n_initialize();
const GdkColor* get_bg_color();
const std::string get_resource_file(const std::string name);

#endif