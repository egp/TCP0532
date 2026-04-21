// tests/host/test_BB_tcp0532_get_firmware_version.cpp v1
#include "TCP0532.h"
#include "test_support/FakeTcp1819.h"
#include "test_support/TestSupport.h"

int main() {
  {
    TCP0532 dut;
    uint32_t version = 0xFFFFFFFFu;

    fakeTcp1819Reset();

    EXPECT_FALSE(dut.getFirmwareVersion(version));
    EXPECT_EQ(static_cast<uint32_t>(0), version);
    EXPECT_STREQ("not begun", dut.lastError());
    EXPECT_FALSE(dut.isReady());
    EXPECT_EQ(0, fakeTcp1819WriteCallCount());
    EXPECT_EQ(0, fakeTcp1819ReadCallCount());
  }

  {
    TCP0532 dut;
    BBI2C bus{};
    uint32_t version = 0;

    const uint8_t ack[] = {0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00};
    const uint8_t response[] = {
        0x00, 0x00, 0xFF, 0x06, 0xFA, 0xD5, 0x03, 0x32, 0x01, 0x06, 0x07, 0xE8, 0x00};

    fakeTcp1819Reset();
    fakeTcp1819SetBeginResult(true);
    fakeTcp1819SetWriteResult(true);
    fakeTcp1819SetReadResult(true);
    fakeTcp1819SetAckFrame(ack, sizeof(ack));
    fakeTcp1819SetResponseFrame(response, sizeof(response));

    EXPECT_TRUE(dut.begin(bus, 0x28));
    EXPECT_TRUE(dut.getFirmwareVersion(version));
    EXPECT_EQ(static_cast<uint32_t>(0x32010607u), version);
    EXPECT_STREQ("", dut.lastError());
    EXPECT_TRUE(dut.isReady());
    EXPECT_EQ(1, fakeTcp1819WriteCallCount());
    EXPECT_EQ(2, fakeTcp1819ReadCallCount());
    EXPECT_EQ(static_cast<uint8_t>(0x28), fakeTcp1819LastWriteAddress());
    EXPECT_EQ(static_cast<size_t>(9), fakeTcp1819LastWriteLength());
  }

  return 0;
}
// tests/host/test_BB_tcp0532_get_firmware_version.cpp v1