#ifndef __shortcut_menu_area_h__
#define __shortcut_menu_area_h__

#include <gtk/gtk.h>

class ShortcutMenuArea {
public:
  ShortcutMenuArea();
  ~ShortcutMenuArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);
  void show();
  void hide();

private:

private:
  int m_width;
  int m_height;
};

#endif
