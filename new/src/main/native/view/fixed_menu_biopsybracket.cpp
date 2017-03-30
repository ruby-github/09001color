#include "view/fixed_menu_biopsybracket.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuBiopsyBracket::FixedMenuBiopsyBracket() {
  m_width = 0;
  m_height = 0;
}

FixedMenuBiopsyBracket::~FixedMenuBiopsyBracket() {
}

void FixedMenuBiopsyBracket::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuBiopsyBracket::initialize(GtkFixed* fixed) {
}
