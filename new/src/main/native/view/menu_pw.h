#ifndef __menu_pw_h__
#define __menu_pw_h__

#include <gtk/gtk.h>
#include <string>

class MenuPW {
public:
  MenuPW();
  ~MenuPW();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
