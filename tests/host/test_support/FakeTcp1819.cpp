// tests/host/test_support/FakeTcp1819.cpp v2
#include "FakeTcp1819.h"

namespace {
bool gBeginResult = true;
bool gWakeResult = true;
int gBeginCallCount = 0;
int gWakeCallCount = 0;
uint8_t gLastWakeAddress = 0x00;
}

void fakeTcp1819Reset() {
  gBeginResult = true;
  gWakeResult = true;
  gBeginCallCount = 0;
  gWakeCallCount = 0;
  gLastWakeAddress = 0x00;
}

void fakeTcp1819SetBeginResult(bool result) {
  gBeginResult = result;
}

void fakeTcp1819SetWakeResult(bool result) {
  gWakeResult = result;
}

int fakeTcp1819BeginCallCount() {
  return gBeginCallCount;
}

int fakeTcp1819WakeCallCount() {
  return gWakeCallCount;
}

uint8_t fakeTcp1819LastWakeAddress() {
  return gLastWakeAddress;
}

bool tcp0532HostBeginBus(BBI2C& bus) {
  (void)bus;
  ++gBeginCallCount;
  return gBeginResult;
}

bool tcp0532HostWakeDevice(BBI2C& bus, uint8_t address) {
  (void)bus;
  ++gWakeCallCount;
  gLastWakeAddress = address;
  return gWakeResult;
}
// tests/host/test_support/FakeTcp1819.cpp v2