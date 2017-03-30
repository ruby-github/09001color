#ifndef __menu_review_h__
#define __menu_review_h__

#include <gtk/gtk.h>
#include <string>

class MenuReview {
public:
  MenuReview();
  ~MenuReview();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
