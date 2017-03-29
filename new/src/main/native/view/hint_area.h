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

  void update_network(bool on);
  void update_audio(bool on);
  void update_replay(bool on);
  void update_flashkey(bool on);
  void update_cdrom(bool on);
  void update_battery();
  void update_printer(bool on);

  void update_scan();

  int get_scan_count() {
    return m_scan_count;
  }

private:
  void initialize_hint(GtkBox* box);
  void initialize_status(GtkBox* box);

private:
  int m_width;
  int m_height;

  GtkLabel* m_label_hint;

  GtkImage* m_network;
  GtkImage* m_audio;
  GtkImage* m_replay;
  GtkImage* m_flashkey;
  GtkImage* m_cdrom;
  GtkImage* m_battery;
  GtkImage* m_printer;

  unsigned int m_capacity_level;
  int m_scan_count;
};

#endif