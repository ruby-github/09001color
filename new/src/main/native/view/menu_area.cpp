#include "view/menu_area.h"
#include "view/gtk_global.h"

MenuArea::MenuArea() {
  m_width = 0;
  m_height = 0;
}

MenuArea::~MenuArea() {
}

void MenuArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuArea::initialize(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("blue"));

  gtk_container_add(GTK_CONTAINER(box), button);
}

void MenuArea::show() {
}

void MenuArea::hide() {
}
