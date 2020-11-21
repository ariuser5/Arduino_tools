// This an example on how to use RotaryEncoder library.

#include "RotaryEncoder.h"

// Define the physical component output pins
#define outputA 2
#define outputB 3

// Declare the encoder instance;
RotaryEncoder encoder(outputA, outputB);

// The encoder position will be recorded 
// but it won't be allowed to exceed certain limits
int position = 0;
int maxPosition = 20;
int minPosition = 0;

// The time in milliseconds that have past since start of the execution
unsigned long timeInMillis = 0;


void setup() {
  // Begin session of listening the serial input from micro controller
  Serial.begin(9600);

  // Read current time;
  timeInMillis = millis();
}

void loop() {

  // Read signal from the encoder.
  // The method needs to receive the value of timeInMillis
  // in order to debounce the encoder's signal.
  int dir = encoder.readSignal(timeInMillis);

  if(dir != 0){

    // Determine the intended position after signal is received
    int newPosition = position + dir;

    // Clamp the position within specified limits
    position = constrain(newPosition, minPosition, maxPosition);

    // Print the current position of the encoder
    Serial.print("Position: ");
    Serial.println(position);
  }

  // Update time value
  timeInMillis = millis();
}
