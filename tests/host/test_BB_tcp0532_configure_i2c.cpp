// tests/host/test_BB_tcp0532_configure_i2c.cpp v1
#include "TCP0532.h"
#include "test_support/TestSupport.h"

int main() {
  {
    TCP0532 dut;

    EXPECT_TRUE(dut.configureI2C(0x28));
    EXPECT_EQ(static_cast<uint8_t>(0x28), dut.i2cAddress());
    EXPECT_STREQ("", dut.lastError());
    EXPECT_FALSE(dut.isReady());
  }

  {
    TCP0532 dut;

    EXPECT_FALSE(dut.configureI2C(0x00));
    EXPECT_EQ(TCP0532_DEFAULT_I2C_ADDRESS, dut.i2cAddress());
    EXPECT_STREQ("invalid i2c address", dut.lastError());
    EXPECT_FALSE(dut.isReady());
  }

  return 0;
}
// tests/host/test_BB_tcp0532_configure_i2c.cpp v1