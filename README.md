# OneShot #

The `OneShot` class is derived from the `StateMachine` class ([https://github.com/twrackers/StateMachine-library](https://github.com/twrackers/StateMachine-library)), and creates a one-shot or mono-stable action.
A one-shot is normally "off" until it receives a "trigger", which changes the one-shot to its "on" state.  After a preset time has elapsed since the trigger, the one-shot will return to its "off" state.  This implementation of a one-shot is *retriggerable*, meaning if it is triggered before it has returned to its off state, then the timing period will be restarted from that point, extending the time the one-shot is on.

Because a one-shot is retriggerable, it can be used as a "watchdog timer" by giving it a time period longer than the expected period between consecutive events of some type.  In normal operation, every time the event occurs it should retrigger the watchdog, preventing it from ever turning off.  If other code examines the state of the watchdog and sees that it is off, that means the periodic events either stopped occurring or were delayed beyond the watchdog's timeout period.

## Examples ##

The *OneShot* library includes a [`WatchdogDemo` sketch](https://github.com/twrackers/OneShot-library/blob/main/examples/WatchdogDemo/WatchdogDemo.ino) in the `examples` directory.  This sketch shows how the `OneShot` class can be used as a watchdog timer.  The sketch uses the `OneShot` class and the `StateMachine` class (which is used by the `OneShot` class anyway).

## Dependencies ##

The `OneShot` library requires installation of the `StateMachine` library.

## Installation ##

Instructions for installing the *OneShot* library can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/OneShot-library/blob/main/INSTALL.md](https://github.com/twrackers/OneShot-library/blob/main/INSTALL.md).

## API ##

### *OneShot(const unsigned int dly)* ###

The constructor creates an instance of a `OneShot` object with a specified timeout interval.

#### Arguments ####

- **dly: const unsigned int:** Timeout interval in milliseconds.  If **dly** milliseconds pass since the most recent trigger of the `OneShot`, it will switch from an on state (`true`) to off (`false`).

### *virtual bool update()* ###

Checks if it is time to update the state of the `OneShot` object.  This method should be called from within the Arduino sketch's `loop()` function.

#### Returns ####

- **bool:** `true` if it was time to update the object's internal state machine.  Usually can be ignored.

### *bool isTriggered() const* ###

Reads the current state of the `OneShot`.

#### Returns ####

- **bool:** `true` if `OneShot` has been triggered but not yet timed out, otherwise `false`.

