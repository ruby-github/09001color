#include "view/image_area.h"

#include "view/gtk_global.h"

//     20                                                                   20
//    |-----------------------------------------------------------------------|
// 20 |                                  649                                  |
//    |  |-----------------------------------------------------------------|  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  | 478                          图像区                             |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |                                                                 |  |
//    |  |-----------------------------------------------------------------|  |
// 20 |                                                                       |
//    |-----------------------------------------------------------------------|
// 50 |                               电影回放区                              |
//    |                                                                       |
//    |-----------------------------------------------------------------------|

ImageArea::ImageArea() {
  m_width = 0;
  m_height = 0;
}

ImageArea::~ImageArea() {
}

void ImageArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void ImageArea::initialize(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("green"));

  gtk_container_add(GTK_CONTAINER(box), button);
}

void ImageArea::show() {
}

void ImageArea::hide() {
}
