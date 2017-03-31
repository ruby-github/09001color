#include "window/menu_biopsy.h"
#include "window/gtk_global.h"

using namespace std;

MenuBiopsy::MenuBiopsy() {
  m_width = 0;
  m_height = 0;
}

MenuBiopsy::~MenuBiopsy() {
}

void MenuBiopsy::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuBiopsy::initialize(GtkBox* box) {
}
