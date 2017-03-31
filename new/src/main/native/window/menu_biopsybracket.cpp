#include "window/menu_biopsybracket.h"
#include "window/gtk_global.h"

using namespace std;

MenuBiopsyBracket::MenuBiopsyBracket() {
  m_width = 0;
  m_height = 0;
}

MenuBiopsyBracket::~MenuBiopsyBracket() {
}

void MenuBiopsyBracket::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuBiopsyBracket::initialize(GtkBox* box) {
}
