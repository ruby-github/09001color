#ifndef __MAINVIEW_H__
#define __MAINVIEW_H__

#include <gtk/gtk.h>

class MainView {
public:
  ~MainView();

  static MainView* get_instance();

  void initialize();

  void show();
  void hide();

private:
  MainView();

  void initialize_view(GtkWidget* widget);
  void initialize_menu(GtkWidget* widget);
  void initialize_status(GtkWidget* widget);

  void initialize_view_left(GtkWidget* widget);
  void initialize_view_info(GtkWidget* widget);
  void initialize_view_right(GtkWidget* widget);

  void initialize_view_patient_info(GtkWidget* widget);

  static MainView* m_instance;

  GdkColor m_fg_color;
  GdkColor m_bg_color;
  GdkColor m_btn_color;

  GtkWidget* m_window;
};

#endif