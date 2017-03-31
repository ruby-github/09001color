#include "window/menu_m.h"
#include "window/gtk_global.h"

using namespace std;

MenuM::MenuM() {
  m_width = 0;
  m_height = 0;
}

MenuM::~MenuM() {
}

void MenuM::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuM::initialize(GtkBox* box) {
}
