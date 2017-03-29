#include "module/battery.h"

#define BATTERY_ADDR 0x0b
#define BATTERY_CHARGE 0x0d

Battery::Battery() {
}

Battery::~Battery() {
}

int Battery::capacity() {
  unsigned char capacity = 0;

  /*I2CInterface i2c;

  if (i2c.I2CRead(BATTERY_ADDR, BATTERY_CHARGE, 1, &capacity) < 0) {
    CgosGpioI2C cgosI2C;

    if (cgosI2C.I2CRead(BATTERY_ADDR, BATTERY_CHARGE, 1, &capacity) < 0) {
      g_logger("read battery capacity fail");
    }
  }*/

  capacity = 30;

  return capacity;
}