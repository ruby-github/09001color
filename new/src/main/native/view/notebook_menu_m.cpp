#include "view/notebook_menu_m.h"
#include "view/gtk_global.h"

using namespace std;

NotebookMenuM::NotebookMenuM() {
  m_width = 0;
  m_height = 0;
}

NotebookMenuM::~NotebookMenuM() {
}

void NotebookMenuM::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void NotebookMenuM::initialize(GtkBox* box) {
}