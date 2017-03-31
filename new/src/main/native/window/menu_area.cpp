#include "window/menu_area.h"
#include "window/gtk_global.h"

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
  MenuArea* menu_area = (MenuArea*)data;
  menu_area->notebook_changed(page_num);
}

MenuArea::MenuArea() {
  m_width = 0;
  m_height = 0;

  m_label = NULL;
  m_notebook = NULL;

  m_menu_2d = new Menu2D();
  m_menu_m = new MenuM();
  m_menu_pw = new MenuPW();
  m_menu_cw = new MenuCW();
  m_menu_cfm = new MenuCFM();

  m_menu_measure2d = new MenuMeasure2D();
  m_menu_calc = new MenuCalc();
  m_menu_note = new MenuNote();
  m_menu_bodymark = new MenuBodyMark();
  m_menu_review = new MenuReview();
  m_menu_biopsy = new MenuBiopsy();
  m_menu_biopsybracket = new MenuBiopsyBracket();
  m_menu_biopsyverify = new MenuBiopsyVerify();
  m_menu_system = new MenuSystem();
  m_menu_efov = new MenuEFOV();
}

MenuArea::~MenuArea() {
  m_label = NULL;
  m_notebook = NULL;

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

  if (m_menu_measure2d != NULL) {
    delete m_menu_measure2d;

    m_menu_measure2d = NULL;
  }

  if (m_menu_calc != NULL) {
    delete m_menu_calc;

    m_menu_calc = NULL;
  }

  if (m_menu_note != NULL) {
    delete m_menu_note;

    m_menu_note = NULL;
  }

  if (m_menu_bodymark != NULL) {
    delete m_menu_bodymark;

    m_menu_bodymark = NULL;
  }

  if (m_menu_review != NULL) {
    delete m_menu_review;

    m_menu_review = NULL;
  }

  if (m_menu_biopsy != NULL) {
    delete m_menu_biopsy;

    m_menu_biopsy = NULL;
  }

  if (m_menu_biopsybracket != NULL) {
    delete m_menu_biopsybracket;

    m_menu_biopsybracket = NULL;
  }

  if (m_menu_biopsyverify != NULL) {
    delete m_menu_biopsyverify;

    m_menu_biopsyverify = NULL;
  }

  if (m_menu_system != NULL) {
    delete m_menu_system;

    m_menu_system = NULL;
  }

  if (m_menu_efov != NULL) {
    delete m_menu_review;

    m_menu_efov = NULL;
  }
}

void MenuArea::set_size(int width, int height) {
  m_width = width;
  m_height = height;
}

void MenuArea::initialize(GtkBox* box) {
  // label
  m_label = create_label("Sub Menu");
  set_font((GtkWidget*)m_label, "WenQuanYi Zen Hei", "", 14);
  gtk_misc_set_alignment(GTK_MISC(m_label), 0.5, 0.5);

  // notebook
  m_notebook = create_notebook();
  gtk_widget_modify_bg((GtkWidget*)m_notebook, GTK_STATE_NORMAL, get_bg_color());
  g_signal_connect(G_OBJECT(m_notebook), "switch-page", G_CALLBACK(signal_notebook_changed), this);

  //gtk_notebook_set_show_tabs(m_notebook, FALSE);

  gtk_widget_set_size_request((GtkWidget*)m_label, 0, LABEL_HEIGHT);

  gtk_box_pack_start(box, (GtkWidget*)m_label, FALSE, FALSE, 0);
  gtk_box_pack_start(box, (GtkWidget*)m_notebook, TRUE, TRUE, 0);

  initialize_notebook();

  show_menu(MENU_2D);
}

void MenuArea::show_menu(EnumMenuType menu_type) {
  if (m_notebook == NULL) {
    return;
  }

  switch (menu_type) {
  case MENU_2D:
    {
      gtk_notebook_set_current_page(m_notebook, 0);

      break;
    }
  case MENU_M:
    {
      gtk_notebook_set_current_page(m_notebook, 1);

      break;
    }
  case MENU_PW:
    {
      gtk_notebook_set_current_page(m_notebook, 2);

      break;
    }
  case MENU_CW:
    {
      gtk_notebook_set_current_page(m_notebook, 3);

      break;
    }
  case MENU_CFM:
    {
      gtk_notebook_set_current_page(m_notebook, 4);

      break;
    }
  case MENU_PDI:
    {
      gtk_notebook_set_current_page(m_notebook, 4);

      break;
    }
  case MENU_PWCFM:
    {
      gtk_notebook_set_current_page(m_notebook, 4);
      gtk_label_set_text(m_label, _("PW Color Mode"));

      break;
    }
  case MENU_CWCFM:
    {
      gtk_notebook_set_current_page(m_notebook, 4);

      break;
    }
  case MENU_MEASURE2D:
    {
      gtk_notebook_set_current_page(m_notebook, 5);

      break;
    }
  case MENU_CALC:
    {
      gtk_notebook_set_current_page(m_notebook, 6);

      break;
    }
  case MENU_NOTE:
    {
      gtk_notebook_set_current_page(m_notebook, 7);

      break;
    }
  case MENU_BODYMARK:
    {
      gtk_notebook_set_current_page(m_notebook, 8);

      break;
    }
  case MENU_REVIEW:
    {
      gtk_notebook_set_current_page(m_notebook, 9);

      break;
    }
  case MENU_BIOPSY:
    {
      gtk_notebook_set_current_page(m_notebook, 10);

      break;
    }
  case MENU_BIOPSYBRACKET:
    {
      gtk_notebook_set_current_page(m_notebook, 11);

      break;
    }
  case MENU_BIOPSYVERIFY:
    {
      gtk_notebook_set_current_page(m_notebook, 12);

      break;
    }
  case MENU_EFOV_PREPARE:
    {
      gtk_notebook_set_current_page(m_notebook, 13);

      break;
    }
  case MENU_EFOV_CAPTURE:
    {
      gtk_notebook_set_current_page(m_notebook, 13);

      break;
    }
  case MENU_EFOV_VIEW:
    {
      gtk_notebook_set_current_page(m_notebook, 13);

      break;
    }
  case MENU_EFOV_REVIEW:
    {
      gtk_notebook_set_current_page(m_notebook, 13);

      break;
    }
  case MENU_SYSTEM:
    {
      gtk_notebook_set_current_page(m_notebook, 14);

      break;
    }
  default:
    {
      gtk_label_set_text(m_label, "");

      break;
    }
  }

  update_label(menu_type);
}

void MenuArea::notebook_changed(unsigned int page_num) {
  EnumMenuType menu_type = MENU_2D;

  switch (page_num) {
  case 0:
    {
      menu_type = MENU_2D;

      break;
    }
  case 1:
    {
      menu_type = MENU_M;

      break;
    }
  case 2:
    {
      menu_type = MENU_PW;

      break;
    }
  case 3:
    {
      menu_type = MENU_CW;

      break;
    }
  case 4:
    {
      menu_type = MENU_CFM;

      break;
    }
  case 5:
    {
      menu_type = MENU_MEASURE2D;

      break;
    }
  case 6:
    {
      menu_type = MENU_CALC;

      break;
    }
  case 7:
    {
      menu_type = MENU_NOTE;

      break;
    }
  case 8:
    {
      menu_type = MENU_BODYMARK;

      break;
    }
  case 9:
    {
      menu_type = MENU_REVIEW;

      break;
    }
  case 10:
    {
      menu_type = MENU_BIOPSY;

      break;
    }
  case 11:
    {
      menu_type = MENU_BIOPSYBRACKET;

      break;
    }
  case 12:
    {
      menu_type = MENU_BIOPSYVERIFY;

      break;
    }
  case 13:
    {
      menu_type = MENU_EFOV_VIEW;

      break;
    }
  case 14:
    {
      menu_type = MENU_SYSTEM;

      break;
    }
  default:
    break;
  }

  update_label(menu_type);
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
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_measure2d, (GtkWidget*)create_label(_("MEASURE2D")));

  m_menu_measure2d->set_size(max_width, max_height);
  m_menu_measure2d->initialize(box_menu_measure2d);

  // calc menu
  GtkBox* box_menu_calc = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_calc, (GtkWidget*)create_label(_("CALC")));

  m_menu_calc->set_size(max_width, max_height);
  m_menu_calc->initialize(box_menu_calc);

  // note menu
  GtkBox* box_menu_note = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_note, (GtkWidget*)create_label(_("NOTE")));

  m_menu_note->set_size(max_width, max_height);
  m_menu_note->initialize(box_menu_note);

  // bodymark menu
  GtkBox* box_menu_bodymark = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_bodymark, (GtkWidget*)create_label(_("BODYMARK")));

  m_menu_bodymark->set_size(max_width, max_height);
  m_menu_bodymark->initialize(box_menu_bodymark);

  // review menu
  GtkBox* box_menu_review = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_review, (GtkWidget*)create_label(_("REVIEW")));

  m_menu_review->set_size(max_width, max_height);
  m_menu_review->initialize(box_menu_review);

  // biopsy menu
  GtkBox* box_menu_biopsy = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_biopsy, (GtkWidget*)create_label(_("BIOPSY")));

  m_menu_biopsy->set_size(max_width, max_height);
  m_menu_biopsy->initialize(box_menu_biopsy);

  // biopsy bracket menu
  GtkBox* box_menu_biopsybracket = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_biopsybracket, (GtkWidget*)create_label(_("BIOPSYBRACKET")));

  m_menu_biopsybracket->set_size(max_width, max_height);
  m_menu_biopsybracket->initialize(box_menu_biopsybracket);

  // biopsy verify menu
  GtkBox* box_menu_biopsyverify = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_biopsyverify, (GtkWidget*)create_label(_("BIOPSYVERIFY")));

  m_menu_biopsyverify->set_size(max_width, max_height);
  m_menu_biopsyverify->initialize(box_menu_biopsyverify);

  // efov
  GtkBox* box_menu_efov = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_efov, (GtkWidget*)create_label(_("EFOV")));

  m_menu_efov->set_size(max_width, max_height);
  m_menu_efov->initialize(box_menu_efov);

  // system menu
  GtkBox* box_menu_system = GTK_BOX(gtk_vbox_new(FALSE, 0));
  gtk_notebook_append_page(m_notebook, (GtkWidget*)box_menu_system, (GtkWidget*)create_label(_("SYSTEM")));

  m_menu_system->set_size(max_width, max_height);
  m_menu_system->initialize(box_menu_system);
}

void MenuArea::update_label(EnumMenuType menu_type) {
  switch (menu_type) {
  case MENU_2D:
    {
      gtk_label_set_text(m_label, _("2D Mode"));

      break;
    }
  case MENU_M:
    {
      gtk_label_set_text(m_label, _("M Mode"));

      break;
    }
  case MENU_PW:
    {
      gtk_label_set_text(m_label, _("PW Mode"));

      break;
    }
  case MENU_CW:
    {
      gtk_label_set_text(m_label, _("CW Mode"));

      break;
    }
  case MENU_CFM:
    {
      gtk_label_set_text(m_label, _("Color Mode"));

      break;
    }
  case MENU_PDI:
    {
      gtk_label_set_text(m_label, _("Color Mode"));

      break;
    }
  case MENU_PWCFM:
    {
      gtk_label_set_text(m_label, _("PW Color Mode"));

      break;
    }
  case MENU_CWCFM:
    {
      gtk_label_set_text(m_label, _("CW Color Mode"));

      break;
    }
  case MENU_MEASURE2D:
    {
      gtk_label_set_text(m_label, _("Measure"));

      break;
    }
  case MENU_CALC:
    {
      gtk_label_set_text(m_label, _("Calculate"));

      break;
    }
  case MENU_NOTE:
    {
      gtk_label_set_text(m_label, _("Note"));

      break;
    }
  case MENU_BODYMARK:
    {
      gtk_label_set_text(m_label, _("BodyMark"));

      break;
    }
  case MENU_REVIEW:
    {
      gtk_label_set_text(m_label, _("Review"));

      break;
    }
  case MENU_BIOPSY:
    {
      gtk_label_set_text(m_label, _("Biopsy"));

      break;
    }
  case MENU_BIOPSYBRACKET:
    {
      gtk_label_set_text(m_label, _("Biopsy Bracket"));

      break;
    }
  case MENU_BIOPSYVERIFY:
    {
      gtk_label_set_text(m_label, _("Verify"));

      break;
    }
  case MENU_EFOV_PREPARE:
    {
      gtk_label_set_text(m_label, _("eView Mode\nPrepare Status"));

      break;
    }
  case MENU_EFOV_CAPTURE:
    {
      gtk_label_set_text(m_label, _("eView Mode\nCapture Status"));

      break;
    }
  case MENU_EFOV_VIEW:
    {
      gtk_label_set_text(m_label, _("eView Mode\nView Status"));

      break;
    }
  case MENU_EFOV_REVIEW:
    {
      gtk_label_set_text(m_label, _("eView Mode\nReview Status"));

      break;
    }
  case MENU_SYSTEM:
    {
      gtk_label_set_text(m_label, _("System Setting"));

      break;
    }
  default:
    {
      gtk_label_set_text(m_label, "");

      break;
    }
  }

  adjust_font_size((GtkWidget*)m_label, "WenQuanYi Zen Hei", "", 14, m_width, LABEL_HEIGHT);
}