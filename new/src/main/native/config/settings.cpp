#include "config/settings.h"
#include "config/inifile.h"
#include "config.h"

using namespace std;

string get_settings(const string file, const string group, const string name) {
  IniFile inifile(file);

  return inifile.get_string(group, name);
}

void set_settings(const string file, const string group, const string name, const string value) {
  IniFile inifile(file);

  inifile.set_string(group, name, value);
}

string get_settings_sys_setting(const string group, const string name) {
  return get_settings(SETTINGS_SYS_SETTING, group, name);
}

void set_settings_sys_setting(const string group, const string name, const string value) {
  set_settings(SETTINGS_SYS_SETTING, group, name, value);
}
