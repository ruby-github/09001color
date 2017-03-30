#ifndef __fixed_menu_measure2d_h__
#define __fixed_menu_measure2d_h__

#include <gtk/gtk.h>
#include <string>

class FixedMenuMeasure2D {
public:
  FixedMenuMeasure2D();
  ~FixedMenuMeasure2D();

  void set_size(int width, int height);
  void initialize(GtkFixed* fixed);

private:

private:
  int m_width;
  int m_height;
};

#endif
