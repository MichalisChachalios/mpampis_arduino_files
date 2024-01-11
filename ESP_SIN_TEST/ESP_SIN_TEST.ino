#include <Arduino.h>
#include <math.h>

const int amplitude = 50;  // Adjust the amplitude of the sine wave
const float frequency = 1.0;  // Adjust the frequency of the sine wave
const int offset = 128;  // Offset to make the sine wave oscillate around a midpoint

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (float i = 0; i < 360; i += 5) {  // Iterate from 0 to 360 degrees
    float radians = i * (PI / 180.0);  // Convert degrees to radians
    int value = int(amplitude * sin(frequency * radians) + offset);  // Calculate sine value
    
    // Print the sine wave value to the Serial Monitor
    Serial.println(value);

    delay(50);  // Adjust the delay to control the speed of the sine wave
  }
}
