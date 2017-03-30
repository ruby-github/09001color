#include "view/fixed_menu_biopsy.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuBiopsy::FixedMenuBiopsy() {
  m_width = 0;
  m_height = 0;
}

FixedMenuBiopsy::~FixedMenuBiopsy() {
}

void FixedMenuBiopsy::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuBiopsy::initialize(GtkFixed* fixed) {
}
