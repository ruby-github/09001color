#ifndef __fixed_menu_biopsybracket_h__
#define __fixed_menu_biopsybracket_h__

#include <gtk/gtk.h>
#include <string>

class FixedMenuBiopsyBracket {
public:
  FixedMenuBiopsyBracket();
  ~FixedMenuBiopsyBracket();

  void set_size(int width, int height);
  void initialize(GtkFixed* fixed);

private:

private:
  int m_width;
  int m_height;
};

#endif
