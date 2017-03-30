#include "view/fixed_menu_measure2d.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuMeasure2D::FixedMenuMeasure2D() {
  m_width = 0;
  m_height = 0;
}

FixedMenuMeasure2D::~FixedMenuMeasure2D() {
}

void FixedMenuMeasure2D::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuMeasure2D::initialize(GtkFixed* fixed) {
}
