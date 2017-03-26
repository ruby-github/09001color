#include "view/main_window.h"

#include "config.h"
#include "view/gtk_global.h"

#include <iostream>

using namespace std;

//         130           130                         429                          130               205
//     |-------------|-------------|-------------------------------------------|-------------|--------------------|
//     |             |             |30    病人信息(姓名, 性别, 年龄, ID)       |             |                    |
// 60  |    LOGO     |  医院名称   |-------------------------------------------|  时间信息   |                    |
//     |             |             |30        声功率, 探头, 检查模式           |             |                    |
//     |-------------|-------------|-------------------------------------------|-------------|                    |
//     |             |20                                649                                20|                    |
//     |             |  |-----------------------------------------------------------------|  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
// 568 |  图像参数区 |  | 478                          图像区                             |  |      菜单区        |
//     |             |  |                                                                 |  |   已储存图像区     |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |                                                                 |  |                    |
//     |             |  |-----------------------------------------------------------------|  |                    |
//     |             |  20                                                                   |                    |
//     |             |-----|-----------------------------------------------------------------|                    |
//     |          50 |                               电影回放区                              |                    |
//     |             |30      120         120         120         120         120        120 |    30      114     |
//     |-------------|---|-----------|-----------|-----------|-----------|-----------|-----------|---|------------|
//     |             |   |           |           |           |           |           |           |   |            |
// 105 |    保留区   |<< | 快捷菜单1 | 快捷菜单2 | 快捷菜单3 | 快捷菜单4 | 快捷菜单5 | 快捷菜单6 | >>|   保留区   |
//     |             |   |           |           |           |           |           |           |   |            |
//     |-------------|---|-----------|-----------|-----------|-----------|-----------|-----------|---|------------|
// 35  |                                    操作提示信息区                                   |       状态区       |
//     |-------------------------------------------------------------------------------------|--------------------|

#define SCREEN_WIDTH                1024
#define SCREEN_HEIGHT               768

#define IMAGE_PARAM_AREA_WIDTH      130
#define IMAGE_MENU_AREA_WIDTH       205
#define IMAGE_INFO_AREA_WIDTH       (SCREEN_WIDTH - IMAGE_PARAM_AREA_WIDTH - IMAGE_MENU_AREA_WIDTH)

#define LOGO_AREA_HEIGHT            60
#define SHORTCUT_MENU_AREA_HEIGHT   105
#define STATUS_MESSAGE_AREA_HEIGHT  35
#define IMAGE_PARAM_AREA_HEIGHT     (SCREEN_HEIGHT - LOGO_AREA_HEIGHT - SHORTCUT_MENU_AREA_HEIGHT - STATUS_MESSAGE_AREA_HEIGHT)

#define IMAGE_EDGE_HEIGHT           20
#define MOVIE_PLAYBACK_AREA_HEIGHT  50
#define IMAGE_INFO_AREA_HEIGHT      (IMAGE_PARAM_AREA_HEIGHT - MOVIE_PLAYBACK_AREA_HEIGHT - 2 * IMAGE_EDGE_HEIGHT)

#define LOGO_WIDTH                  IMAGE_PARAM_AREA_WIDTH
#define HOSPITAL_WIDTH              130
#define TIME_WIDTH                  130
#define PATIENT_INFO_WIDTH          (IMAGE_INFO_AREA_WIDTH - HOSPITAL_WIDTH - TIME_WIDTH)

#define IMAGE_EDGE_WIDTH            20
#define IMAGE_CANVAS_WIDTH          (IMAGE_INFO_AREA_WIDTH - 2 * IMAGE_EDGE_WIDTH)

#define RESERVED_AREA_WIDTH         IMAGE_PARAM_AREA_WIDTH
#define RESERVED_AREA2_WIDTH        114
#define SHORTCUT_MENU_ARROW_WIDTH   30
#define SHORTCUT_MENU_WIDTH         120

#define MESSAGE_STATUS_WIDTH        IMAGE_MENU_AREA_WIDTH
#define MESSAGE_INFO_WIDTH          (SCREEN_WIDTH - MESSAGE_STATUS_WIDTH)

MainWindow* MainWindow::m_instance = NULL;

MainWindow* MainWindow::instance() {
  if (m_instance == NULL) {
    m_instance = new MainWindow();
  }

  return m_instance;
}

MainWindow::MainWindow() {
  m_window = NULL;
}

MainWindow::~MainWindow() {
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

  g_signal_connect(GTK_OBJECT(m_window), "destroy", G_CALLBACK (gtk_main_quit), NULL);

  // 初始化视图

  GtkWidget* box = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(m_window), box);

  // TOP图像信息区
  GtkWidget* top_info_box = gtk_hbox_new(FALSE, 0);
  // 快捷菜单和保留区
  GtkWidget* shortcut_menu_box = gtk_hbox_new(FALSE, 0);
  // 操作提示信息和状态区
  GtkWidget* status_message_box = gtk_hbox_new(FALSE, 0);

  gtk_widget_set_size_request(shortcut_menu_box, 0, SHORTCUT_MENU_AREA_HEIGHT);
  gtk_widget_set_size_request(status_message_box, 0, STATUS_MESSAGE_AREA_HEIGHT);

  gtk_box_pack_start(GTK_BOX(box), top_info_box, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), shortcut_menu_box, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box), status_message_box, FALSE, FALSE, 0);

  initialize_top_info(top_info_box);
  initialize_shortcut_menu(shortcut_menu_box);
  initialize_status_message(status_message_box);

  show();
}

void MainWindow::show() {
  gtk_widget_show_all(m_window);
}

void MainWindow::hide() {
  gtk_widget_hide_all(m_window);
}

// ---------------------------------------------------------

// TOP图像信息区
void MainWindow::initialize_top_info(GtkWidget* widget) {
  GtkWidget* image_param_box = gtk_vbox_new(FALSE, 0);
  GtkWidget* image_info_box = gtk_vbox_new(FALSE, 0);
  GtkWidget* image_menu_box = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(image_param_box, IMAGE_PARAM_AREA_WIDTH, 0);
  gtk_widget_set_size_request(image_menu_box, IMAGE_MENU_AREA_WIDTH, 0);

  gtk_box_pack_start(GTK_BOX(widget), image_param_box, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(widget), image_info_box, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), image_menu_box, FALSE, FALSE, 0);

  initialize_top_image_param(image_param_box);
  initialize_top_image_info(image_info_box);
  initialize_top_image_menu(image_menu_box);
}

// 快捷菜单和保留区
void MainWindow::initialize_shortcut_menu(GtkWidget* widget) {
}

// 操作提示信息和状态区
void MainWindow::initialize_status_message(GtkWidget* widget) {
}

// LOGO和图像参数区
void MainWindow::initialize_top_image_param(GtkWidget* widget) {
  GtkWidget* logo_box = gtk_vbox_new(FALSE, 0);
  GtkWidget* param_box = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(logo_box, 0, LOGO_AREA_HEIGHT);

  gtk_box_pack_start(GTK_BOX(widget), logo_box, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(widget), param_box, TRUE, TRUE, 0);

  // LOGO

  GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file(get_resource_file(IMAGE_LOGO_FILENAME).c_str(), NULL);
  GdkPixbuf* pixbuf_scale = gdk_pixbuf_scale_simple(pixbuf, LOGO_WIDTH, LOGO_AREA_HEIGHT, GDK_INTERP_BILINEAR);

  GtkWidget* img_logo = gtk_image_new_from_pixbuf(pixbuf_scale);
  g_object_unref(pixbuf_scale);
  g_object_unref(pixbuf);

  gtk_box_pack_start(GTK_BOX(logo_box), img_logo, TRUE, TRUE, 0);

  // 图像参数

  // ***** 病人信息和图像区 *****

  // ***** 菜单和已储存图像区 *****
}

void MainWindow::initialize_top_image_info(GtkWidget* widget) {
}

void MainWindow::initialize_top_image_menu(GtkWidget* widget) {
}
