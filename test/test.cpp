#include <stdio.h>
#include <iostream>
#include <gtk/gtk.h>

using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int AREA_MENU_HEIGHT = 100;
const int AREA_STATUS_HEIGHT = 50;

const int AREA_LEFT_WIDTH = 150;
const int AREA_RIGHT_WIDTH = 150;

const int LOGO_HEIGHT = 100;
const int CUSTOM_HEIGHT = 100;

const int INFO_HEIGHT = 30;
const int RES_HEIGHT = 70;

const int TIME_WIDTH = 100;

void init_area_main_panel(GtkWidget* widget);
void init_area_menu_panel(GtkWidget* widget);
void init_area_status_panel(GtkWidget* widget);

void init_area_main_left_panel(GtkWidget* widget);
void init_area_main_info_panel(GtkWidget* widget);
void init_area_main_right_panel(GtkWidget* widget);

void init_area_main_hospital_info_panel(GtkWidget* widget);

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK (gtk_main_quit), NULL);

    gtk_container_set_border_width(GTK_CONTAINER (window), 0);

    gtk_window_set_title(GTK_WINDOW (window), "gtk test");
    gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    GtkWidget* box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER (window), box);

    GtkWidget* box_area_main = gtk_hbox_new(FALSE, 0);
    GtkWidget* box_area_menu= gtk_hbox_new(FALSE, 0);
    GtkWidget* box_area_status = gtk_hbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_menu, 0, AREA_MENU_HEIGHT);
    gtk_widget_set_size_request(box_area_status, 0, AREA_STATUS_HEIGHT);

    gtk_box_pack_start(GTK_BOX(box), box_area_main, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), box_area_menu, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), box_area_status, FALSE, FALSE, 0);

    init_area_main_panel(box_area_main);
    init_area_menu_panel(box_area_menu);
    init_area_status_panel(box_area_status);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

// 主视图区
void init_area_main_panel(GtkWidget* widget) {
    GtkWidget* box_area_left = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_info = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_right = gtk_vbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_left, AREA_LEFT_WIDTH, 0);
    gtk_widget_set_size_request(box_area_right, AREA_RIGHT_WIDTH, 0);

    gtk_box_pack_start(GTK_BOX(widget), box_area_left, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_info, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_right, FALSE, FALSE, 0);

    init_area_main_left_panel(box_area_left);
    init_area_main_info_panel(box_area_info);
    init_area_main_right_panel(box_area_right);
}

// 快捷菜单区
void init_area_menu_panel(GtkWidget* widget) {
    GtkWidget* button1 = gtk_button_new_with_label("快捷菜单1");
    GtkWidget* button2 = gtk_button_new_with_label("快捷菜单2");
    GtkWidget* button3 = gtk_button_new_with_label("快捷菜单3");
    GtkWidget* button4 = gtk_button_new_with_label("快捷菜单4");
    GtkWidget* button5 = gtk_button_new_with_label("快捷菜单5");
    GtkWidget* button6 = gtk_button_new_with_label("快捷菜单6");

    gtk_box_pack_start(GTK_BOX(widget), button1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), button2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), button3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), button4, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), button5, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), button6, TRUE, TRUE, 0);
}

// 帮助信息区
void init_area_status_panel(GtkWidget* widget) {
    GtkWidget* box_area_help = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_system = gtk_vbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_system, AREA_RIGHT_WIDTH, 0);

    gtk_box_pack_start(GTK_BOX(widget), box_area_help, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_system, FALSE, FALSE, 0);

    // -----------------------------------------------------

    GtkWidget* button_help = gtk_button_new_with_label("帮助信息区");
    GtkWidget* button_system = gtk_button_new_with_label("系统状态区");

    gtk_container_add(GTK_CONTAINER(box_area_help), button_help);
    gtk_container_add(GTK_CONTAINER(box_area_system), button_system);
}

void init_area_main_left_panel(GtkWidget* widget) {
    GtkWidget* box_area_logo = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_param = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_custom = gtk_vbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_logo, 0, LOGO_HEIGHT);
    gtk_widget_set_size_request(box_area_custom, 0, CUSTOM_HEIGHT);

    gtk_box_pack_start(GTK_BOX(widget), box_area_logo, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_param, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_custom, FALSE, FALSE, 0);

    // -----------------------------------------------------

    GtkWidget* button_logo = gtk_button_new_with_label("LOGO");
    GtkWidget* button_param = gtk_button_new_with_label("图像参数区");
    GtkWidget* button_custom = gtk_button_new_with_label("自定义按键功能指示区");

    gtk_container_add(GTK_CONTAINER(box_area_logo), button_logo);
    gtk_container_add(GTK_CONTAINER(box_area_param), button_param);
    gtk_container_add(GTK_CONTAINER(box_area_custom), button_custom);
}

void init_area_main_info_panel(GtkWidget* widget) {
    GtkWidget* box_area_info = gtk_hbox_new(FALSE, 0);
    GtkWidget* box_area_image = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_mov = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_res = gtk_vbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_info, 0, LOGO_HEIGHT);
    gtk_widget_set_size_request(box_area_mov, 0, CUSTOM_HEIGHT - RES_HEIGHT);
    gtk_widget_set_size_request(box_area_res, 0, RES_HEIGHT);

    gtk_box_pack_start(GTK_BOX(widget), box_area_info, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_image, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_mov, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_res, FALSE, FALSE, 0);

    // -----------------------------------------------------

    GtkWidget* button_image = gtk_button_new_with_label("图像区");
    GtkWidget* button_mov = gtk_button_new_with_label("电影回放区");
    GtkWidget* button_res = gtk_button_new_with_label("光标资源区");

    gtk_container_add(GTK_CONTAINER(box_area_image), button_image);
    gtk_container_add(GTK_CONTAINER(box_area_mov), button_mov);
    gtk_container_add(GTK_CONTAINER(box_area_res), button_res);

    init_area_main_hospital_info_panel(box_area_info);
}

void init_area_main_right_panel(GtkWidget* widget) {
    GtkWidget* box_area_store = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_thumb = gtk_vbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_thumb, 0, RES_HEIGHT);

    gtk_box_pack_start(GTK_BOX(widget), box_area_store, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_thumb, FALSE, FALSE, 0);

    // -----------------------------------------------------

    GtkWidget* button_store = gtk_button_new_with_label("已存储图像区菜单区");
    GtkWidget* button_thumb = gtk_button_new_with_label("缩略图功能区");

    gtk_container_add(GTK_CONTAINER(box_area_store), button_store);
    gtk_container_add(GTK_CONTAINER(box_area_thumb), button_thumb);
}

void init_area_main_hospital_info_panel(GtkWidget* widget) {
    GtkWidget* box_area_info = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_time = gtk_vbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_time, TIME_WIDTH, 0);

    gtk_box_pack_start(GTK_BOX(widget), box_area_info, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(widget), box_area_time, FALSE, FALSE, 0);

    GtkWidget* box_area_patient_info = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_hospital_info = gtk_hbox_new(FALSE, 0);

    gtk_widget_set_size_request(box_area_patient_info, 0, INFO_HEIGHT);

    gtk_box_pack_start(GTK_BOX(box_area_info), box_area_patient_info, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box_area_info), box_area_hospital_info, TRUE, TRUE, 0);

    GtkWidget* box_area_hospital = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_sound = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_output = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_probe = gtk_vbox_new(FALSE, 0);
    GtkWidget* box_area_mode = gtk_vbox_new(FALSE, 0);

    gtk_box_pack_start(GTK_BOX(box_area_hospital_info), box_area_hospital, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box_area_hospital_info), box_area_sound, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box_area_hospital_info), box_area_output, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box_area_hospital_info), box_area_probe, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box_area_hospital_info), box_area_mode, FALSE, FALSE, 0);

    // -----------------------------------------------------

    GtkWidget* button_patient = gtk_button_new_with_label("病人信息区");
    GtkWidget* button_hospital = gtk_button_new_with_label("医院名称");
    GtkWidget* button_sound = gtk_button_new_with_label("声功率 ");
    GtkWidget* button_output = gtk_button_new_with_label("声输出指数");
    GtkWidget* button_probe = gtk_button_new_with_label("探头");
    GtkWidget* button_mode = gtk_button_new_with_label("检查模式");

    GtkWidget* button_time = gtk_button_new_with_label("检查时间");

    gtk_container_add(GTK_CONTAINER(box_area_patient_info), button_patient);
    gtk_container_add(GTK_CONTAINER(box_area_hospital), button_hospital);
    gtk_container_add(GTK_CONTAINER(box_area_sound), button_sound);
    gtk_container_add(GTK_CONTAINER(box_area_output), button_output);
    gtk_container_add(GTK_CONTAINER(box_area_probe), button_probe);
    gtk_container_add(GTK_CONTAINER(box_area_mode), button_mode);

    gtk_container_add(GTK_CONTAINER(box_area_time), button_time);
}