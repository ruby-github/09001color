#include "view/fixed_menu_biopsyverify.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuBiopsyVerify::FixedMenuBiopsyVerify() {
  m_width = 0;
  m_height = 0;
}

FixedMenuBiopsyVerify::~FixedMenuBiopsyVerify() {
}

void FixedMenuBiopsyVerify::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuBiopsyVerify::initialize(GtkFixed* fixed) {
}
