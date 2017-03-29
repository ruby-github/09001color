#ifndef __notebook_menu_2d_h__
#define __notebook_menu_2d_h__

#include <gtk/gtk.h>
#include <string>

class NotebookMenu2D {
public:
  NotebookMenu2D();
  ~NotebookMenu2D();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif