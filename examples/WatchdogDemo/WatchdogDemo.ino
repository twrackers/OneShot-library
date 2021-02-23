// This sketch mimics the action of a watchdog timer.
//
// A hardware watchdog timer is an electronic timer that is used to
// detect and recover from computer malfunctions. During normal operation,
// the computer regularly resets the watchdog timer to prevent it from
// elapsing, or "timing out". If, due to a hardware fault or program error,
// the computer fails to reset the watchdog, the timer will elapse and
// generate a timeout signal. The timeout signal is used to initiate
// corrective action or actions. The corrective actions typically include
// placing the computer system in a safe state or restarting the system.
//
// In this sketch, a OneShot object simulates the watchdog timer.  A OneShot
// object is in an off state until it is triggered.  Once triggered, the
// OneShot goes to an on state for a preset time period, then returns to its
// off state.  If it is triggered again while already on, its timer gets
// restarted, extending the on time.  As long as the OneShot keeps
// getting triggered before it times out, it will remain on.
//
// Whenever the watchdog timer is timed out (not triggered), the built-in
// LED will be lit up.  So as long as the watchdog doesn't time out, the LED
// will remain off.

#include <Arduino.h>

#include <OneShot.h>
#include <StateMachine.h>

// Random number generator will be sampled by 'pacer' at 100 Hz (every 10 msec).
StateMachine pacer(10, true);

// When watchdog is triggered, it will remain in on state for 250 msec, then
// return to its off state.  If it's triggered while in its on state, the
// 250 msec timer will restart, extending the on state.
OneShot watchdog(250);

void setup() {
  // Put built-in LED pin in output mode.
  pinMode(LED_BUILTIN, OUTPUT);
  // LED will remain off as long as watchdog is in on (triggered) state.
  digitalWrite(LED_BUILTIN, watchdog.isTriggered() ? LOW : HIGH);
}

void loop() {
  
  // If it's time to update the watchdog...
  if (watchdog.update()) {
    // ... update the built-in LED from the watchdog state.
    digitalWrite(LED_BUILTIN, watchdog.isTriggered() ? LOW : HIGH);
  }
  
  // Is it time to update the pacer?
  // If so, does the random number generator return 0?
  // It will do so on the average 10% of the time.
  // The watchdog will time out if 250 msec (25 samples at 10 msec per)
  // passes without the random number generator returning a zero.
  if (pacer.update() && (random(10) == 0)) {
    // (Re)trigger the watchdog.
    watchdog.trigger();
  }
  
}
