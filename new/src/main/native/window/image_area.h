#ifndef __image_area_h__
#define __image_area_h__

#include <gtk/gtk.h>

class ImageArea {
public:
  ImageArea();
  ~ImageArea();

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
