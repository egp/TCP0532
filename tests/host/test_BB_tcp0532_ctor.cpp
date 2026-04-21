// tests/host/test_BB_tcp0532_ctor.cpp v1
#include "TCP0532.h"
#include "test_support/FakeTcp1819.h"
#include "test_support/TestSupport.h"

int main() {
  TCP0532 dut;

  EXPECT_FALSE(dut.isReady());
  EXPECT_STREQ("", dut.lastError());
  EXPECT_EQ(TCP0532_DEFAULT_I2C_ADDRESS, dut.i2cAddress());

  return 0;
}
// tests/host/test_BB_tcp0532_ctor.cpp v1