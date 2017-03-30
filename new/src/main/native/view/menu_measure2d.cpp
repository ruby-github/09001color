#include "view/menu_measure2d.h"
#include "view/gtk_global.h"

using namespace std;

MenuMeasure2D::MenuMeasure2D() {
  m_width = 0;
  m_height = 0;
}

MenuMeasure2D::~MenuMeasure2D() {
}

void MenuMeasure2D::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuMeasure2D::initialize(GtkBox* box) {
}
