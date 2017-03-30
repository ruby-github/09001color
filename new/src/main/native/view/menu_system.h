#ifndef __menu_system_h__
#define __menu_system_h__

#include <gtk/gtk.h>
#include <string>

class MenuSystem {
public:
  MenuSystem();
  ~MenuSystem();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
