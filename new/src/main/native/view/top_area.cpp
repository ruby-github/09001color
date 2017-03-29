#include "view/top_area.h"
#include "view/gtk_global.h"
#include "config.h"

#include <sstream>
#include <time.h>

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

gboolean time_handler(gpointer data) {
  TopArea* top_area= (TopArea*)data;
  top_area->update_time();

  return TRUE;
}

TopArea::TopArea() {
  m_width = 0;
  m_height = 0;

  m_label_hospital = NULL;
  m_label_info = NULL;
  m_label_time = NULL;
}

TopArea::~TopArea() {
  m_label_hospital = NULL;
  m_label_info = NULL;
  m_label_time = NULL;
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

  update_time();

  g_timeout_add(500, time_handler, this);
}

void TopArea::set_patient_info(const std::string name, const std::string sex, const unsigned int age, const std::string id) {
  m_patient_name = name;
  m_patient_sex = sex;
  m_patient_age = age;
  m_patient_id = id;

  update_info();
}

void TopArea::set_tis(const double tis) {
  m_tis = tis;

  update_info();
}

void TopArea::set_probe_type(const std::string probe_type) {
  m_probe_type = probe_type;

  update_info();
}

void TopArea::set_check_mode(const std::string check_mode) {
  m_check_mode = check_mode;

  update_info();
}

// 更新医院名称
void TopArea::update_hospital_name(const std::string name) {
  if (m_label_hospital != NULL) {
    gtk_label_set_text(m_label_hospital, name.c_str());

    adjust_font_size((GtkWidget*)m_label_hospital, "", "", 20, HOSPITAL_WIDTH, m_height);
  }
}

// 更新病人信息和设备信息
void TopArea::update_info() {
  stringstream ss;

  // 更新病人信息(姓名, 性别, 年龄, ID)

  ss << _("Name:") << " ";
  ss.width(10);
  ss << std::left << m_patient_name;
  ss << " ";

  ss << _("Gender:") << " ";
  ss.width(6);
  ss << std::left << m_patient_sex;
  ss << " ";

  ss << _("Age:") << " ";
  ss.width(4);
  ss << std::left << m_patient_age;
  ss << " ";

  ss << _("ID:") << " ";
  ss << m_patient_id;
  ss << endl;

  // 更新设备信息(声功率, 探头, 检查模式)

  if (m_tis < 0.0001) {
  } else {
    if (m_tis < 0.4) {
      ss.width(16);
      ss << std::left << _("TIS < 0.4");
      ss << " ";
    } else {
      ss << _("TIS") << " ";
      ss.width(12);
      ss << std::left << ((int)(m_tis * 10)) / 10;
      ss << " ";
    }
  }

  if (m_probe_type.empty()) {
    ss.width(16);
    ss << std::left << _("No Probe");
    ss << " ";
  } else {
    ss << _("Probe") << " ";
    ss.width(10);
    ss << std::left << m_probe_type;
    ss << " ";
  }

  ss << _("Mode") << " ";
  ss << m_check_mode;

  gtk_label_set_text(m_label_info, ss.str().c_str());
}

// 更新时间
void TopArea::update_time() {
  if (m_label_time != NULL) {
    time_t t;
    time(&t);

    char buf[255] = {0};

    tm* timeinfo = localtime(&t);
    strftime(buf, sizeof(buf), "%Y-%m-%d\n%H:%M:%S %A", timeinfo);

    string str = string(buf);
    gtk_label_set_text(m_label_time, str.c_str());
  }
}

// ---------------------------------------------------------

// LOGO
void TopArea::initialize_logo(GtkBox* box) {
  GtkImage* image_logo = create_image(IMAGE_LOGO, LOGO_WIDTH, m_height);

  gtk_misc_set_alignment(GTK_MISC(image_logo), 0.5, 0.5);
  gtk_box_pack_start(box, (GtkWidget*)image_logo, TRUE, TRUE, 0);
}

// 医院名称
void TopArea::initialize_hospital(GtkBox* box) {
  m_label_hospital = create_labe("");
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_hospital);

  gtk_misc_set_alignment(GTK_MISC(m_label_hospital), 0.5, 0.5);
}

// 病人信息和设备信息
void TopArea::initialize_info(GtkBox* box) {
  m_label_info = create_labe("");
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_info);
}

// 时间信息
void TopArea::initialize_time(GtkBox* box) {
  m_label_time = create_labe("");
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_time);
}