/*
Code to test RFAutoMaTE.
Ph.D. José Miguel Algarín Guisado
mriLab, i3M, CSIC, Valencia, Spain

This code should blink all the relays secuentially. The user should see leds

*/

// Number of digital outputs
const int numOutputs = 16;

// Define the digital output pins
int outputPins[numOutputs] = {23, 31, 29, 27, 25, 41, 39, 37, 35, 33, 43, 51, 49, 47, 45, 53};

// Time delay for blinking in milliseconds
const int blinkDelay = 500;

void setup() {
  // Set all digital output pins as OUTPUT
  for (int i = 0; i < numOutputs; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
}

void loop() {
  // Blink each output one by one
  for (int i = 0; i < numOutputs; i++) {
    digitalWrite(outputPins[i], HIGH);  // Turn on
    delay(blinkDelay);
    digitalWrite(outputPins[i], LOW);   // Turn off
    delay(blinkDelay);
  }
}