#include "view/fixed_menu_bodymark.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuBodyMark::FixedMenuBodyMark() {
  m_width = 0;
  m_height = 0;
}

FixedMenuBodyMark::~FixedMenuBodyMark() {
}

void FixedMenuBodyMark::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuBodyMark::initialize(GtkFixed* fixed) {
}
