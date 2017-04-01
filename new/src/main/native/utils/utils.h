#ifndef __utils_h__
#define __utils_h__

#include <string>

const std::string to_string(const int value);
const std::string to_string(const double value);
const std::string to_string(const bool value);

int to_int(const std::string str);
double to_double(const std::string str);
bool to_bool(const std::string str);

const std::string get_resource_file(const std::string name);

#endif