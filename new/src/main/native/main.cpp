#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include "config.h"
#include "view/mainview.h"

#include <iostream>

using namespace std;

void i18n_initialize() {
  setlocale(LC_ALL, "");
  bindtextdomain(PACKAGE_NAME, LOCALE_PATH);
  bind_textdomain_codeset(PACKAGE_NAME, "UTF-8");
  textdomain(PACKAGE_NAME);
}

int main(int argc, char *argv[]) {
  i18n_initialize();

  gtk_init(&argc, &argv);

  MainView* mainview = MainView::get_instance();
  mainview->initialize();
  mainview->show();

  gtk_main();

  return 0;
}
