#include "view/menu_pw.h"
#include "view/gtk_global.h"

using namespace std;

MenuPW::MenuPW() {
  m_width = 0;
  m_height = 0;
}

MenuPW::~MenuPW() {
}

void MenuPW::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuPW::initialize(GtkBox* box) {
}
