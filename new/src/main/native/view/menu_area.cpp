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

  m_box_label = NULL;
  m_box_menu = NULL;

  m_label = NULL;
  m_fixed_menu = NULL;
  m_notebook = NULL;

  m_notebook_menu_2d = new NotebookMenu2D();
  m_notebook_menu_m = new NotebookMenuM();
  m_notebook_menu_pw = new NotebookMenuPW();
  m_notebook_menu_cw = new NotebookMenuCW();
  m_notebook_menu_cfm = new NotebookMenuCFM();

  m_fixed_menu_measure2d = new FixedMenuMeasure2D();
  m_fixed_menu_calc = new FixedMenuCalc();
  m_fixed_menu_note = new FixedMenuNote();
  m_fixed_menu_bodymark = new FixedMenuBodyMark();
  m_fixed_menu_review = new FixedMenuReview();
  m_fixed_menu_biopsy = new FixedMenuBiopsy();
  m_fixed_menu_biopsybracket = new FixedMenuBiopsyBracket();
  m_fixed_menu_biopsyverify = new FixedMenuBiopsyVerify();
  m_fixed_menu_system = new FixedMenuSystem();
  m_fixed_menu_efov = new FixedMenuEFOV();
}

MenuArea::~MenuArea() {
  m_box_label = NULL;
  m_box_menu = NULL;

  m_label = NULL;
  m_fixed_menu = NULL;
  m_notebook = NULL;

  if (m_notebook_menu_2d != NULL) {
    delete m_notebook_menu_2d;

    m_notebook_menu_2d = NULL;
  }

  if (m_notebook_menu_m != NULL) {
    delete m_notebook_menu_m;

    m_notebook_menu_m = NULL;
  }

  if (m_notebook_menu_pw != NULL) {
    delete m_notebook_menu_pw;

    m_notebook_menu_pw = NULL;
  }

  if (m_notebook_menu_cw != NULL) {
    delete m_notebook_menu_cw;

    m_notebook_menu_cw = NULL;
  }

  if (m_notebook_menu_cfm != NULL) {
    delete m_notebook_menu_cfm;

    m_notebook_menu_cfm = NULL;
  }

  if (m_fixed_menu_measure2d != NULL) {
    delete m_fixed_menu_measure2d;

    m_fixed_menu_measure2d = NULL;
  }

  if (m_fixed_menu_calc != NULL) {
    delete m_fixed_menu_calc;

    m_fixed_menu_calc = NULL;
  }

  if (m_fixed_menu_note != NULL) {
    delete m_fixed_menu_note;

    m_fixed_menu_note = NULL;
  }

  if (m_fixed_menu_bodymark != NULL) {
    delete m_fixed_menu_bodymark;

    m_fixed_menu_bodymark = NULL;
  }

  if (m_fixed_menu_review != NULL) {
    delete m_fixed_menu_review;

    m_fixed_menu_review = NULL;
  }

  if (m_fixed_menu_biopsy != NULL) {
    delete m_fixed_menu_biopsy;

    m_fixed_menu_biopsy = NULL;
  }

  if (m_fixed_menu_biopsybracket != NULL) {
    delete m_fixed_menu_biopsybracket;

    m_fixed_menu_biopsybracket = NULL;
  }

  if (m_fixed_menu_biopsyverify != NULL) {
    delete m_fixed_menu_biopsyverify;

    m_fixed_menu_biopsyverify = NULL;
  }

  if (m_fixed_menu_system != NULL) {
    delete m_fixed_menu_system;

    m_fixed_menu_system = NULL;
  }

  if (m_fixed_menu_efov != NULL) {
    delete m_fixed_menu_review;

    m_fixed_menu_efov = NULL;
  }
}

void MenuArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuArea::initialize(GtkBox* box) {
  // label
  m_label = create_label("Sub Menu");
  set_font((GtkWidget*)m_label, "WenQuanYi Zen Hei", "", 16);
  gtk_misc_set_alignment(GTK_MISC(m_label), 0.5, 0.5);

  // notebook
  m_notebook = create_notebook();
  gtk_widget_modify_bg((GtkWidget*)m_notebook, GTK_STATE_NORMAL, get_bg_color());
  g_signal_connect(G_OBJECT(m_notebook), "switch-page", G_CALLBACK(signal_notebook_changed), this);

  gtk_widget_set_size_request((GtkWidget*)m_label, 0, LABEL_HEIGHT);

  gtk_box_pack_start(box, (GtkWidget*)m_label, FALSE, FALSE, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_notebook, TRUE, TRUE, 0);

  initialize_notebook();

  show_menu_2d();
}

void MenuArea::show_menu(void) {
}

void MenuArea::hide_all_menu(void) {
  // m_notebook_menu_2d->hide();
  // m_notebook_menu_m->hide();
  // m_notebook_menu_pw->hide();
  // m_notebook_menu_cw->hide();
  // m_notebook_menu_cfm->hide();

  if (m_notebook != NULL) {
    gtk_widget_hide_all((GtkWidget*)m_notebook);
  }

  // m_fixed_menu_measure2d->hide();
  // m_fixed_menu_calc->hide();
  // m_fixed_menu_note->hide();
  // m_fixed_menu_bodymark->hide();
  // m_fixed_menu_review->hide();
  // m_fixed_menu_biopsy->hide();
  // m_fixed_menu_biopsybracket->hide();
  // m_fixed_menu_biopsyverify->hide();
  // m_fixed_menu_system->hide();
  // m_fixed_menu_efov->hide();
}

void MenuArea::show_menu_2d(void) {
  m_menu_type = MENU_2D;

  hide_all_menu();

  gtk_label_set_text(m_label, _("2D Mode"));
  gtk_notebook_set_show_tabs(m_notebook, TRUE);

  //m_notebook_menu_2d->show();
}

void MenuArea::show_menu_m(void) {
}

void MenuArea::show_menu_pw(void) {
}

void MenuArea::show_menu_cw(void) {
}

void MenuArea::show_menu_cfm(void) {
}

void MenuArea::show_menu_pwcfm(bool current) {
}

void MenuArea::show_menu_cwcfm(bool current) {
}

void MenuArea::show_menu_measure2d(void) {
}

void MenuArea::show_menu_calc(void) {
}

void MenuArea::show_menu_note(void) {
}

void MenuArea::show_menu_bodymark(void) {
}

void MenuArea::show_menu_review(void) {
}

void MenuArea::show_menu_biopsy(void) {
}

void MenuArea::show_menu_biopsybracket(void) {
}

void MenuArea::show_menu_biopsyverify(void) {
}

void MenuArea::show_menu_system(void) {
}

void MenuArea::show_menu_efov_prepare(void) {
}

void MenuArea::show_menu_efov_capture(void) {
}

void MenuArea::show_menu_efov_view(void) {
}

void MenuArea::show_menu_efov_review(void) {
}

// ---------------------------------------------------------

void MenuArea::initialize_notebook() {
  int max_width = m_width;
  int max_height = m_height - LABEL_HEIGHT - 30;

  // 2d menu
  GtkBox* box_menu_2d = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_2d, (GtkWidget*)create_label(_("2D")));

  m_menu_2d->set_size(max_width, max_height);
  m_menu_2d->initialize(box_menu_2d);

  // m menu
  GtkBox* box_menu_m = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_m, (GtkWidget*)create_label(_("M")));

  m_menu_m->set_size(max_width, max_height);
  m_menu_m->initialize(box_menu_m);

  // pw menu
  GtkBox* box_menu_pw = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_pw, (GtkWidget*)create_label(_("PW")));

  m_menu_pw->set_size(max_width, max_height);
  m_menu_pw->initialize(box_menu_pw);

  // cw menu
  GtkBox* box_menu_cw = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_cw, (GtkWidget*)create_label(_("CW")));

  m_menu_cw->set_size(max_width, max_height);
  m_menu_cw->initialize(box_menu_cw);

  // cfm menu
  GtkBox* box_menu_cfm = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_cfm, (GtkWidget*)create_label(_("CFM/PDI")));

  m_menu_cfm->set_size(max_width, max_height);
  m_menu_cfm->initialize(box_menu_cfm);

  // measure2d menu
  GtkBox* box_menu_measure2d = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_measure2d, (GtkWidget*)create_label(_("")));

  m_menu_measure2d->set_size(max_width, max_height);
  m_menu_measure2d->initialize(box_menu_measure2d);

  // calc menu
  GtkBox* box_menu_calc = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_calc, (GtkWidget*)create_label(_("")));

  m_menu_calc->set_size(max_width, max_height);
  m_menu_calc->initialize(box_menu_calc);

  // note menu
  GtkBox* box_menu_note = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_note, (GtkWidget*)create_label(_("")));

  m_menu_note->set_size(max_width, max_height);
  m_menu_note->initialize(box_menu_note);

  // bodymark menu
  GtkBox* box_menu_bodymark = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_bodymark, (GtkWidget*)create_label(_("")));

  m_menu_bodymark->set_size(max_width, max_height);
  m_menu_bodymark->initialize(box_menu_bodymark);

  // review menu
  GtkBox* box_menu_review = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_review, (GtkWidget*)create_label(_("")));

  m_menu_review->set_size(max_width, max_height);
  m_menu_review->initialize(box_menu_review);

  // biopsy menu
  GtkBox* box_menu_biopsy = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_biopsy, (GtkWidget*)create_label(_("")));

  m_menu_biopsy->set_size(max_width, max_height);
  m_menu_biopsy->initialize(box_menu_biopsy);

  // biopsy bracket menu
  GtkBox* box_menu_biopsybracket = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_biopsybracket, (GtkWidget*)create_label(_("")));

  m_menu_biopsybracket->set_size(max_width, max_height);
  m_menu_biopsybracket->initialize(box_menu_biopsybracket);

  // biopsy verify menu
  GtkBox* box_menu_biopsyverify = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_biopsyverify, (GtkWidget*)create_label(_("")));

  m_menu_biopsyverify->set_size(max_width, max_height);
  m_menu_biopsyverify->initialize(box_menu_biopsyverify);

  // system menu
  GtkBox* box_menu_system = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_system, (GtkWidget*)create_label(_("")));

  m_menu_system->set_size(max_width, max_height);
  m_menu_system->initialize(box_menu_system);

  // efov
  GtkBox* box_menu_efov = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_efov, (GtkWidget*)create_label(_("")));

  m_menu_efov->set_size(max_width, max_height);
  m_menu_efov->initialize(box_menu_efov);
}