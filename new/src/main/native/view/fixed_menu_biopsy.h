#ifndef __fixed_menu_biopsy_h__
#define __fixed_menu_biopsy_h__

#include <gtk/gtk.h>
#include <string>

class FixedMenuBiopsy {
public:
  FixedMenuBiopsy();
  ~FixedMenuBiopsy();

  void set_size(int width, int height);
  void initialize(GtkFixed* fixed);

private:

private:
  int m_width;
  int m_height;
};

#endif
