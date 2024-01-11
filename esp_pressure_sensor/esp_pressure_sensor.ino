/*
 * Simple code snippet for reading Amphenol
 * Pressure sensors with I2C output such as 
 * the NPA Series of Surface-Mount Pressure
 * Sensors NPA-700 and NPA-730.
 * 
 * This basic snippet will likely work for
 * similar sensors of other brands also.
 * I used NPA-730B-05WD to test this. It's
 * not an Arduino Library, but that's also
 * not required since the part is simple.
 */

#include "Wire.h"

byte data[4];
int combined = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // Read just the pressure
  Wire.requestFrom(0x28, 2);
  data[0] = Wire.read();
  data[1] = Wire.read();
  combined = (data[0] << 8) | data[1];
  combined -= 8200; // Compensate
  Serial.print(combined,DEC);

  // Read the pressure & temp (but print only temp)
  Wire.requestFrom(0x28, 4);
  data[0] = Wire.read();
  data[1] = Wire.read();
  data[2] = Wire.read();
  data[3] = Wire.read();
  combined = (data[2] << 8) | data[3];
  Serial.print(" : ");
  Serial.println(combined,DEC);

  delay(100);
}
