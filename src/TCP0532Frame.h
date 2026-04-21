// src/TCP0532Frame.h v1
#pragma once

#include <stddef.h>
#include <stdint.h>

bool tcp0532BuildHostFrame(const uint8_t* payload,
                           size_t payloadLen,
                           uint8_t* frame,
                           size_t frameCapacity,
                           size_t* frameLen);
// src/TCP0532Frame.h v1