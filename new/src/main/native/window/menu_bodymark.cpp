#include "window/menu_bodymark.h"
#include "window/gtk_global.h"

using namespace std;

MenuBodyMark::MenuBodyMark() {
  m_width = 0;
  m_height = 0;
}

MenuBodyMark::~MenuBodyMark() {
}

void MenuBodyMark::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuBodyMark::initialize(GtkBox* box) {
}
