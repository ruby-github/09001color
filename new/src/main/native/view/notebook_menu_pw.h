#ifndef __notebook_menu_pw_h__
#define __notebook_menu_pw_h__

#include <gtk/gtk.h>
#include <string>

class NotebookMenuPW {
public:
  NotebookMenuPW();
  ~NotebookMenuPW();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif