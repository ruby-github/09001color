#include "view/main_window.h"

#include "config.h"
#include "view/gtk_global.h"

using namespace std;

//       |------------------------------------- 1024 --------------------------------------|
//                                                                             205
// ---   |-----------------------------------------------------------------|---------------|
//  |    |                                                                 |               |
//  | 60 |                              TopArea                            |               |
//  |    |                                                                 |               |
//  |    |-----------------------------------------------------------------|               |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
// 768   |                              ImageArea                          |   MenuArea    |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
//  |    |                                                                 |               |
//  |    |-----------------------------------------------------------------|---------------|
//  |    |                                                                                 |
//  | 105|                              ShortcutMenuArea                                   |
//  |    |                                                                                 |
//  |    |---------------------------------------------------------------------------------|
//  | 35 |                              MessageArea                                        |
// ---   |---------------------------------------------------------------------------------|

#define SCREEN_WIDTH            1024
#define SCREEN_HEIGHT           768

#define MENUAREA_WIDTH          205
#define TOPAREA_HEIGHT          60
#define SHORTCUTMENUAREA_HEIGHT 105
#define MESSAGEAREA_HEIGHT      35

MainWindow* MainWindow::m_instance = NULL;

MainWindow* MainWindow::instance() {
  if (m_instance == NULL) {
    m_instance = new MainWindow();
  }

  return m_instance;
}

MainWindow::MainWindow() {
  m_window = NULL;

  m_top_area = new TopArea();
  m_image_area = new ImageArea();
  m_menu_area = new MenuArea();
  m_shortcut_menu_area = new ShortcutMenuArea();
  m_message_area = new MessageArea();
}

MainWindow::~MainWindow() {
  m_window = NULL;

  if (m_top_area != NULL) {
    delete m_top_area;

    m_top_area = NULL;
  }

  if (m_image_area != NULL) {
    delete m_image_area;

    m_image_area = NULL;
  }

  if (m_menu_area != NULL) {
    delete m_menu_area;

    m_menu_area = NULL;
  }

  if (m_shortcut_menu_area != NULL) {
    delete m_shortcut_menu_area;

    m_shortcut_menu_area = NULL;
  }

  if (m_message_area != NULL) {
    delete m_message_area;

    m_message_area = NULL;
  }
}

void MainWindow::initialize() {
  if (m_window != NULL) {
    return;
  }

  // 初始化主窗口

  m_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  //gtk_window_set_decorated(GTK_WINDOW(m_window), FALSE);
  gtk_window_set_default_size(GTK_WINDOW(m_window), SCREEN_WIDTH, SCREEN_HEIGHT);
  gtk_window_set_position(GTK_WINDOW(m_window), GTK_WIN_POS_CENTER);

  gtk_container_set_border_width(GTK_CONTAINER(m_window), 0);
  gtk_widget_modify_bg(m_window, GTK_STATE_NORMAL, get_bg_color());

  g_signal_connect(GTK_OBJECT(m_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  // 初始化视图

  GtkBox* top_level_box = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_container_add(GTK_CONTAINER(m_window), (GtkWidget*)top_level_box);

  // TopArea + ImageArea + MenuArea
  GtkBox* top_image_area_box = GTK_BOX(gtk_hbox_new(FALSE, 0));
  // ShortcutMenuArea
  GtkBox* shortcut_menu_area_box = GTK_BOX(gtk_hbox_new(FALSE, 0));
  // MessageArea
  GtkBox* message_area_box = GTK_BOX(gtk_hbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)shortcut_menu_area_box, 0, SHORTCUTMENUAREA_HEIGHT);
  gtk_widget_set_size_request((GtkWidget*)message_area_box, 0, MESSAGEAREA_HEIGHT);

  gtk_box_pack_start(top_level_box, (GtkWidget*)top_image_area_box, TRUE, TRUE, 0);
  gtk_box_pack_start(top_level_box, (GtkWidget*)shortcut_menu_area_box, FALSE, FALSE, 0);
  gtk_box_pack_start(top_level_box, (GtkWidget*)message_area_box, FALSE, FALSE, 0);

  initialize_top_image(top_image_area_box);
  initialize_shortcut_menu(shortcut_menu_area_box);
  initialize_message_image(message_area_box);

  show();
}

void MainWindow::show() {
  gtk_widget_show_all(m_window);
}

void MainWindow::hide() {
  gtk_widget_hide_all(m_window);
}

// ---------------------------------------------------------

// TopArea + ImageArea + MenuArea
void MainWindow::initialize_top_image(GtkBox* box) {
  GtkBox* top_left_box = GTK_BOX(gtk_vbox_new(FALSE, 0));
  GtkBox* menu_area_box = GTK_BOX(gtk_vbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)menu_area_box, MENUAREA_WIDTH, 0);

  gtk_box_pack_start(box, (GtkWidget*)top_left_box, TRUE, TRUE, 0);
  gtk_box_pack_start(box, (GtkWidget*)menu_area_box, FALSE, FALSE, 0);

  // -------------------------------------------------------

  GtkBox* top_area_box = GTK_BOX(gtk_hbox_new(FALSE, 0));
  GtkBox* image_area_box = GTK_BOX(gtk_hbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)top_area_box, 0, TOPAREA_HEIGHT);

  gtk_box_pack_start(top_left_box, (GtkWidget*)top_area_box, FALSE, FALSE, 0);
  gtk_box_pack_start(top_left_box, (GtkWidget*)image_area_box, TRUE, TRUE, 0);

  // TopArea
  m_top_area->set_size(SCREEN_WIDTH - MENUAREA_WIDTH, TOPAREA_HEIGHT);
  m_top_area->initialize(top_area_box);

  // ImageArea
  m_image_area->set_size(SCREEN_WIDTH - MENUAREA_WIDTH, SCREEN_HEIGHT - TOPAREA_HEIGHT - SHORTCUTMENUAREA_HEIGHT - MESSAGEAREA_HEIGHT);
  m_image_area->initialize(image_area_box);

  // MenuArea
  m_menu_area->set_size(MENUAREA_WIDTH, SCREEN_HEIGHT - SHORTCUTMENUAREA_HEIGHT - MESSAGEAREA_HEIGHT);
  m_menu_area->initialize(menu_area_box);
}

// ShortcutMenuArea
void MainWindow::initialize_shortcut_menu(GtkBox* box) {
  m_shortcut_menu_area->set_size(SCREEN_WIDTH, SHORTCUTMENUAREA_HEIGHT);
  m_shortcut_menu_area->initialize(box);
}

// MessageArea
void MainWindow::initialize_message_image(GtkBox* box) {
  m_message_area->set_size(SCREEN_WIDTH, MESSAGEAREA_HEIGHT);
  m_message_area->initialize(box);
}
