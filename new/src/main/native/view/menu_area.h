#ifndef __menu_area_h__
#define __menu_area_h__

#include "view/notebook_menu_2d.h"
#include "view/notebook_menu_m.h"
#include "view/notebook_menu_pw.h"
#include "view/notebook_menu_cw.h"
#include "view/notebook_menu_cfm.h"

class MenuArea {
public:
  MenuArea();
  ~MenuArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:
  void initialize_notebook();
  void initialize_other_menu();

private:
  int m_width;
  int m_height;

  GtkFixed* m_fixed;
  GtkBox* m_box_notebook;

  GtkLabel* m_label;
  GtkNotebook* m_notebook;

  NotebookMenu2D* m_menu_2d;
  NotebookMenuM* m_menu_m;
  NotebookMenuPW* m_menu_pw;
  NotebookMenuCW* m_menu_cw;
  NotebookMenuCFM* m_menu_cfm;
};

#endif