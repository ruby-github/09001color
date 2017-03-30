#include "view/menu_efov.h"
#include "view/gtk_global.h"

using namespace std;

MenuEFOV::MenuEFOV() {
  m_width = 0;
  m_height = 0;
}

MenuEFOV::~MenuEFOV() {
}

void MenuEFOV::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuEFOV::initialize(GtkBox* box) {
}
