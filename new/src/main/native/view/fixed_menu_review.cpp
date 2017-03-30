#include "view/fixed_menu_review.h"
#include "view/gtk_global.h"

using namespace std;

FixedMenuReview::FixedMenuReview() {
  m_width = 0;
  m_height = 0;
}

FixedMenuReview::~FixedMenuReview() {
}

void FixedMenuReview::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void FixedMenuReview::initialize(GtkFixed* fixed) {
}
