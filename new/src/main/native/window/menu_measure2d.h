#ifndef __menu_measure2d_h__
#define __menu_measure2d_h__

#include <gtk/gtk.h>
#include <string>

class MenuMeasure2D {
public:
  MenuMeasure2D();
  ~MenuMeasure2D();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
