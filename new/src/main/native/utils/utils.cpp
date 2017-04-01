#include "utils/utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

string g_application_path = "";

const string to_string(const int value) {
  stringstream ss;
  ss << value;

  return ss.str();
}

const string to_string(const double value) {
  stringstream ss;
  ss << value;

  return ss.str();
}

const string to_string(const bool value) {
  string str = "false";

  if (value) {
    str = "true";
  }

  return str;
}

int to_int(const string str) {
  bool found = false;

  for (int i = 0; i < str.size(); i++) {
    char c = str[i];

    if (c >= '0' && c <= '9') {
      continue;
    }

    found = true;
  }

  int val = 0;

  if (!found) {
    val = atoi(str.c_str());
  }

  return val;
}

double to_double(const string str) {
  bool found = false;
  int dot = 0;

  for (int i = 0; i < str.size(); i++) {
    char c = str[i];

    if (c >= '0' && c <= '9') {
      continue;
    }

    if (c == '.') {
      dot += 1;

      continue;
    }

    found = true;
  }

  double val = 0.0;

  if (!found && dot <= 1) {
    val = atof(str.c_str());
  }

  return val;
}

bool to_bool(const string str) {
  bool val = false;

  if (str == "true") {
    val = true;
  }

  return val;
}

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