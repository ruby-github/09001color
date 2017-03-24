#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>

#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 768

#define MAINVIEW_MENU_HEIGHT      100
#define MAINVIEW_STATUS_HEIGHT    50

#define MAINVIEW_LEFT_WIDTH       200
#define MAINVIEW_RIGHT_WIDTH      200

#define MAINVIEW_LOGO_HEIGHT      100

#define MAINVIEW_PATIENT_HEIGHT   30
#define MAINVIEW_PLAYBACK_HEIGHT  100

#define MAINVIEW_TIME_WIDTH       100

#define LOCALE_PATH   "/usr/share/locale"
#define PACKAGE_NAME  "09001_lang"

#define GDKCOLOR_FOREGROUND "white"
#define GDKCOLOR_BACKGROUND "black" // "#2a2f3a"
#define GDKCOLOR_BUTTON "green"

#define MAX_PATH 1024
#define IMG_LOGO_FILE "res/logo.png"

extern std::string g_application_path;

#endif