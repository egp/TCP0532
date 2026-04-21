#include "TCP0532.h"

TCP0532::TCP0532()
    : wire_(nullptr), i2cAddress_(TCP0532_DEFAULT_I2C_ADDRESS), lastError_(nullptr), ready_(false) {}

bool TCP0532::begin(TwoWire& wire) {
  wire_ = &wire;
  ready_ = false;
  lastError_ = nullptr;

  if (!configureI2C(i2cAddress_)) {
    return false;
  }

  ready_ = true;
  return true;
}

bool TCP0532::configureI2C(uint8_t address) {
  if (address == 0) {
    setError("invalid I2C address");
    return false;
  }

  i2cAddress_ = address;
  return true;
}

bool TCP0532::isReady() const {
  return ready_;
}

const char* TCP0532::lastError() const {
  return (lastError_ != nullptr) ? lastError_ : "";
}

uint8_t TCP0532::i2cAddress() const {
  return i2cAddress_;
}

void TCP0532::setError(const char* message) {
  lastError_ = message;
  ready_ = false;
}
