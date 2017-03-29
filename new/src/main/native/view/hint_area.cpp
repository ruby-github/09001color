#include "view/hint_area.h"

#include "view/gtk_global.h"

using namespace std;

//                        819                          205
// |---------------------------------------------|------------|
// |                 操作提示信息区              |   状态区   |
// |---------------------------------------------|------------|

#define STATUS_WIDTH  205

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
}

// ---------------------------------------------------------

// 提示信息
void HintArea::initialize_hint(GtkBox* box) {
  m_label_hint = create_labe("");
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_label_hint);
}

// 系统状态
void HintArea::initialize_status(GtkBox* box) {
  GtkWidget* button = gtk_button_new();
  gtk_widget_modify_bg(button, GTK_STATE_NORMAL, get_color("yellow"));

  gtk_container_add(GTK_CONTAINER(box), button);
}