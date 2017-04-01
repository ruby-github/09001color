#include "device/battery.h"
#include "device/i2c_cgosgpio.h"
#include "device/i2c_interface.h"
#include "utils/utils.h"

#define BATTERY_ADDR      0x0b
#define BATTERY_REG_ADDR  0x0d

Battery::Battery() {
}

Battery::~Battery() {
}

int Battery::capacity() {
  unsigned char capacity = 0;

  I2CInterface i2c;

  if (!i2c.read(BATTERY_ADDR, BATTERY_REG_ADDR, &capacity, 1)) {
    I2CCgosGpio cgos;

    if (!cgos.read(BATTERY_ADDR, BATTERY_REG_ADDR, &capacity, 1)) {
      logger("read battery capacity fail");
    }
  }

  return capacity;
}