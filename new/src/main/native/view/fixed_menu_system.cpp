#include "view/fixed_menu_system.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuSystem::FixedMenuSystem() {
  m_width = 0;
  m_height = 0;
}

FixedMenuSystem::~FixedMenuSystem() {
}

void FixedMenuSystem::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuSystem::initialize(GtkFixed* fixed) {
}
