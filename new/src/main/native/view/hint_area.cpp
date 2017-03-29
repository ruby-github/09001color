#include "view/hint_area.h"
#include "view/gtk_global.h"
#include "config.h"

using namespace std;

//                        819                          205
// |---------------------------------------------|------------|
// |                 操作提示信息区              |   状态区   |
// |---------------------------------------------|------------|

#define STATUS_WIDTH  205

const string icon_network_list[2] = {
  ICON_NETWORK_IDLE,
  ICON_NETWORK_OFFLINE
};

const string icon_audio_list[2] = {
  ICON_AUDIO_MUTED,
  ICON_AUDIO_ON
};

const string icon_charge_list[7] = {
  ICON_CHARGE_1,
  ICON_CHARGE_2,
  ICON_CHARGE_3,
  ICON_CHARGE_4,
  ICON_CHARGE_5,
  ICON_CHARGE_6,
  ICON_CHARGE_7
};

const string icon_scan_list[5] = {
  ICON_SCAN_00,
  ICON_SCAN_25,
  ICON_SCAN_50,
  ICON_SCAN_75,
  ICON_SCAN_100
};

const string icon_replay  = ICON_REPLAY;
const string icon_flashkey   = ICON_FLASHKEY;
const string icon_cdrom      = ICON_CDROM;
const string icon_printer = ICON_PRINTER;

gboolean time_clear_handler(gpointer data) {
  HintArea* hint_area= (HintArea*)data;
  hint_area->update_hint("", 0);

  return FALSE;
}

HintArea::HintArea() {
  m_width = 0;
  m_height = 0;
}

HintArea::~HintArea() {
}

void HintArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void HintArea::initialize(GtkBox* box) {
  GtkBox* box_hint = GTK_BOX(gtk_vbox_new(FALSE, 0));
  GtkBox* box_status = GTK_BOX(gtk_vbox_new(FALSE, 0));

  gtk_widget_set_size_request((GtkWidget*)box_status, STATUS_WIDTH, 0);

  gtk_box_pack_start(box, (GtkWidget*)box_hint, TRUE, TRUE, 0);
  gtk_box_pack_start(box, (GtkWidget*)box_status, FALSE, FALSE, 0);

  initialize_hint(box_hint);
  initialize_status(box_status);
}

void HintArea::update_hint(const string hint, unsigned int timeout) {
  if (m_label_hint != NULL) {
    gtk_label_set_text(m_label_hint, hint.c_str());
  }

  if (timeout > 0) {
    g_timeout_add_seconds(timeout, time_clear_handler, this);
  }
}

// ---------------------------------------------------------

// 提示信息
void HintArea::initialize_hint(GtkBox* box) {
  m_label_hint = create_labe("");
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_hint);
}

// 系统状态
void HintArea::initialize_status(GtkBox* box) {
  GtkTable* table = GTK_TABLE(gtk_table_new(1, 6, TRUE));
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)table);

  m_network = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_network, 0, 1, 0, 1);

  m_audio = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_audio, 1, 2, 0, 1);

  m_replay = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_replay, 2, 3, 0, 1);

  m_flashkey = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_flashkey, 3, 4, 0, 1);

  m_cdrom = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_cdrom, 4, 5, 0, 1);

  m_charge = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_charge, 5, 6, 0, 1);

  //m_printer = create_image();
  //m_replay = create_image();
}