#include "window/menu_note.h"
#include "window/gtk_global.h"

using namespace std;

MenuNote::MenuNote() {
  m_width = 0;
  m_height = 0;
}

MenuNote::~MenuNote() {
}

void MenuNote::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuNote::initialize(GtkBox* box) {
}
