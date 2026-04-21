// tests/host/test_BB_tcp0532_wake.cpp v1
#include "TCP0532.h"
#include "test_support/FakeTcp1819.h"
#include "test_support/TestSupport.h"

int main() {
  {
    TCP0532 dut;

    fakeTcp1819Reset();
    EXPECT_FALSE(dut.wake());
    EXPECT_STREQ("not begun", dut.lastError());
    EXPECT_FALSE(dut.isReady());
    EXPECT_EQ(0, fakeTcp1819WakeCallCount());
  }

  {
    TCP0532 dut;
    BBI2C bus{};

    fakeTcp1819Reset();
    fakeTcp1819SetBeginResult(true);
    fakeTcp1819SetWakeResult(true);

    EXPECT_TRUE(dut.begin(bus, 0x28));
    EXPECT_TRUE(dut.wake());
    EXPECT_TRUE(dut.isReady());
    EXPECT_STREQ("", dut.lastError());
    EXPECT_EQ(1, fakeTcp1819WakeCallCount());
    EXPECT_EQ(static_cast<uint8_t>(0x28), fakeTcp1819LastWakeAddress());
  }

  return 0;
}
// tests/host/test_BB_tcp0532_wake.cpp v1
