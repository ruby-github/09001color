#include "view/notebook_menu_cfm.h"
#include "view/gtk_global.h"

using namespace std;

NotebookMenuCFM::NotebookMenuCFM() {
  m_width = 0;
  m_height = 0;
}

NotebookMenuCFM::~NotebookMenuCFM() {
}

void NotebookMenuCFM::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void NotebookMenuCFM::initialize(GtkBox* box) {
}