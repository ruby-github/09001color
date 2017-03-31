#include "window/menu_cfm.h"
#include "window/gtk_global.h"

using namespace std;

MenuCFM::MenuCFM() {
  m_width = 0;
  m_height = 0;
}

MenuCFM::~MenuCFM() {
}

void MenuCFM::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuCFM::initialize(GtkBox* box) {
}
