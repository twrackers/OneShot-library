// This sketch demonstrates using a OneShot to turn on an LED for
// 1 second whenever a pushbutton is pressed.  A OneShot by default
// is retriggerable, but this example disables that feature.
//
// NOTE: If the pushbutton is held down, the OneShot will appear to
// retrigger immediately after it times out.  This example is intended
// to be controlled by momentary button presses of less than 1 second.

#include <Arduino.h>

#include <OneShot.h>

// Create a OneShot with a 1 second timeout interval with retrigger
// disabled.
OneShot oneshot(1000, false);

// Connect a momentary normally-open pushbutton
// between GPIO pin 3 and ground.  Pushing the button will
// cause the input to go LOW.
const byte PB_PIN = 3;

// Output of OneShot is the built-in LED.
const byte LED_PIN = LED_BUILTIN;

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
