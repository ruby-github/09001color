#ifndef __i2c_cgosgpio_h__
#define __i2c_cgosgpio_h__

#include <Cgos.h>

class I2CCgosGpio {
public:
  I2CCgosGpio();
  ~I2CCgosGpio();

  bool write(unsigned char addr, unsigned char buf[], int len);
  bool read(unsigned char addr, unsigned char reg, unsigned char buf[], int len);

private:
  HCGOS m_hcgos;
};

#endif
