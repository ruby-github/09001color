#include "window/menu_calc.h"
#include "window/gtk_global.h"

using namespace std;

MenuCalc::MenuCalc() {
  m_width = 0;
  m_height = 0;
}

MenuCalc::~MenuCalc() {
}

void MenuCalc::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuCalc::initialize(GtkBox* box) {
}
