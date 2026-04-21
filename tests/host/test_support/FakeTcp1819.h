// tests/host/test_support/FakeTcp1819.h v5
#pragma once

#include <stddef.h>
#include <stdint.h>

struct BBI2C {};

void fakeTcp1819Reset();
void fakeTcp1819SetBeginResult(bool result);
void fakeTcp1819SetWakeResult(bool result);
void fakeTcp1819SetWriteResult(bool result);
void fakeTcp1819SetReadResult(bool result);

void fakeTcp1819SetAckFrame(const uint8_t* data, size_t len);
void fakeTcp1819SetResponseFrame(const uint8_t* data, size_t len);

int fakeTcp1819BeginCallCount();
int fakeTcp1819WakeCallCount();
int fakeTcp1819WriteCallCount();
int fakeTcp1819ReadCallCount();

uint8_t fakeTcp1819LastWakeAddress();
uint8_t fakeTcp1819LastWriteAddress();
size_t fakeTcp1819LastWriteLength();
// tests/host/test_support/FakeTcp1819.h v5