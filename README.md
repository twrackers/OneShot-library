# OneShot-library
This Arduino library is derived from my StateMachine library, and creates a one-shot or mono-stable action.
A one-shot is normally "off" until it receives a "trigger", which changes the one-shot to its "on" state.  After a preset time has elapsed since the trigger, the one-shot will return to its "off" state.  This implementation of a one-shot is *retriggerable*, such that if it is triggered before it has returned to its off state, then the timing period will be restarted from that point, extending the time the one-shot is on.
