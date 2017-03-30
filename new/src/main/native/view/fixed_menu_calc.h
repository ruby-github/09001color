#ifndef __fixed_menu_calc_h__
#define __fixed_menu_calc_h__

#include <gtk/gtk.h>
#include <string>

class FixedMenuCalc {
public:
  FixedMenuCalc();
  ~FixedMenuCalc();

  void set_size(int width, int height);
  void initialize(GtkFixed* fixed);

private:

private:
  int m_width;
  int m_height;
};

#endif
