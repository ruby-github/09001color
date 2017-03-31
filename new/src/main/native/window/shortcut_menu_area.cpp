#include "window/shortcut_menu_area.h"
#include "window/gtk_global.h"
#include "config.h"

//       120       32      120         120         120         120         120        120      32      120
//  |-------------|---|-----------|-----------|-----------|-----------|-----------|-----------|---|------------|
//  |             |   |           |           |           |           |           |           |   |            |
//  |   保留区    |<< | 快捷菜单1 | 快捷菜单2 | 快捷菜单3 | 快捷菜单4 | 快捷菜单5 | 快捷菜单6 | >>|   保留区   |
//  |             |   |           |           |           |           |           |           |   |            |
//  |-------------|---|-----------|-----------|-----------|-----------|-----------|-----------|---|------------|

#define RESERVED_LEFT_WIDTH   120
#define RESERVED_RIGHT_WIDTH  120
#define ARROW_WIDTH           32
#define MENU_WIDTH            120

ShortcutMenuArea::ShortcutMenuArea() {
  m_width = 0;
  m_height = 0;

  for (int i = 0; i < KNOB_NUM; i++) {
    m_button_list[i] = NULL;
  }

  m_button_left = NULL;
  m_button_right = NULL;
}

ShortcutMenuArea::~ShortcutMenuArea() {
  for (int i = 0; i < KNOB_NUM; i++) {
    m_button_list[i] = NULL;
  }

  m_button_left = NULL;
  m_button_right = NULL;
}

void ShortcutMenuArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void ShortcutMenuArea::initialize(GtkBox* box) {
  GtkBox* box_reserved_left = GTK_BOX(gtk_hbox_new(FALSE, 0));
  GtkBox* box_knob = GTK_BOX(gtk_hbox_new(FALSE, 0));
  GtkBox* box_reserved_right = GTK_BOX(gtk_hbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_reserved_left, RESERVED_LEFT_WIDTH, 0);
  gtk_widget_set_size_request((GtkWidget*)box_reserved_right, RESERVED_RIGHT_WIDTH, 0);

  gtk_box_pack_start(box, (GtkWidget*)box_reserved_left, FALSE, FALSE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_knob, TRUE, TRUE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_reserved_right, FALSE, FALSE, 0);

  initialize_knob(box_knob);
}

// ---------------------------------------------------------

void ShortcutMenuArea::initialize_knob(GtkBox* box) {
  // left
  m_button_left = create_button(_("<<"));

  gtk_widget_set_size_request((GtkWidget*)m_button_left, ARROW_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_left, FALSE, FALSE, 0);

  // button1
  m_button_list[0] = create_button_with_image(IMAGE_SHORTCUT_MENU_1, MENU_WIDTH, m_height);

  gtk_widget_set_size_request((GtkWidget*)m_button_list[0], MENU_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_list[0], FALSE, FALSE, 0);

  // button2
  m_button_list[1] = create_button_with_image(IMAGE_SHORTCUT_MENU_2, MENU_WIDTH, m_height);

  gtk_widget_set_size_request((GtkWidget*)m_button_list[1], MENU_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_list[1], FALSE, FALSE, 0);

  // button3
  m_button_list[2] = create_button_with_image(IMAGE_SHORTCUT_MENU_3, MENU_WIDTH, m_height);

  gtk_widget_set_size_request((GtkWidget*)m_button_list[2], MENU_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_list[2], FALSE, FALSE, 0);

  // button4
  m_button_list[3] = create_button_with_image(IMAGE_SHORTCUT_MENU_4, MENU_WIDTH, m_height);

  gtk_widget_set_size_request((GtkWidget*)m_button_list[3], MENU_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_list[3], FALSE, FALSE, 0);

  // button5
  m_button_list[4] = create_button_with_image(IMAGE_SHORTCUT_MENU_5, MENU_WIDTH, m_height);

  gtk_widget_set_size_request((GtkWidget*)m_button_list[4], MENU_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_list[4], FALSE, FALSE, 0);

  // button6
  m_button_list[5] = create_button_with_image(IMAGE_SHORTCUT_MENU_6, MENU_WIDTH, m_height);

  gtk_widget_set_size_request((GtkWidget*)m_button_list[5], MENU_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_list[5], FALSE, FALSE, 0);

  // right
  m_button_right = create_button(_(">>"));

  gtk_widget_set_size_request((GtkWidget*)m_button_right, ARROW_WIDTH, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_button_right, TRUE, TRUE, 0);
  gtk_button_set_alignment(m_button_right, 1, 0.5);

  for (int i = 0; i < KNOB_NUM; i++) {
    gtk_widget_modify_bg((GtkWidget*)m_button_list[i], GTK_STATE_NORMAL, get_bg_color());
    gtk_widget_modify_bg((GtkWidget*)m_button_list[i], GTK_STATE_ACTIVE, get_bg_color());
    gtk_widget_modify_bg((GtkWidget*)m_button_list[i], GTK_STATE_PRELIGHT, get_bg_color());
    gtk_widget_modify_bg((GtkWidget*)m_button_list[i], GTK_STATE_SELECTED, get_bg_color());
    gtk_widget_modify_bg((GtkWidget*)m_button_list[i], GTK_STATE_INSENSITIVE, get_bg_color());
  }

  gtk_widget_modify_bg((GtkWidget*)m_button_left, GTK_STATE_NORMAL, get_bg_color());
  gtk_widget_modify_bg((GtkWidget*)m_button_left, GTK_STATE_ACTIVE, get_color("green"));
  gtk_widget_modify_bg((GtkWidget*)m_button_left, GTK_STATE_PRELIGHT, get_color("green"));
  gtk_widget_modify_bg((GtkWidget*)m_button_left, GTK_STATE_SELECTED, get_color("green"));
  gtk_widget_modify_bg((GtkWidget*)m_button_left, GTK_STATE_INSENSITIVE, get_color("green"));

  gtk_widget_modify_bg((GtkWidget*)m_button_right, GTK_STATE_NORMAL, get_bg_color());
  gtk_widget_modify_bg((GtkWidget*)m_button_right, GTK_STATE_ACTIVE, get_color("green"));
  gtk_widget_modify_bg((GtkWidget*)m_button_right, GTK_STATE_PRELIGHT, get_color("green"));
  gtk_widget_modify_bg((GtkWidget*)m_button_right, GTK_STATE_SELECTED, get_color("green"));
  gtk_widget_modify_bg((GtkWidget*)m_button_right, GTK_STATE_INSENSITIVE, get_color("green"));
}