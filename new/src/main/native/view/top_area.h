#ifndef __top_area_h__
#define __top_area_h__

#include <gtk/gtk.h>

class TopArea {
public:
  TopArea();
  ~TopArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);
  void show();
  void hide();

private:
  void initialize_logo(GtkBox* box);
  void initialize_hospital(GtkBox* box);
  void initialize_info(GtkBox* box);
  void initialize_time(GtkBox* box);

private:
  int m_width;
  int m_height;

  GtkLabel* m_hospital;
};

#endif
