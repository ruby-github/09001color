#ifndef __menu_cw_h__
#define __menu_cw_h__

#include <gtk/gtk.h>
#include <string>

class MenuCW {
public:
  MenuCW();
  ~MenuCW();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif