#ifndef __shortcut_menu_area_h__
#define __shortcut_menu_area_h__

#include <gtk/gtk.h>

#define KNOB_NUM  6

class ShortcutMenuArea {
public:
  ShortcutMenuArea();
  ~ShortcutMenuArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:
  void initialize_knob(GtkBox* box);

private:
  int m_width;
  int m_height;

  GtkButton* m_button_list[KNOB_NUM];

  GtkButton* m_button_left;
  GtkButton* m_button_right;
};

#endif
