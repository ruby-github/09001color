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

  m_label_hospital = NULL;
}

TopArea::~TopArea() {
  m_label_hospital = NULL;
}

void TopArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void TopArea::initialize(GtkBox* box) {
  GtkBox* box_logo = GTK_BOX(gtk_vbox_new(FALSE, 0));
  GtkBox* box_hospital = GTK_BOX(gtk_vbox_new(FALSE, 0));
  GtkBox* box_info = GTK_BOX(gtk_vbox_new(FALSE, 0));
  GtkBox* box_time = GTK_BOX(gtk_vbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_logo, LOGO_WIDTH, 0);
  gtk_widget_set_size_request((GtkWidget*)box_hospital, HOSPITAL_WIDTH, 0);
  gtk_widget_set_size_request((GtkWidget*)box_time, TIME_WIDTH, 0);

  gtk_box_pack_start(box, (GtkWidget*)box_logo, FALSE, FALSE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_hospital, FALSE, FALSE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_info, TRUE, TRUE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_time, FALSE, FALSE, 0);

  initialize_logo(box_logo);
  initialize_hospital(box_hospital);
  initialize_info(box_info);
  initialize_time(box_time);
}

void TopArea::show() {
}

void TopArea::hide() {
}

// ---------------------------------------------------------

// LOGO
void TopArea::initialize_logo(GtkBox* box) {
  GtkImage* image_logo = create_image_from_file(IMAGE_LOGO_FILENAME, LOGO_WIDTH, m_height);
  gtk_box_pack_start(box, (GtkWidget*)image_logo, TRUE, TRUE, 0);
}

// 医院名称
void TopArea::initialize_hospital(GtkBox* box) {
  m_label_hospital = create_labe("南山医院");

  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_hospital);
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
