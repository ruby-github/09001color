#ifndef __message_area_h__
#define __message_area_h__

#include <gtk/gtk.h>

class MessageArea {
public:
  MessageArea();
  ~MessageArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);

private:

private:
  int m_width;
  int m_height;
};

#endif
