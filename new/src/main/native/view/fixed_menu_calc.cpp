#include "view/fixed_menu_calc.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuCalc::FixedMenuCalc() {
  m_width = 0;
  m_height = 0;
}

FixedMenuCalc::~FixedMenuCalc() {
}

void FixedMenuCalc::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuCalc::initialize(GtkFixed* fixed) {
}
