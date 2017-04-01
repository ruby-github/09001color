#ifndef __inifile_h__
#define __inifile_h__

#include <glib.h>
#include <string>

class IniFile {
public:
  IniFile(const std::string file, const bool create = true);
  ~IniFile();

  std::string get_string(const std::string group, const std::string key);
  int get_int(const std::string group, const std::string key);
  double get_double(const std::string group, const std::string key);
  bool get_bool(const std::string group, const std::string key);

  void set_string(const std::string group, const std::string key, const std::string value);
  void set_int(const std::string group, const std::string key, const int value);
  void set_double(const std::string group, const std::string key, const double value);
  void set_bool(const std::string group, const std::string key, const bool value);

private:
  std::string m_file;
  GKeyFile* m_keyfile;
};

#endif