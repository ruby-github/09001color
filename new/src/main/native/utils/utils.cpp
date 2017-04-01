#include "utils/utils.h"

#include <unistd.h>

using namespace std;

string g_application_path = "";

const string get_resource_file(const string name) {
  if (g_application_path.empty()) {
    const int MAX_PATH = 1024;
    char buf[MAX_PATH] = {0};

    int count = readlink("/proc/self/exe", buf, MAX_PATH);

    if (count > 0 && count < MAX_PATH) {
      buf[count] = '\0';

      string filename = string(buf);
      size_t pos = filename.find_last_of('/');

      if (pos != string::npos) {
        g_application_path = filename.substr(0, pos);
      }
    } else {
      g_application_path = ".";
    }
  }

  return g_application_path + "/" + name;
}