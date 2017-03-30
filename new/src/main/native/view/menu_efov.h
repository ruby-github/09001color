#ifndef __menu_efov_h__
#define __menu_efov_h__

#include <gtk/gtk.h>
#include <string>

class MenuEFOV {
public:
  MenuEFOV();
  ~MenuEFOV();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
