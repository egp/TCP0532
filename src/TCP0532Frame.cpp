// src/TCP0532Frame.cpp v2
#include "TCP0532Frame.h"

bool tcp0532BuildHostFrame(const uint8_t* payload,
                           size_t payloadLen,
                           uint8_t* frame,
                           size_t frameCapacity,
                           size_t* frameLen) {
  if (frameLen == nullptr) {
    return false;
  }
  *frameLen = 0;

  if (frame == nullptr) {
    return false;
  }
  if (payloadLen > 0 && payload == nullptr) {
    return false;
  }

  const size_t totalFrameLen = payloadLen + 8;
  if (frameCapacity < totalFrameLen) {
    return false;
  }

  const uint8_t len = static_cast<uint8_t>(payloadLen + 1);
  const uint8_t lcs = static_cast<uint8_t>(0u - len);

  frame[0] = 0x00;
  frame[1] = 0x00;
  frame[2] = 0xFF;
  frame[3] = len;
  frame[4] = lcs;
  frame[5] = 0xD4;

  uint8_t sum = 0xD4;
  for (size_t i = 0; i < payloadLen; ++i) {
    frame[6 + i] = payload[i];
    sum = static_cast<uint8_t>(sum + payload[i]);
  }

  frame[6 + payloadLen] = static_cast<uint8_t>(0u - sum);
  frame[7 + payloadLen] = 0x00;

  *frameLen = totalFrameLen;
  return true;
}
// src/TCP0532Frame.cpp v2