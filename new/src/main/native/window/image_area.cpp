#include "window/image_area.h"
#include "window/gtk_global.h"

using namespace std;

//         130        20                                                                  20
// |-----------------|-----------------------------------------------------------------------|
// |                 |                                  649                                  |
// |                 |  |-----------------------------------------------------------------|  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |   图像参数区    |  | 478                          图像区                             |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |                                                                 |  |
// |                 |  |-----------------------------------------------------------------|  |
// |              20 |                                                                       |
// |                 |-----------------------------------------------------------------------|
// |              50 |                               电影回放区                              |
// |                 |                                                                       |
// |-----------------|-----------------------------------------------------------------------|

#define IMAGE_PARAM_WIDTH     130
#define MOVIE_PLAYBACK_HEIGHT 50
#define IMAGE_BORDER_SIZE     20

ImageArea::ImageArea() {
  m_width = 0;
  m_height = 0;

  m_label_param = NULL;
}

ImageArea::~ImageArea() {
  m_label_param = NULL;
}

void ImageArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void ImageArea::initialize(GtkBox* box) {
  GtkBox* box_param_area = GTK_BOX(gtk_vbox_new(FALSE, 0));
  GtkBox* box_image_area = GTK_BOX(gtk_vbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_param_area, IMAGE_PARAM_WIDTH, 0);

  gtk_box_pack_start(box, (GtkWidget*)box_param_area, FALSE, FALSE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_image_area, TRUE, TRUE, 0);

  GtkBox* box_image = GTK_BOX(gtk_hbox_new(FALSE, 0));
  GtkBox* box_movie = GTK_BOX(gtk_hbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_movie, 0, MOVIE_PLAYBACK_HEIGHT);

  gtk_box_pack_start(box_image_area, (GtkWidget*)box_image, TRUE, TRUE, 0);
  gtk_box_pack_start(box_image_area, (GtkWidget*)box_movie, FALSE, FALSE, 0);

  initialize_param(box_param_area);
  initialize_image(box_image);
  initialize_movie(box_movie);
}

void ImageArea::update_image_param(const std::string str) {
  if (m_label_param != NULL) {
    gtk_label_set_markup(m_label_param, str.c_str());
  }
}

// ---------------------------------------------------------

void ImageArea::initialize_param(GtkBox* box) {
  m_label_param = create_label("");

  gtk_misc_set_alignment(GTK_MISC(m_label_param), 0.1, 0);
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_param);
}

void ImageArea::initialize_image(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("blue"));

  gtk_container_add(GTK_CONTAINER(box), button);
}

void ImageArea::initialize_movie(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("green"));

  gtk_container_add(GTK_CONTAINER(box), button);
}
