// tests/host/test_WB_tcp0532_frame_encode.cpp v2
#include "TCP0532Frame.h"
#include "test_support/TestSupport.h"

#include <stddef.h>
#include <stdint.h>

int main() {
  {
    uint8_t frame[8] = {};
    size_t frameLen = 0;

    const uint8_t expected[] = {0x00, 0x00, 0xFF, 0x01, 0xFF, 0xD4, 0x2C, 0x00};

    EXPECT_TRUE(tcp0532BuildHostFrame(nullptr, 0, frame, sizeof(frame), &frameLen));
    EXPECT_EQ(static_cast<size_t>(8), frameLen);
    for (size_t i = 0; i < frameLen; ++i) {
      EXPECT_EQ(expected[i], frame[i]);
    }
  }

  {
    const uint8_t payload[] = {0x02};
    uint8_t frame[9] = {};
    size_t frameLen = 0;

    const uint8_t expected[] = {
        0x00, 0x00, 0xFF, 0x02, 0xFE, 0xD4, 0x02, 0x2A, 0x00};

    EXPECT_TRUE(
        tcp0532BuildHostFrame(payload, sizeof(payload), frame, sizeof(frame), &frameLen));
    EXPECT_EQ(static_cast<size_t>(9), frameLen);
    for (size_t i = 0; i < frameLen; ++i) {
      EXPECT_EQ(expected[i], frame[i]);
    }
  }

  {
    const uint8_t payload[] = {0x4A, 0x01, 0x00};
    uint8_t frame[11] = {};
    size_t frameLen = 0;

    const uint8_t expected[] = {
        0x00, 0x00, 0xFF, 0x04, 0xFC, 0xD4, 0x4A, 0x01, 0x00, 0xE1, 0x00};

    EXPECT_TRUE(
        tcp0532BuildHostFrame(payload, sizeof(payload), frame, sizeof(frame), &frameLen));
    EXPECT_EQ(static_cast<size_t>(11), frameLen);
    for (size_t i = 0; i < frameLen; ++i) {
      EXPECT_EQ(expected[i], frame[i]);
    }
  }

  return 0;
}
// tests/host/test_WB_tcp0532_frame_encode.cpp v2