#include "window/menu_biopsyverify.h"
#include "window/gtk_global.h"

using namespace std;

MenuBiopsyVerify::MenuBiopsyVerify() {
  m_width = 0;
  m_height = 0;
}

MenuBiopsyVerify::~MenuBiopsyVerify() {
}

void MenuBiopsyVerify::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuBiopsyVerify::initialize(GtkBox* box) {
}
