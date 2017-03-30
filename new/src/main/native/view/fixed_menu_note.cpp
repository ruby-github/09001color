#include "view/fixed_menu_note.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuNote::FixedMenuNote() {
  m_width = 0;
  m_height = 0;
}

FixedMenuNote::~FixedMenuNote() {
}

void FixedMenuNote::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuNote::initialize(GtkFixed* fixed) {
}
