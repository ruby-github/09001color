#ifndef __menu_2d_h__
#define __menu_2d_h__

#include <gtk/gtk.h>
#include <string>

class Menu2D {
public:
  Menu2D();
  ~Menu2D();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
