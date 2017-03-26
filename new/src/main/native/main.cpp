#include <gtk/gtk.h>

#include "view/gtk_global.h"
#include "view/main_window.h"

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  i18n_initialize();
  global_initialize();

  MainWindow* instance = MainWindow::instance();
  instance->initialize();

  gtk_main();

  delete instance;
  instance = NULL;

  global_free();

  return 0;
}