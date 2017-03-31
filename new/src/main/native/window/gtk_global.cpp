#include "window/gtk_global.h"
#include "config.h"

#include <unistd.h>
#include <sstream>
#include <string>

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
  PangoFontDescription* font = NULL;

  if (sytle.empty()) {
    font = pango_font_description_new();
  } else {
    font = pango_font_description_from_string(sytle.c_str());
  }

  if (!family.empty()) {
    pango_font_description_set_family(font, family.c_str());
  } else {
    pango_font_description_set_family(font, "WenQuanYi Zen Hei");
  }

  if (size > 0) {
    pango_font_description_set_size(font, size * PANGO_SCALE);
  } else {
    pango_font_description_set_size(font, 12 * PANGO_SCALE);
  }

  gtk_widget_modify_font(widget, font);
  pango_font_description_free(font);
}

void adjust_font_size(GtkWidget* widget, const string family, const string sytle,
  const unsigned int size, const unsigned int max_width, const unsigned int max_height) {
  if (size > 0) {
    if (max_width > 0 && max_height > 0) {
      string text;

      if (GTK_IS_LABEL(widget) == TRUE) {
        text = gtk_label_get_text(GTK_LABEL(widget));
      } else if (GTK_IS_BUTTON(widget) == TRUE) {
        text = gtk_button_get_label(GTK_BUTTON(widget));
      } else {
      }

      if (!text.empty()) {
        PangoFontDescription* font = NULL;

        if (sytle.empty()) {
          font = pango_font_description_new();
        } else {
          font = pango_font_description_from_string(sytle.c_str());
        }

        if (!family.empty()) {
          pango_font_description_set_family(font, family.c_str());
        } else {
          pango_font_description_set_family(font, "WenQuanYi Zen Hei");
        }

        int width = 0;
        int height = 0;
        int font_size = size;

        PangoLayout* layout = gtk_widget_create_pango_layout(widget, text.c_str());

        do {
          pango_font_description_set_size(font, font_size * PANGO_SCALE);

          pango_layout_set_font_description(layout, font);
          pango_layout_get_pixel_size(layout, &width, &height);

          font_size -= 1;

          if (font_size <= 0) {
            break;
          }
        } while (width > max_width || height > max_height);

        g_object_unref(layout);

        if (font_size > 0) {
          gtk_widget_modify_font(widget, font);
        }

        pango_font_description_free(font);
      }
    }
  }
}

void set_image(GtkImage* image, const string filename) {
  if (filename.empty()) {
    gtk_image_set_from_pixbuf(image, NULL);
  } else {
    gtk_image_set_from_file(image, get_resource_file(filename).c_str());
  }
}

GtkLabel* create_label(const string str) {
  GtkLabel* label = GTK_LABEL(gtk_label_new(str.c_str()));

  set_font((GtkWidget*)label, "", "", 12);

  gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
  gtk_widget_modify_fg((GtkWidget*)label, GTK_STATE_NORMAL, get_color("white"));

  return label;
}

GtkButton* create_button(const string label) {
  GtkButton* button = NULL;

  if (label.empty()) {
    button = GTK_BUTTON(gtk_button_new());
  } else {
    button = GTK_BUTTON(gtk_button_new_with_label(label.c_str()));

    gtk_button_set_alignment(button, 1, 0.5);
    gtk_widget_modify_fg((GtkWidget*)button, GTK_STATE_NORMAL, get_color("white"));
  }

  return button;
}

GtkButton* create_button_with_image(const string filename, const int width, const int height) {
  GtkButton* button = GTK_BUTTON(gtk_button_new());

  if (!filename.empty()) {
    gtk_button_set_image(button, (GtkWidget*)create_image(filename, width, height));
    gtk_button_set_image_position(button, GTK_POS_LEFT);
  }

  return button;
}

GtkNotebook* create_notebook() {
  GtkNotebook* notebook = GTK_NOTEBOOK(gtk_notebook_new());

  gtk_notebook_set_scrollable(notebook, TRUE);
  gtk_container_set_border_width (GTK_CONTAINER(notebook), 0);

  return notebook;
}

GtkImage* create_image(const string filename, const int width, const int height) {
  GtkImage* image = NULL;

  if (filename.empty()) {
    image = GTK_IMAGE(gtk_image_new());
  } else {
    if (width == 0 || height == 0) {
      image = GTK_IMAGE(gtk_image_new_from_file(get_resource_file(filename).c_str()));
    } else {
      GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file(get_resource_file(filename).c_str(), NULL);
      GdkPixbuf* pixbuf_scale = gdk_pixbuf_scale_simple(pixbuf, width, height, GDK_INTERP_BILINEAR);

      image = GTK_IMAGE(gtk_image_new_from_pixbuf(pixbuf_scale));
      g_object_unref(pixbuf_scale);
      g_object_unref(pixbuf);
    }
  }

  return image;
}