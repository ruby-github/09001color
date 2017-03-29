#include "view/notebook_menu_pw.h"
#include "view/gtk_global.h"

using namespace std;

NotebookMenuPW::NotebookMenuPW() {
  m_width = 0;
  m_height = 0;
}

NotebookMenuPW::~NotebookMenuPW() {
}

void NotebookMenuPW::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void NotebookMenuPW::initialize(GtkBox* box) {
}