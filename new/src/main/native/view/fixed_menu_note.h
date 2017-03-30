#ifndef __fixed_menu_note_h__
#define __fixed_menu_note_h__

#include <gtk/gtk.h>
#include <string>

class FixedMenuNote {
public:
  FixedMenuNote();
  ~FixedMenuNote();

  void set_size(int width, int height);
  void initialize(GtkFixed* fixed);

private:

private:
  int m_width;
  int m_height;
};

#endif
