#ifndef __menu_calc_h__
#define __menu_calc_h__

#include <gtk/gtk.h>
#include <string>

class MenuCalc {
public:
  MenuCalc();
  ~MenuCalc();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
