#include "config.h"
#include "view/mainview.h"

MainView* MainView::m_instance = NULL;

MainView* MainView::get_instance() {
  if (m_instance == NULL) {
    m_instance = new MainView();
  }

  return m_instance;
}

MainView::MainView() {
  m_window = NULL;

  gdk_color_parse(GDKCOLOR_FOREGROUND, &m_fg_color);
  gdk_color_parse(GDKCOLOR_BACKGROUND, &m_bg_color);
  gdk_color_parse(GDKCOLOR_BUTTON, &m_btn_color);
}

MainView::~MainView() {
  if (m_instance != NULL) {
    delete m_instance;

    m_instance = NULL;
  }
}

void MainView::initialize() {
  // 初始化主窗口
  m_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_decorated(GTK_WINDOW(m_window), FALSE);
  gtk_window_set_default_size(GTK_WINDOW(m_window), SCREEN_WIDTH, SCREEN_HEIGHT);
  gtk_window_set_position(GTK_WINDOW(m_window), GTK_WIN_POS_CENTER);

  gtk_container_set_border_width(GTK_CONTAINER(m_window), 0);
  gtk_widget_modify_bg(m_window, GTK_STATE_NORMAL, &m_bg_color);

  g_signal_connect(GTK_OBJECT(m_window), "destroy", G_CALLBACK (gtk_main_quit), NULL);

  // 初始化视图

  GtkWidget* box = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(m_window), box);

  GtkWidget* box_view = gtk_hbox_new(FALSE, 0);
  GtkWidget* box_menu= gtk_hbox_new(FALSE, 0);
  GtkWidget* box_status = gtk_hbox_new(FALSE, 0);

  gtk_widget_set_size_request(box_menu, 0, MAINVIEW_MENU_HEIGHT);
  gtk_widget_set_size_request(box_status, 0, MAINVIEW_STATUS_HEIGHT);

  gtk_box_pack_start(GTK_BOX(box), box_view, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), box_menu, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box), box_status, FALSE, FALSE, 0);

  initialize_view(box_view);
  initialize_menu(box_menu);
  initialize_status(box_status);
}

void MainView::show() {
  gtk_widget_show_all(m_window);
}

void MainView::hide() {
  gtk_widget_hide_all(m_window);
}

// 初始化主视图区
void MainView::initialize_view(GtkWidget* widget) {
  GtkWidget* box_left = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_info = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_right = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(box_left, MAINVIEW_LEFT_WIDTH, 0);
  gtk_widget_set_size_request(box_right, MAINVIEW_RIGHT_WIDTH, 0);

  gtk_box_pack_start(GTK_BOX(widget), box_left, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_info, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_right, FALSE, FALSE, 0);

  initialize_view_left(box_left);
  initialize_view_info(box_info);
  initialize_view_right(box_right);
}

// 初始化快捷菜单区
void MainView::initialize_menu(GtkWidget* widget) {
  GtkWidget* label1 = gtk_label_new("快捷菜单1");
  GtkWidget* label2 = gtk_label_new("快捷菜单2");
  GtkWidget* label3 = gtk_label_new("快捷菜单3");
  GtkWidget* label4 = gtk_label_new("快捷菜单4");
  GtkWidget* label5 = gtk_label_new("快捷菜单5");
  GtkWidget* label6 = gtk_label_new("快捷菜单6");

  gtk_box_pack_start(GTK_BOX(widget), label1, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), label2, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), label3, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), label4, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), label5, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), label6, TRUE, TRUE, 0);
}

// 初始化状态信息区
void MainView::initialize_status(GtkWidget* widget) {
  GtkWidget* box_help = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_system = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(box_system, MAINVIEW_RIGHT_WIDTH, 0);

  gtk_box_pack_start(GTK_BOX(widget), box_help, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_system, FALSE, FALSE, 0);

  // -----------------------------------------------------

  GtkWidget* label_help = gtk_label_new("帮助信息区");
  GtkWidget* label_system = gtk_label_new("系统状态区");

  gtk_container_add(GTK_CONTAINER(box_help), label_help);
  gtk_container_add(GTK_CONTAINER(box_system), label_system);
}

// 初始化主视图左侧参数区
void MainView::initialize_view_left(GtkWidget* widget) {
  GtkWidget* box_logo = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_param = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_custom = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(box_logo, 0, MAINVIEW_LOGO_HEIGHT);
  gtk_widget_set_size_request(box_custom, 0, MAINVIEW_CUSTOM_HEIGHT);

  gtk_box_pack_start(GTK_BOX(widget), box_logo, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_param, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_custom, FALSE, FALSE, 0);

  // -----------------------------------------------------

  GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file(std::string(g_application_path + "/" + IMG_LOGO_FILE).c_str(), NULL);
  GdkPixbuf* scale = gdk_pixbuf_scale_simple(pixbuf, 180, 57, GDK_INTERP_BILINEAR);

  GtkWidget* img_logo = gtk_image_new_from_pixbuf(scale);
  g_object_unref(pixbuf);
  g_object_unref(scale);

  //GtkWidget* button_logo = gtk_button_new_with_label("LOGO");
  GtkWidget* button_param = gtk_button_new_with_label("图像参数区");
  GtkWidget* button_custom = gtk_button_new_with_label("自定义按键功能指示区");

  GdkColor color;
  gdk_color_parse(GDKCOLOR_BUTTON, &color);
  gtk_widget_modify_bg(box_logo, GTK_STATE_NORMAL, &color);

  gtk_container_add(GTK_CONTAINER(box_logo), img_logo);
  //gtk_container_add(GTK_CONTAINER(box_logo), button_logo);
  gtk_container_add(GTK_CONTAINER(box_param), button_param);
  gtk_container_add(GTK_CONTAINER(box_custom), button_custom);

  //gtk_widget_modify_bg(button_logo, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_param, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_custom, GTK_STATE_NORMAL, &m_bg_color);
}

// 初始化主视图中间信息区
void MainView::initialize_view_info(GtkWidget* widget) {
  GtkWidget* box_patient_info = gtk_hbox_new(FALSE, 0);
  GtkWidget* box_image = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_playback = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_cursor = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(box_patient_info, 0, MAINVIEW_LOGO_HEIGHT);
  gtk_widget_set_size_request(box_playback, 0, MAINVIEW_PLAYBACK_HEIGHT);
  gtk_widget_set_size_request(box_cursor, 0, MAINVIEW_CURSOR_HEIGHT);

  gtk_box_pack_start(GTK_BOX(widget), box_patient_info, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_image, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_playback, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_cursor, FALSE, FALSE, 0);

  // -----------------------------------------------------

  GtkWidget* button_image = gtk_button_new_with_label("图像区");
  GtkWidget* button_playback = gtk_button_new_with_label("电影回放区");
  GtkWidget* button_cursor = gtk_button_new_with_label("光标资源区");

  gtk_container_add(GTK_CONTAINER(box_image), button_image);
  gtk_container_add(GTK_CONTAINER(box_playback), button_playback);
  gtk_container_add(GTK_CONTAINER(box_cursor), button_cursor);

  gtk_widget_modify_bg(button_image, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_playback, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_cursor, GTK_STATE_NORMAL, &m_bg_color);

  initialize_view_patient_info(box_patient_info);
}

// 初始化主视图右侧存储图像区
void MainView::initialize_view_right(GtkWidget* widget) {
  GtkWidget* box_store = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_thumb = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(box_thumb, 0, MAINVIEW_CURSOR_HEIGHT);

  gtk_box_pack_start(GTK_BOX(widget), box_store, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_thumb, FALSE, FALSE, 0);

  // -----------------------------------------------------

  GtkWidget* button_store = gtk_button_new_with_label("已存储图像区菜单区");
  GtkWidget* button_thumb = gtk_button_new_with_label("缩略图功能区");

  gtk_container_add(GTK_CONTAINER(box_store), button_store);
  gtk_container_add(GTK_CONTAINER(box_thumb), button_thumb);

  gtk_widget_modify_bg(button_store, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_thumb, GTK_STATE_NORMAL, &m_bg_color);
}

// 初始化病人信息区
void MainView::initialize_view_patient_info(GtkWidget* widget) {
  GtkWidget* box_info = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_time = gtk_vbox_new(FALSE, 0);

  gtk_widget_set_size_request(box_time, MAINVIEW_TIME_WIDTH, 0);

  gtk_box_pack_start(GTK_BOX(widget), box_info, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(widget), box_time, FALSE, FALSE, 0);

  GtkWidget* box_patient_info = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_hospital_info = gtk_hbox_new(TRUE, 0);

  gtk_widget_set_size_request(box_patient_info, 0, MAINVIEW_PATIENT_HEIGHT);

  gtk_box_pack_start(GTK_BOX(box_info), box_patient_info, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box_info), box_hospital_info, TRUE, TRUE, 0);

  GtkWidget* box_hospital = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_sound = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_output = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_probe = gtk_vbox_new(FALSE, 0);
  GtkWidget* box_mode = gtk_vbox_new(FALSE, 0);

  gtk_box_pack_start(GTK_BOX(box_hospital_info), box_hospital, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box_hospital_info), box_sound, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box_hospital_info), box_output, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box_hospital_info), box_probe, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box_hospital_info), box_mode, TRUE, TRUE, 0);

  // -----------------------------------------------------

  GdkColor color;
  gdk_color_parse("green", &color);

  GtkWidget* button_patient = gtk_button_new_with_label("病人信息区");
  GtkWidget* button_hospital = gtk_button_new_with_label("医院名称");
  GtkWidget* button_sound = gtk_button_new_with_label("声功率 ");
  GtkWidget* button_output = gtk_button_new_with_label("声输出指数");
  GtkWidget* button_probe = gtk_button_new_with_label("探头");
  GtkWidget* button_mode = gtk_button_new_with_label("检查模式");

  GtkWidget* button_time = gtk_button_new_with_label("检查时间");

  gtk_container_add(GTK_CONTAINER(box_patient_info), button_patient);
  gtk_container_add(GTK_CONTAINER(box_hospital), button_hospital);
  gtk_container_add(GTK_CONTAINER(box_sound), button_sound);
  gtk_container_add(GTK_CONTAINER(box_output), button_output);
  gtk_container_add(GTK_CONTAINER(box_probe), button_probe);
  gtk_container_add(GTK_CONTAINER(box_mode), button_mode);

  gtk_container_add(GTK_CONTAINER(box_time), button_time);

  gtk_widget_modify_bg(button_patient, GTK_STATE_PRELIGHT, &m_btn_color);
  gtk_widget_modify_bg(button_hospital, GTK_STATE_PRELIGHT, &m_btn_color);
  gtk_widget_modify_bg(button_sound, GTK_STATE_PRELIGHT, &m_btn_color);
  gtk_widget_modify_bg(button_output, GTK_STATE_PRELIGHT, &m_btn_color);
  gtk_widget_modify_bg(button_probe, GTK_STATE_PRELIGHT, &m_btn_color);
  gtk_widget_modify_bg(button_mode, GTK_STATE_PRELIGHT, &m_btn_color);

  gtk_widget_modify_bg(button_patient, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_hospital, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_sound, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_output, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_probe, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_mode, GTK_STATE_NORMAL, &m_bg_color);
  gtk_widget_modify_bg(button_time, GTK_STATE_NORMAL, &m_bg_color);
}