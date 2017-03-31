#ifndef __image_area_h__
#define __image_area_h__

#include <gtk/gtk.h>
#include <string>

class ImageArea {
public:
  ImageArea();
  ~ImageArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

  void update_image_param(const std::string str);

private:
  void initialize_param(GtkBox* box);
  void initialize_image(GtkBox* box);
  void initialize_movie(GtkBox* box);

private:
  int m_width;
  int m_height;

  GtkLabel* m_label_param;
};

#endif
