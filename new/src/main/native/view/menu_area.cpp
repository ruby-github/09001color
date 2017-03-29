#include "view/menu_area.h"
#include "view/gtk_global.h"

// ---   |---------------|
//  |    |               |
//  | 60 |     label     |
//  |    |               |
// ---   |---------------|
//       |               |
//       |     menu      |
//       |               |
//       |               |
//       |               |
//       |               |
//       |               |
//       |               |
//       |               |
//       |               |
//       |               |
//       |---------------|

#define LABEL_HEIGHT  60

void signal_notebook_changed(GtkNotebook* notebook, GtkNotebookPage* page, guint page_num, gpointer* data) {
}

MenuArea::MenuArea() {
  m_width = 0;
  m_height = 0;

  m_fixed = NULL;
  m_box_notebook = NULL;

  m_menu_2d = new NotebookMenu2D();
  m_menu_m = new NotebookMenuM();
  m_menu_pw = new NotebookMenuPW();
  m_menu_cw = new NotebookMenuCW();
  m_menu_cfm = new NotebookMenuCFM();
}

MenuArea::~MenuArea() {
  m_fixed = NULL;
  m_box_notebook = NULL;

  if (m_menu_2d != NULL) {
    delete m_menu_2d;

    m_menu_2d = NULL;
  }

  if (m_menu_m != NULL) {
    delete m_menu_m;

    m_menu_m = NULL;
  }

  if (m_menu_pw != NULL) {
    delete m_menu_pw;

    m_menu_pw = NULL;
  }

  if (m_menu_cw != NULL) {
    delete m_menu_cw;

    m_menu_cw = NULL;
  }

  if (m_menu_cfm != NULL) {
    delete m_menu_cfm;

    m_menu_cfm = NULL;
  }
}

void MenuArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuArea::initialize(GtkBox* box) {
  m_fixed = GTK_FIXED(gtk_fixed_new());
  gtk_widget_set_size_request((GtkWidget*)m_fixed, m_width, m_height);
  gtk_container_add(GTK_CONTAINER(box), (GtkWidget*)m_fixed);

  initialize_notebook();
  initialize_other_menu();
}

// ---------------------------------------------------------

void MenuArea::initialize_notebook() {
  m_box_notebook = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_widget_set_size_request((GtkWidget*)m_box_notebook, m_width, m_height);
  gtk_fixed_put(m_fixed, (GtkWidget*)m_box_notebook, 0, 0);

  m_label = create_label("Sub Menu");
  set_font((GtkWidget*)m_label, "WenQuanYi Zen Hei", "", 16);
  gtk_misc_set_alignment(GTK_MISC(m_label), 0.5, 0.5);

  m_notebook = create_notebook();
  gtk_widget_modify_bg((GtkWidget*)m_notebook, GTK_STATE_NORMAL, get_bg_color());
  gtk_container_set_border_width (GTK_CONTAINER(m_notebook), 0);
  g_signal_connect(G_OBJECT(m_notebook), "switch-page", G_CALLBACK(signal_notebook_changed), this);

  gtk_widget_set_size_request((GtkWidget*)m_label, 0, LABEL_HEIGHT);

  gtk_box_pack_start(m_box_notebook, (GtkWidget*)m_label, FALSE, FALSE, 0);
  gtk_box_pack_start(m_box_notebook, (GtkWidget*)m_notebook, TRUE, TRUE, 0);

  // 2D menu
  GtkBox* box_menu_2d = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_container_add(GTK_CONTAINER(m_notebook), (GtkWidget*)box_menu_2d);

  GtkLabel* labe_menu_2d = create_label(_("2D"));
  gtk_notebook_set_tab_label(m_notebook, gtk_notebook_get_nth_page(m_notebook, 0), (GtkWidget*)labe_menu_2d);

  // M menu
  GtkBox* box_menu_m = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_container_add(GTK_CONTAINER(m_notebook), (GtkWidget*)box_menu_m);

  GtkLabel* labe_menu_m = create_label(_("M"));
  gtk_notebook_set_tab_label(m_notebook, gtk_notebook_get_nth_page(m_notebook, 1), (GtkWidget*)labe_menu_m);

  // PW menu
  GtkBox* box_menu_pw = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_container_add(GTK_CONTAINER(m_notebook), (GtkWidget*)box_menu_pw);

  GtkLabel* labe_menu_pw = create_label(_("PW"));
  gtk_notebook_set_tab_label(m_notebook, gtk_notebook_get_nth_page(m_notebook, 2), (GtkWidget*)labe_menu_pw);

  // CW menu
  GtkBox* box_menu_cw = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_container_add(GTK_CONTAINER(m_notebook), (GtkWidget*)box_menu_cw);

  GtkLabel* labe_menu_cw = create_label(_("CW"));
  gtk_notebook_set_tab_label(m_notebook, gtk_notebook_get_nth_page(m_notebook, 3), (GtkWidget*)labe_menu_cw);

  // CFM menu
  GtkBox* box_menu_cfm = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_container_add(GTK_CONTAINER(m_notebook), (GtkWidget*)box_menu_cfm);

  GtkLabel* labe_menu_cfm = create_label(_("CFM/PDI"));
  gtk_notebook_set_tab_label(m_notebook, gtk_notebook_get_nth_page(m_notebook, 4), (GtkWidget*)labe_menu_cfm);

  m_menu_2d->set_size(m_width, m_height - LABEL_HEIGHT);
  m_menu_2d->initialize(box_menu_2d);

  m_menu_m->set_size(m_width, m_height - LABEL_HEIGHT);
  m_menu_m->initialize(box_menu_m);

  m_menu_pw->set_size(m_width, m_height - LABEL_HEIGHT);
  m_menu_pw->initialize(box_menu_pw);

  m_menu_cw->set_size(m_width, m_height - LABEL_HEIGHT);
  m_menu_cw->initialize(box_menu_cw);

  m_menu_cfm->set_size(m_width, m_height - LABEL_HEIGHT);
  m_menu_cfm->initialize(box_menu_cfm);
}

void MenuArea::initialize_other_menu() {
}