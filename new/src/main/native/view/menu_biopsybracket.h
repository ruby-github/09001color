#ifndef __menu_biopsybracket_h__
#define __menu_biopsybracket_h__

#include <gtk/gtk.h>
#include <string>

class MenuBiopsyBracket {
public:
  MenuBiopsyBracket();
  ~MenuBiopsyBracket();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
