#ifndef __menu_biopsyverify_h__
#define __menu_biopsyverify_h__

#include <gtk/gtk.h>
#include <string>

class MenuBiopsyVerify {
public:
  MenuBiopsyVerify();
  ~MenuBiopsyVerify();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
