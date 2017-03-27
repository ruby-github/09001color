#ifndef __main_window_h__
#define __main_window_h__

#include <gtk/gtk.h>

#include "view/top_area.h"
#include "view/image_area.h"
#include "view/menu_area.h"
#include "view/shortcut_menu_area.h"
#include "view/message_area.h"

class MainWindow {
public:
  static MainWindow* instance();

  ~MainWindow();

  void initialize();
  void show();
  void hide();

private:
  MainWindow();

  void initialize_top_image(GtkBox* box);
  void initialize_shortcut_menu(GtkBox* box);
  void initialize_message_image(GtkBox* box);

private:
  static MainWindow* m_instance;

  GtkWidget* m_window;

  TopArea* m_top_area;
  ImageArea* m_image_area;
  MenuArea* m_menu_area;

  ShortcutMenuArea* m_shortcut_menu_area;
  MessageArea* m_message_area;
};

#endif
