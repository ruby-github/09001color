#include "window/menu_cw.h"
#include "window/gtk_global.h"

using namespace std;

MenuCW::MenuCW() {
  m_width = 0;
  m_height = 0;
}

MenuCW::~MenuCW() {
}

void MenuCW::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuCW::initialize(GtkBox* box) {
}
