#ifndef __menu_biopsy_h__
#define __menu_biopsy_h__

#include <gtk/gtk.h>
#include <string>

class MenuBiopsy {
public:
  MenuBiopsy();
  ~MenuBiopsy();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
