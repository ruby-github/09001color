#include <gtk/gtk.h>

#include "window/gtk_global.h"
#include "window/main_window.h"

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  i18n();

  MainWindow* instance = MainWindow::instance();
  instance->initialize();

  gtk_main();

  delete instance;
  instance = NULL;

  return 0;
}