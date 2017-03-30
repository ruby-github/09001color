#ifndef __menu_area_h__
#define __menu_area_h__

#include "view/menu_2d.h"
#include "view/menu_m.h"
#include "view/menu_pw.h"
#include "view/menu_cw.h"
#include "view/menu_cfm.h"
#include "view/menu_measure2d.h"
#include "view/menu_calc.h"
#include "view/menu_note.h"
#include "view/menu_bodymark.h"
#include "view/menu_review.h"
#include "view/menu_biopsy.h"
#include "view/menu_biopsybracket.h"
#include "view/menu_biopsyverify.h"
#include "view/menu_system.h"
#include "view/menu_efov.h"

class MenuArea {
public:
  MenuArea();
  ~MenuArea();

  enum EnumMenuType {
    MENU_2D,
    MENU_M,
    MENU_PW,
    MENU_CW,
    MENU_CFM,
    MENU_PDI,
    MENU_PWCFM,
    MENU_CWCFM,

    MENU_MEASURE2D,
    MENU_CALC,
    MENU_NOTE,
    MENU_BODYMARK,
    MENU_REVIEW,
    MENU_BIOPSY,
    MENU_BIOPSYBRACKET,
    MENU_BIOPSYVERIFY,
    MENU_EFOV_PREPARE,
    MENU_EFOV_CAPTURE,
    MENU_EFOV_VIEW,
    MENU_EFOV_REVIEW,
    MENU_SYSTEM
  };

  void set_size(int width, int height);
  void initialize(GtkBox* box);

  void show_menu(EnumMenuType menu_type);
  void notebook_changed(unsigned int page_num);

private:
  void initialize_notebook();
  void update_label(EnumMenuType menu_type);

private:
  int m_width;
  int m_height;

  GtkLabel* m_label;
  GtkNotebook* m_notebook;

  Menu2D*             m_menu_2d;
  MenuM*              m_menu_m;
  MenuPW*             m_menu_pw;
  MenuCW*             m_menu_cw;
  MenuCFM*            m_menu_cfm;
  MenuMeasure2D*      m_menu_measure2d;
  MenuCalc*           m_menu_calc;
  MenuNote*           m_menu_note;
  MenuBodyMark*       m_menu_bodymark;
  MenuReview*         m_menu_review;
  MenuBiopsy*         m_menu_biopsy;
  MenuBiopsyBracket*  m_menu_biopsybracket;
  MenuBiopsyVerify*   m_menu_biopsyverify;
  MenuSystem*         m_menu_system;
  MenuEFOV*           m_menu_efov;
};

#endif

/*

    EMenuType GetMenuType(void);
    bool GetMenuVisible() {
        return m_menuVisbible;
    }
    void SwitchMenu(EMenuType type);
    EMenuType GetNotebookType(void);



    void UpdateLabel(void);
    void UpdateSubMenu(void);

   void GetMenuIndex(int &index);
*/