#include "window/menu_system.h"
#include "window/gtk_global.h"

using namespace std;

MenuSystem::MenuSystem() {
  m_width = 0;
  m_height = 0;
}

MenuSystem::~MenuSystem() {
}

void MenuSystem::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuSystem::initialize(GtkBox* box) {
}
