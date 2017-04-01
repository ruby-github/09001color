#ifndef __i2c_interface_h__
#define __i2c_interface_h__

class I2CInterface {
public:
  I2CInterface();
  ~I2CInterface();

  bool write(unsigned char addr, unsigned char buf[], int len);
  bool read(unsigned char addr, unsigned char reg, unsigned char buf[], int len);

private:
  int m_fd;
};

#endif
