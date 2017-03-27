#include "view/shortcut_menu_area.h"

#include "view/gtk_global.h"

ShortcutMenuArea::ShortcutMenuArea() {
  m_width = 0;
  m_height = 0;
}

ShortcutMenuArea::~ShortcutMenuArea() {
}

void ShortcutMenuArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void ShortcutMenuArea::initialize(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("yellow"));

  gtk_container_add(GTK_CONTAINER(box), button);
}

void ShortcutMenuArea::show() {
}

void ShortcutMenuArea::hide() {
}
