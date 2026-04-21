#pragma once

#include <Arduino.h>
#include <Wire.h>

static constexpr uint8_t TCP0532_DEFAULT_I2C_ADDRESS = 0x24;

class TCP0532 {
 public:
  TCP0532();

  bool begin(TwoWire& wire = Wire);
  bool configureI2C(uint8_t address = TCP0532_DEFAULT_I2C_ADDRESS);

  bool isReady() const;
  const char* lastError() const;
  uint8_t i2cAddress() const;

 private:
  void setError(const char* message);

  TwoWire* wire_;
  uint8_t i2cAddress_;
  const char* lastError_;
  bool ready_;
};
