#include "device/i2c_interface.h"
#include "utils/utils.h"

#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>

I2CInterface::I2CInterface() {
  m_fd = open("/dev/i2c-1", O_RDWR);

  if (m_fd < 0) {
    logger("open i2c device fail.");
  }
}

I2CInterface::~I2CInterface() {
  if (m_fd >= 0) {
    close(m_fd);
  }
}

bool I2CInterface::write(unsigned char addr, unsigned char buf[], int len) {
  i2c_msg msgs[1];

  msgs[0].addr = addr;
  msgs[0].flags = 0;
  msgs[0].len = len + 1;
  msgs[0].buf = buf;

  i2c_rdwr_ioctl_data ioctl_data;

  ioctl_data.nmsgs = 1;
  ioctl_data.msgs = msgs;

  if (ioctl(m_fd, I2C_RDWR, (unsigned long)&ioctl_data) == 0) {
    return true;
  } else {
    return false;
  }
}

bool I2CInterface::read(unsigned char addr, unsigned char reg, unsigned char buf[], int len) {
  unsigned char tmp_reg = reg;

  i2c_msg msgs[2];

  msgs[0].addr = addr;
  msgs[0].flags = 0;
  msgs[0].len = 1;
  msgs[0].buf = &tmp_reg;

  msgs[1].addr = addr;
  msgs[1].flags = I2C_M_RD;
  msgs[1].len = 1;
  msgs[1].buf = buf;

  i2c_rdwr_ioctl_data ioctl_data;

  ioctl_data.nmsgs = 2 ;
  ioctl_data.msgs = msgs;

  if (ioctl(m_fd, I2C_RDWR, (unsigned long)&ioctl_data) == 0) {
    return true;
  } else {
    return false;
  }
}
