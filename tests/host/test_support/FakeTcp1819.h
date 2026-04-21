// tests/host/test_support/FakeTcp1819.h v3
#pragma once

#include <stdint.h>

struct BBI2C {};

void fakeTcp1819Reset();
void fakeTcp1819SetBeginResult(bool result);
void fakeTcp1819SetWakeResult(bool result);

int fakeTcp1819BeginCallCount();
int fakeTcp1819WakeCallCount();
uint8_t fakeTcp1819LastWakeAddress();
// tests/host/test_support/FakeTcp1819.h v3