#include "window/menu_2d.h"
#include "window/gtk_global.h"

using namespace std;

Menu2D::Menu2D() {
  m_width = 0;
  m_height = 0;
}

Menu2D::~Menu2D() {
}

void Menu2D::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void Menu2D::initialize(GtkBox* box) {
}
