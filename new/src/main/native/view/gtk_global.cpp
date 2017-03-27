#include "view/gtk_global.h"

#include <unistd.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include "config.h"

using namespace std;

string g_application_path = "";

GdkColor* g_color = NULL;
GdkColor* g_bg_color = NULL;

void i18n_initialize() {
  setlocale(LC_ALL, "");
  bindtextdomain(PACKAGE_NAME, LOCALE_PATH);
  bind_textdomain_codeset(PACKAGE_NAME, "UTF-8");
  textdomain(PACKAGE_NAME);
}

void global_initialize() {
}

void global_free() {
}

const string get_resource_file(const string name) {
  if (g_application_path.empty()) {
    const int MAX_PATH = 1024;
    char buf[MAX_PATH] = {0};

    int count = readlink("/proc/self/exe", buf, MAX_PATH);

    if (count > 0 && count < MAX_PATH) {
      buf[count] = '\0';

      string filename = string(buf);
      size_t pos = filename.find_last_of('/');

      if (pos != string::npos) {
        g_application_path = filename.substr(0, pos);
      }
    } else {
      g_application_path = ".";
    }
  }

  return g_application_path + "/" + name;
}

const GdkColor* get_color(const string color_name) {
  if (g_color == NULL) {
    g_color = new GdkColor();
  }

  gdk_color_parse(color_name.c_str(), g_color);

  return g_color;
}

const GdkColor* get_bg_color() {
  if (g_bg_color == NULL) {
    g_bg_color = new GdkColor();

    gdk_color_parse("black", g_bg_color);
  }

  return g_bg_color;
}

GtkLabel* create_labe(const std::string text) {
  GtkLabel* label = GTK_LABEL(gtk_label_new(text.c_str()));

  gtk_label_set_line_wrap(label, TRUE);
  //gtk_widget_modify_font(label, font);
  //PangoFontDescription *font

  return label;
}

GtkButton* create_button() {
  GtkWidget* button = gtk_button_new();

  return GTK_BUTTON(button);
}

GtkButton* create_button_with_label(const std::string label) {
  GtkWidget* button = gtk_button_new_with_label(label.c_str());

  return GTK_BUTTON(button);
}

GtkImage* create_image_from_file(const std::string filename, const int width, const int height) {
  GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file(get_resource_file(filename).c_str(), NULL);
  GdkPixbuf* pixbuf_scale = gdk_pixbuf_scale_simple(pixbuf, width, height, GDK_INTERP_BILINEAR);

  GtkWidget* image = gtk_image_new_from_pixbuf(pixbuf_scale);
  g_object_unref(pixbuf_scale);
  g_object_unref(pixbuf);

  return GTK_IMAGE(image);
}