#include "window/hint_area.h"
#include "window/gtk_global.h"
#include "config.h"

#include "device/battery.h"

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
  ICON_AUDIO_ON,
  ICON_AUDIO_MUTED
};

const string icon_battery_list[7] = {
  ICON_BATTERY_0,
  ICON_BATTERY_1,
  ICON_BATTERY_2,
  ICON_BATTERY_3,
  ICON_BATTERY_4,
  ICON_BATTERY_5,
  ICON_BATTERY
};

const string icon_scan_list[5] = {
  ICON_SCAN_00,
  ICON_SCAN_25,
  ICON_SCAN_50,
  ICON_SCAN_75,
  ICON_SCAN_100
};

const string icon_replay    = ICON_REPLAY;
const string icon_flashkey  = ICON_FLASHKEY;
const string icon_cdrom     = ICON_CDROM;
const string icon_printer   = ICON_PRINTER;

gboolean time_battery_handler(gpointer data) {
  HintArea* hint_area= (HintArea*)data;
  hint_area->update_battery();

  return TRUE;
}

gboolean time_scan_handler(gpointer data) {
  HintArea* hint_area= (HintArea*)data;
  hint_area->update_scan();

  if (hint_area->get_scan_count() < 0) {
    return FALSE;
  } else {
    return TRUE;
  }
}

gboolean time_clear_handler(gpointer data) {
  HintArea* hint_area= (HintArea*)data;
  hint_area->update_hint("", 0);

  return FALSE;
}

HintArea::HintArea() {
  m_width = 0;
  m_height = 0;

  m_label_hint = NULL;

  m_network = NULL;
  m_audio = NULL;
  m_replay = NULL;
  m_flashkey = NULL;
  m_cdrom = NULL;
  m_battery = NULL;
  m_printer = NULL;

  m_capacity_level = 0;
  m_scan_count = -1;
}

HintArea::~HintArea() {
  m_label_hint = NULL;

  m_network = NULL;
  m_audio = NULL;
  m_replay = NULL;
  m_flashkey = NULL;
  m_cdrom = NULL;
  m_battery = NULL;
  m_printer = NULL;
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

  update_replay(false);

  g_timeout_add(6000, time_battery_handler, this);
}

void HintArea::update_hint(const string hint, unsigned int timeout) {
  if (m_label_hint != NULL) {
    gtk_label_set_text(m_label_hint, hint.c_str());

    if (timeout > 0) {
      g_timeout_add_seconds(timeout, time_clear_handler, this);
    }
  }
}

void HintArea::update_network(bool on) {
  if (m_network != NULL) {
    if (on) {
      set_image(m_network, icon_network_list[0]);
    } else {
      set_image(m_network, icon_network_list[1]);
    }
  }
}

void HintArea::update_audio(bool on) {
  if (m_audio != NULL) {
    if (on) {
      set_image(m_audio, icon_audio_list[0]);
    } else {
      set_image(m_audio, icon_audio_list[1]);
    }
  }
}

void HintArea::update_replay(bool on) {
  if (m_replay != NULL) {
    if (on) {
      m_scan_count = -1;
      set_image(m_replay, icon_replay);
    } else {
      m_scan_count = 0;
      g_timeout_add(500, time_scan_handler, this);
    }
  }
}

void HintArea::update_flashkey(bool on) {
  if (m_flashkey != NULL) {
    if (on) {
      set_image(m_flashkey, icon_flashkey);
    } else {
      set_image(m_flashkey, "");
    }
  }
}

void HintArea::update_cdrom(bool on) {
  if (m_cdrom != NULL) {
    if (on) {
      set_image(m_cdrom, icon_cdrom);
    } else {
      set_image(m_cdrom, "");
    }
  }
}

void HintArea::update_battery() {
  if (m_battery != NULL) {
    unsigned int capacity_level = 0;

    Battery battery;
    int capacity = battery.capacity();

    if (capacity < 10) {
      capacity_level = 0;
    } else if (capacity < 30) {
      capacity_level = 1;
    } else if (capacity < 50) {
      capacity_level = 2;
    } else if (capacity < 70) {
      capacity_level = 3;
    } else if (capacity < 90) {
      capacity_level = 4;
    } else {
      capacity_level = 5;
    }

    if (capacity_level != m_capacity_level) {
      m_capacity_level = capacity_level;

      set_image(m_battery, icon_battery_list[m_capacity_level]);
    }
  }
}

void HintArea::update_printer(bool on) {
  if (m_printer != NULL) {
    if (on) {
      set_image(m_printer, icon_printer);
    } else {
      set_image(m_printer, "");
    }
  }
}

void HintArea::update_scan() {
  if (m_replay != NULL) {
    if (m_scan_count >= 0) {
      if (m_scan_count > 4) {
        m_scan_count = 0;
      }

      set_image(m_replay, icon_scan_list[m_scan_count]);
      m_scan_count += 1;
    }
  }
}

// ---------------------------------------------------------

// 提示信息
void HintArea::initialize_hint(GtkBox* box) {
  m_label_hint = create_label("");
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_hint);
}

// 系统状态
void HintArea::initialize_status(GtkBox* box) {
  GtkTable* table = GTK_TABLE(gtk_table_new(1, 6, TRUE));
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)table);

  m_network = create_image(icon_network_list[0], 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_network, 0, 1, 0, 1);

  m_audio = create_image(icon_audio_list[0], 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_audio, 1, 2, 0, 1);

  m_replay = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_replay, 2, 3, 0, 1);

  m_flashkey = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_flashkey, 3, 4, 0, 1);

  m_cdrom = create_image("", 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_cdrom, 4, 5, 0, 1);

  m_battery = create_image(icon_battery_list[m_capacity_level], 0, 0);
  gtk_table_attach_defaults(table, (GtkWidget*)m_battery, 5, 6, 0, 1);

  //m_printer = create_image();
}