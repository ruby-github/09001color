#include "device/i2c_cgosgpio.h"
#include "utils/utils.h"

I2CCgosGpio::I2CCgosGpio() {
  m_hcgos = 0;

  bool initialize = true;

  if (!CgosLibInitialize()) {
    if (CgosLibInstall(1)) {
      logger("the CGOS driver has been installed");

      if (!CgosLibInitialize()) {
        initialize = false;

        logger("ERROR: still could not open driver, a reboot might be required!");
      }
    } else {
      initialize = false;

      logger("ERROR: can't install CGOS library");
    }
  }

  if (initialize) {
    if (CgosBoardOpen(0, 0, 0, &m_hcgos)) {
      logger("open CGOS board success");

      CgosI2CSetFrequency(m_hcgos, 0, 100000);
    } else {
      logger("ERROR: open CGOS board fail");
    }
  }
}

I2CCgosGpio::~I2CCgosGpio() {
  if (m_hcgos > 0) {
    CgosBoardClose(m_hcgos);
  }

  CgosLibUninitialize();
}

bool I2CCgosGpio::write(unsigned char addr, unsigned char buf[], int len) {
  if (m_hcgos > 0) {
    if (CgosI2CWrite(m_hcgos, 0, (addr << 1), buf, len)) {
      return true;
    } else {
      logger("CgosI2CWrite fail");

      return false;
    }
  } else {
    return false;
  }
}

bool I2CCgosGpio::read(unsigned char addr, unsigned char reg, unsigned char buf[], int len) {
  if (m_hcgos > 0) {
    unsigned char tmp_reg = reg;

    if (CgosI2CWriteReadCombined(m_hcgos, 0, (addr << 1), &tmp_reg, 1, buf, 1)) {
      return true;
    } else {
      logger("CgosI2CWriteRead fail");

      return false;
    }
  } else {
    return false;
  }
}
