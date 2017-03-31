#include "window/menu_review.h"
#include "window/gtk_global.h"

using namespace std;

MenuReview::MenuReview() {
  m_width = 0;
  m_height = 0;
}

MenuReview::~MenuReview() {
}

void MenuReview::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuReview::initialize(GtkBox* box) {
}
