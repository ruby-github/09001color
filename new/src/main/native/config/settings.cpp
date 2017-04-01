#include "config/settings.h"
#include "config/inifile.h"
#include "config.h"

using namespace std;

string get_settings_hospital() {
  IniFile inifile(SETTINGS_SYSSETTING);

  return inifile.get_string("GeneralSetting", "Hospital");
}

void set_settings_hospital(const string hospital) {
  IniFile inifile(SETTINGS_SYSSETTING);

  inifile.set_string("GeneralSetting", "Hospital", hospital);
}