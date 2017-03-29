#include "view/main_window.h"
#include "view/gtk_global.h"
#include "config.h"

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
//  | 35 |                                 HintArea                                        |
// ---   |---------------------------------------------------------------------------------|

#define SCREEN_WIDTH            1024
#define SCREEN_HEIGHT           768

#define MENUAREA_WIDTH          205
#define TOPAREA_HEIGHT          60
#define SHORTCUTMENUAREA_HEIGHT 105
#define HINTAREA_HEIGHT         35

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
  m_hint_area = new HintArea();
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

  if (m_hint_area != NULL) {
    delete m_hint_area;

    m_hint_area = NULL;
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

  GtkBox* box_top_level = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_container_add(GTK_CONTAINER(m_window), (GtkWidget*)box_top_level);

  // TopArea + ImageArea + MenuArea
  GtkBox* box_top_image_area = GTK_BOX(gtk_hbox_new(FALSE, 0));
  // ShortcutMenuArea
  GtkBox* box_shortcut_menu_area = GTK_BOX(gtk_hbox_new(FALSE, 0));
  // HintArea
  GtkBox* box_hint_area = GTK_BOX(gtk_hbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_shortcut_menu_area, 0, SHORTCUTMENUAREA_HEIGHT);
  gtk_widget_set_size_request((GtkWidget*)box_hint_area, 0, HINTAREA_HEIGHT);

  gtk_box_pack_start(box_top_level, (GtkWidget*)box_top_image_area, TRUE, TRUE, 0);
  gtk_box_pack_start(box_top_level, (GtkWidget*)box_shortcut_menu_area, FALSE, FALSE, 0);
  gtk_box_pack_start(box_top_level, (GtkWidget*)box_hint_area, FALSE, FALSE, 0);

  initialize_top_image(box_top_image_area);
  initialize_shortcut_menu(box_shortcut_menu_area);
  initialize_hint_image(box_hint_area);

  show();

  test();
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
  GtkBox* box_top_image_area = GTK_BOX(gtk_vbox_new(FALSE, 0));
  GtkBox* box_menu_area = GTK_BOX(gtk_vbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_menu_area, MENUAREA_WIDTH, 0);

  gtk_box_pack_start(box, (GtkWidget*)box_top_image_area, TRUE, TRUE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_menu_area, FALSE, FALSE, 0);

  // -------------------------------------------------------

  GtkBox* box_top_area = GTK_BOX(gtk_hbox_new(FALSE, 0));
  GtkBox* box_image_area = GTK_BOX(gtk_hbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_top_area, 0, TOPAREA_HEIGHT);

  gtk_box_pack_start(box_top_image_area, (GtkWidget*)box_top_area, FALSE, FALSE, 0);
  gtk_box_pack_start(box_top_image_area, (GtkWidget*)box_image_area, TRUE, TRUE, 0);

  // TopArea
  m_top_area->set_size(SCREEN_WIDTH - MENUAREA_WIDTH, TOPAREA_HEIGHT);
  m_top_area->initialize(box_top_area);

  // ImageArea
  m_image_area->set_size(SCREEN_WIDTH - MENUAREA_WIDTH, SCREEN_HEIGHT - TOPAREA_HEIGHT - SHORTCUTMENUAREA_HEIGHT - HINTAREA_HEIGHT);
  m_image_area->initialize(box_image_area);

  // MenuArea
  m_menu_area->set_size(MENUAREA_WIDTH, SCREEN_HEIGHT - SHORTCUTMENUAREA_HEIGHT - HINTAREA_HEIGHT);
  m_menu_area->initialize(box_menu_area);
}

// ShortcutMenuArea
void MainWindow::initialize_shortcut_menu(GtkBox* box) {
  m_shortcut_menu_area->set_size(SCREEN_WIDTH, SHORTCUTMENUAREA_HEIGHT);
  m_shortcut_menu_area->initialize(box);
}

// HintArea
void MainWindow::initialize_hint_image(GtkBox* box) {
  m_hint_area->set_size(SCREEN_WIDTH, HINTAREA_HEIGHT);
  m_hint_area->initialize(box);
}

void MainWindow::test() {
  m_top_area->update_hospital_name("南山医院");
  m_top_area->set_patient_info("jack", "male", 21, "201703270001");

  //m_hint_area->update_flashkey(true);
  //m_hint_area->update_cdrom(true);
}