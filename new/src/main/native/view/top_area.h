#ifndef __top_area_h__
#define __top_area_h__

#include <gtk/gtk.h>
#include <string>

class TopArea {
public:
  TopArea();
  ~TopArea();

  void set_size(int width, int height);
  void initialize(GtkBox* box);
  void show();
  void hide();

  void set_patient_info(const std::string name, const std::string sex, const unsigned int age, const std::string id);

  void set_tis(const double tis);
  void set_probe_type(const std::string probe_type);
  void set_check_mode(const std::string check_mode);

  void update_hospital_name(const std::string name);
  void update_info();
  void update_time();

private:
  void initialize_logo(GtkBox* box);
  void initialize_hospital(GtkBox* box);
  void initialize_info(GtkBox* box);
  void initialize_time(GtkBox* box);

private:
  int m_width;
  int m_height;

  std::string m_patient_name;
  std::string m_patient_sex;
  unsigned int m_patient_age;
  std::string m_patient_id;

  double m_tis;
  std::string m_probe_type;
  std::string m_check_mode;

  GtkLabel* m_label_hospital;
  GtkLabel* m_label_info;
  GtkLabel* m_label_time;
};

#endif
