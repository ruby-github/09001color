#ifndef __fixed_menu_system_h__
#define __fixed_menu_system_h__

#include <gtk/gtk.h>
#include <string>

class FixedMenuSystem {
public:
  FixedMenuSystem();
  ~FixedMenuSystem();

  void set_size(int width, int height);
  void initialize(GtkFixed* fixed);

private:

private:
  int m_width;
  int m_height;
};

#endif
