#ifndef __menu_m_h__
#define __menu_m_h__

#include <gtk/gtk.h>
#include <string>

class MenuM {
public:
  MenuM();
  ~MenuM();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
