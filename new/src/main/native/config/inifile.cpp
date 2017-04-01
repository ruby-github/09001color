#include "config/inifile.h"
#include "utils/utils.h"

using namespace std;

IniFile::IniFile(const string file, const bool create) {
  m_file = get_resource_file(file);
  m_keyfile = NULL;

  if (create) {
    if (!g_file_test(m_file.c_str(), G_FILE_TEST_EXISTS)) {
      g_build_filename(m_file.c_str(), NULL);
    }
  }

  if (g_file_test(m_file.c_str(), G_FILE_TEST_EXISTS)) {
    m_keyfile =g_key_file_new();

    if (g_key_file_load_from_file(m_keyfile, m_file.c_str(), G_KEY_FILE_NONE, NULL) != TRUE) {
      g_key_file_free(m_keyfile);

      m_keyfile = NULL;
    }
  }
}

IniFile::~IniFile() {
  if (m_keyfile != NULL) {
    g_key_file_free(m_keyfile);

    m_keyfile = NULL;
  }
}

string IniFile::get_string(const string group, const string key) {
  string value = "";

  if (m_keyfile != NULL) {
    gchar* val = g_key_file_get_string(m_keyfile, group.c_str(), key.c_str(), NULL);

    if (val != NULL) {
      value = val;
    }
  }

  return value;
}

int IniFile::get_int(const string group, const string key) {
  int value = 0;

  if (m_keyfile != NULL) {
    value = g_key_file_get_integer(m_keyfile, group.c_str(), key.c_str(), NULL);
  }

  return value;
}

double IniFile::get_double(const string group, const string key) {
  double value = 0.0;

  if (m_keyfile != NULL) {
    value = g_key_file_get_double(m_keyfile, group.c_str(), key.c_str(), NULL);
  }

  return value;
}

bool IniFile::get_bool(const string group, const string key) {
  bool value = false;

  if (m_keyfile != NULL) {
    if (g_key_file_get_boolean(m_keyfile, group.c_str(), key.c_str(), NULL) == TRUE) {
      value = true;
    }
  }

  return value;
}

void IniFile::set_string(const string group, const string key, const string value) {
  if (m_keyfile != NULL) {
    g_key_file_set_string(m_keyfile, group.c_str(), key.c_str(), value.c_str());
  }
}

void IniFile::set_int(const string group, const string key, const int value) {
  if (m_keyfile != NULL) {
    g_key_file_set_integer(m_keyfile, group.c_str(), key.c_str(), value);
  }
}

void IniFile::set_double(const string group, const string key, const double value) {
  if (m_keyfile != NULL) {
    g_key_file_set_double(m_keyfile, group.c_str(), key.c_str(), value);
  }
}

void IniFile::set_bool(const string group, const string key, const bool value) {
  if (m_keyfile != NULL) {
    if (value) {
      g_key_file_set_boolean(m_keyfile, group.c_str(), key.c_str(), TRUE);
    } else {
      g_key_file_set_boolean(m_keyfile, group.c_str(), key.c_str(), FALSE);
    }
  }
}