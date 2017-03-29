#ifndef __notebook_menu_cfm_h__
#define __notebook_menu_cfm_h__

#include <gtk/gtk.h>
#include <string>

class NotebookMenuCFM {
public:
  NotebookMenuCFM();
  ~NotebookMenuCFM();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif