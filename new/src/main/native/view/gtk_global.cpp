#include "view/gtk_global.h"

#include <unistd.h>


#include <sstream>
#include <string>

#include "config.h"

using namespace std;

#define I18N_PACKAGE  "09001_lang"
#define I18N_LOCALE   "/usr/share/locale"

string g_application_path = "";

GdkColor* g_color = NULL;
GdkColor* g_bg_color = NULL;

void i18n() {
  setlocale(LC_ALL, "");
  bindtextdomain(I18N_PACKAGE, I18N_LOCALE);
  bind_textdomain_codeset(I18N_PACKAGE, "UTF-8");
  textdomain(I18N_PACKAGE);
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

void set_font(GtkWidget* widget, const string family, const string sytle, const unsigned int size) {
  stringstream ss;

  if (!family.empty()) {
    ss << family << " ";
  }

  if (!sytle.empty()) {
    ss << sytle << " ";
  }

  if (size > 0) {
    ss << size;
  }

  PangoFontDescription* font = pango_font_description_from_string(ss.str().c_str());
  gtk_widget_modify_font(widget, font);
  pango_font_description_free(font);
}

GtkLabel* create_labe(const std::string text) {
  GtkLabel* label = GTK_LABEL(gtk_label_new(text.c_str()));

  set_font((GtkWidget*)label, "", "", 12);

  gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
  gtk_widget_modify_fg((GtkWidget*)label, GTK_STATE_NORMAL, get_color("white"));

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