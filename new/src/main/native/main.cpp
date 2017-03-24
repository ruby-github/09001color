#include <unistd.h>

#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include "config.h"
#include "view/mainview.h"

#include <iostream>

using namespace std;

string g_application_path = ".";

void i18n_initialize() {
  setlocale(LC_ALL, "");
  bindtextdomain(PACKAGE_NAME, LOCALE_PATH);
  bind_textdomain_codeset(PACKAGE_NAME, "UTF-8");
  textdomain(PACKAGE_NAME);
}

void set_application_path() {
  char buf[MAX_PATH] = {0};

  int count = readlink("/proc/self/exe", buf, MAX_PATH);

  if (count > 0 && count < MAX_PATH) {
    buf[count] = '\0';

    string filename = string(buf);
    size_t pos = filename.find_last_of('/');

    if (pos != string::npos) {
      g_application_path = filename.substr(0, pos);
    }
  }
}

int main(int argc, char *argv[]) {
  set_application_path();
  i18n_initialize();

  gtk_init(&argc, &argv);

  MainView* mainview = MainView::get_instance();
  mainview->initialize();
  mainview->show();

  gtk_main();

  return 0;
}
