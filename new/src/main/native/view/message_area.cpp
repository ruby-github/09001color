#include "view/message_area.h"

#include "view/gtk_global.h"

//                        819                          205
// |---------------------------------------------|------------|
// |                 操作提示信息区              |   状态区   |
// |---------------------------------------------|------------|

MessageArea::MessageArea() {
  m_width = 0;
  m_height = 0;
}

MessageArea::~MessageArea() {
}

void MessageArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MessageArea::initialize(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("grey"));

  gtk_container_add(GTK_CONTAINER(box), button);
}

void MessageArea::show() {
}

void MessageArea::hide() {
}
