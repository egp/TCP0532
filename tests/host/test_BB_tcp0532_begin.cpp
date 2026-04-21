// tests/host/test_BB_tcp0532_begin.cpp v2
#include "TCP0532.h"
#include "test_support/FakeTcp1819.h"
#include "test_support/TestSupport.h"

int main() {
  TCP0532 dut;
  BBI2C bus{};

  EXPECT_TRUE(dut.begin(bus));
  EXPECT_TRUE(dut.isReady());
  EXPECT_STREQ("", dut.lastError());
  EXPECT_EQ(TCP0532_DEFAULT_I2C_ADDRESS, dut.i2cAddress());

  return 0;
}
// tests/host/test_BB_tcp0532_begin.cpp v2