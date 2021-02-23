// This sketch demonstrates using a OneShot to turn on an LED for
// (at least) 1 second whenever a pushbutton is pressed.  Because
// the OneShot is retriggerable, the 1 second interval begins
// when the button is released.  This action also provides a
// debounce on the button push.

#include <Arduino.h>

#include <OneShot.h>

// Create a OneShot with a 1 second timeout interval.
OneShot oneshot(1000);

// Connect a momentary normally-open pushbutton
// between GPIO pin 3 and ground.  Pushing the button will
// cause the input to go LOW.
const byte PB_PIN = 3;

// Connect an LED and series resistor, say 330 or 470 ohms,
// between GPIO pin 9 and ground.  LED anode (long pin) points
// towards GPIO pin, and cathode (short pin) points towards ground.
const byte LED_PIN = 9;

void setup() {

  // Set up the GPIO pins.
  pinMode(PB_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  
}

void loop() {

  // Update the oneshot's internal state, including advancing
  // its internal timer.
  oneshot.update();
  
  if (digitalRead(PB_PIN) == LOW) {
    // Button is pushed, trigger the oneshot.
    oneshot.trigger();
  }

  // Turn on the LED if oneshot is triggered.
  digitalWrite(LED_PIN, oneshot.isTriggered() ? HIGH : LOW);
  
}
