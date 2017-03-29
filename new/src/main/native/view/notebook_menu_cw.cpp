#include "view/notebook_menu_cw.h"
#include "view/gtk_global.h"

using namespace std;

NotebookMenuCW::NotebookMenuCW() {
  m_width = 0;
  m_height = 0;
}

NotebookMenuCW::~NotebookMenuCW() {
}

void NotebookMenuCW::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void NotebookMenuCW::initialize(GtkBox* box) {
}