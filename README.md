# OneShot #

The `OneShot` class is derived from the `StateMachine` class ([https://github.com/twrackers/StateMachine-library](https://github.com/twrackers/StateMachine-library)), and creates a one-shot or mono-stable action.
A one-shot is normally "off" until it receives a "trigger", which changes the one-shot to its "on" state.  After a preset time has elapsed since the trigger, the one-shot will return to its "off" state.  This implementation of a one-shot is *retriggerable*, meaning if it is triggered before it has returned to its off state, then the timing period will be restarted from that point, extending the time the one-shot is on.

Because a one-shot is retriggerable, it can be used as a "watchdog timer" by giving it a time period longer than the expected period between consecutive events of some type.  In normal operation, every time the event occurs it should retrigger the watchdog, preventing it from ever turning off.  If other code examines the state of the watchdog and sees that it is off, that means the periodic events either stopped occurring or were delayed beyond the watchdog's timeout period.

## Examples ##

## Dependencies ##

The `OneShot` library requires installation of the `StateMachine` library.

## Installation ##

Instructions for installing the *OneShot* library can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/OneShot-library/blob/main/INSTALL.md](https://github.com/twrackers/OneShot-library/blob/main/INSTALL.md).