#ifndef __menu_bodymark_h__
#define __menu_bodymark_h__

#include <gtk/gtk.h>
#include <string>

class MenuBodyMark {
public:
  MenuBodyMark();
  ~MenuBodyMark();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
