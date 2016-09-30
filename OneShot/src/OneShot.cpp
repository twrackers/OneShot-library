#include "OneShot.h"

OneShot::OneShot(const unsigned int dly) :
  StateMachine(1, true), m_delay(dly), m_timeout(0L), m_triggered(false)
{
}

bool OneShot::update()
{
  if (StateMachine::update()) {
    // If in triggered state and timeout period has elapsed,
    // turn off triggered state.
    if (m_triggered && ((millis() - m_timeout) >= 0)) {
      m_triggered = false;
    }
    return true;
  }
  return false;
}

void OneShot::trigger()
{
  // Set time of timeout.
  m_timeout = millis() + m_delay;
  // Set triggered state.
  m_triggered = true;
}

bool OneShot::isTriggered() const
{
  // Return triggered state.
  return m_triggered;
}
