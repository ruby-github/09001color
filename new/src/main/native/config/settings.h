#ifndef __settings_h__
#define __settings_h__

#include <string>

// SysSetting

std::string get_settings(const std::string file, const std::string group, const std::string name);
void set_settings(const std::string file, const std::string group, const std::string name, const std::string value);

std::string get_settings_sys_setting(const std::string group, const std::string name);
void set_settings_sys_setting(const std::string group, const std::string name, const std::string value);

#endif
