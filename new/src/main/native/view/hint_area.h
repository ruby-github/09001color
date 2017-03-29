#ifndef __hint_area_h__
#define __hint_area_h__

#include <gtk/gtk.h>
#include <string>

class HintArea {
public:
  HintArea();
  ~HintArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

  void update_hint(const std::string hint, unsigned int timeout);

private:
  void initialize_hint(GtkBox* box);
  void initialize_status(GtkBox* box);

private:
  int m_width;
  int m_height;

  GtkLabel* m_label_hint;
};

#endif
