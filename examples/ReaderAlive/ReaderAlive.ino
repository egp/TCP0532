// examples/ReaderAlive/ReaderAlive.ino v2
#include <TCP1819.h>
#include "src/TCP0532.h"

TCP0532 nfc;
BBI2C gI2C;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  Serial.println();
  Serial.println(F("TCP0532 ReaderAlive"));

  if (!nfc.begin(gI2C)) {
    Serial.print(F("begin failed: "));
    Serial.println(nfc.lastError());
    Serial.println(F("cycle-1 red stub is in place"));
    return;
  }

  Serial.print(F("configured I2C address: 0x"));
  if (nfc.i2cAddress() < 0x10) {
    Serial.print('0');
  }
  Serial.println(nfc.i2cAddress(), HEX);
}

void loop() {
  delay(1000);
}
// examples/ReaderAlive/ReaderAlive.ino v2