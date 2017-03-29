#include "view/notebook_menu_2d.h"
#include "view/gtk_global.h"

using namespace std;

NotebookMenu2D::NotebookMenu2D() {
  m_width = 0;
  m_height = 0;
}

NotebookMenu2D::~NotebookMenu2D() {
}

void NotebookMenu2D::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void NotebookMenu2D::initialize(GtkBox* box) {
}