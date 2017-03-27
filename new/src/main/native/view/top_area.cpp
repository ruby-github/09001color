#include "view/top_area.h"

#include "view/gtk_global.h"
#include "config.h"

#include <iostream>

using namespace std;

//       130           130                                                       130
// |-------------|-------------|-------------------------------------------|-------------|
// |             |             |      病人信息(姓名, 性别, 年龄, ID)       |             |
// |    LOGO     |  医院名称   |-------------------------------------------|  时间信息   |
// |             |             |          声功率, 探头, 检查模式           |             |
// |-------------|-------------|-------------------------------------------|-------------|

#define LOGO_WIDTH      130
#define HOSPITAL_WIDTH  130
#define TIME_WIDTH      130

TopArea::TopArea() {
  m_width = 0;
  m_height = 0;

  m_hospital = NULL;
}

TopArea::~TopArea() {
}

void TopArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void TopArea::initialize(GtkBox* box) {
  GtkWidget* logo_box = gtk_vbox_new(FALSE, 3);
  GtkWidget* hospital_box = gtk_vbox_new(FALSE, 3);
  GtkWidget* info_box = gtk_vbox_new(FALSE, 3);
  GtkWidget* time_box = gtk_vbox_new(FALSE, 3);

  gtk_widget_set_size_request(logo_box, LOGO_WIDTH, 0);
  gtk_widget_set_size_request(hospital_box, HOSPITAL_WIDTH, 0);
  gtk_widget_set_size_request(time_box, TIME_WIDTH, 0);

  gtk_box_pack_start(box, logo_box, FALSE, FALSE, 0);
  gtk_box_pack_start(box, hospital_box, FALSE, FALSE, 0);
  gtk_box_pack_start(box, info_box, TRUE, TRUE, 0);
  gtk_box_pack_start(box, time_box, FALSE, FALSE, 0);

  initialize_logo(GTK_BOX(logo_box));
  initialize_hospital(GTK_BOX(hospital_box));
  initialize_info(GTK_BOX(info_box));
  initialize_time(GTK_BOX(time_box));
}

void TopArea::show() {
}

void TopArea::hide() {
}

// ---------------------------------------------------------

// LOGO
void TopArea::initialize_logo(GtkBox* box) {
  GtkImage* img_logo = create_image_from_file(IMAGE_LOGO_FILENAME, LOGO_WIDTH, m_height);
  gtk_box_pack_start(box, (GtkWidget*)img_logo, TRUE, TRUE, 0);
}

// 医院名称
void TopArea::initialize_hospital(GtkBox* box) {
  m_hospital = create_labe("南山医院");

  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_hospital);
}

// 病人信息
void TopArea::initialize_info(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("green"));

  gtk_container_add(GTK_CONTAINER(box), button);
}

// 时间信息
void TopArea::initialize_time(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("yellow"));

  gtk_container_add(GTK_CONTAINER(box), button);
}
