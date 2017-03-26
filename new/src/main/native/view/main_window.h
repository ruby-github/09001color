#ifndef __main_window_h__
#define __main_window_h__

#include <gtk/gtk.h>

class MainWindow {
public:
  static MainWindow* instance();

  ~MainWindow();

  void initialize();
  void show();
  void hide();

private:
  MainWindow();

  void initialize_top_info(GtkWidget* widget);
  void initialize_shortcut_menu(GtkWidget* widget);
  void initialize_status_message(GtkWidget* widget);

  void initialize_top_image_param(GtkWidget* widget);
  void initialize_top_image_info(GtkWidget* widget);
  void initialize_top_image_menu(GtkWidget* widget);

private:
  static MainWindow* m_instance;

  GtkWidget* m_window;
};

#endif
