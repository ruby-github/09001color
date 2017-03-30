#include "view/fixed_menu_efov.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuEFOV::FixedMenuEFOV() {
  m_width = 0;
  m_height = 0;
}

FixedMenuEFOV::~FixedMenuEFOV() {
}

void FixedMenuEFOV::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuEFOV::initialize(GtkFixed* fixed) {
}
