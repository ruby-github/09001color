#ifndef __menu_area_h__
#define __menu_area_h__

#include <gtk/gtk.h>

class MenuArea {
public:
  MenuArea();
  ~MenuArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);
  void show();
  void hide();

private:

private:
  int m_width;
  int m_height;
};

#endif
