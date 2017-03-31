#ifndef __menu_note_h__
#define __menu_note_h__

#include <gtk/gtk.h>
#include <string>

class MenuNote {
public:
  MenuNote();
  ~MenuNote();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
