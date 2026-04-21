#include <Wire.h>
#include "src/TCP0532.h"

TCP0532 nfc;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  Wire.begin();

  Serial.println();
  Serial.println(F("TCP0532 ReaderAlive"));

  if (!nfc.begin(Wire)) {
    Serial.print(F("begin failed: "));
    Serial.println(nfc.lastError());
    return;
  }

  Serial.print(F("configured I2C address: 0x"));
  if (nfc.i2cAddress() < 0x10) {
    Serial.print('0');
  }
  Serial.println(nfc.i2cAddress(), HEX);
  Serial.println(F("library skeleton is alive; PN532 transport not yet implemented"));
}

void loop() {
  delay(1000);
}
