#include "OneShot.h"

OneShot::OneShot(const unsigned int dly, const bool retriggerable) :
  StateMachine(1, true, true), m_delay(dly * 1000), m_timeout(0L),
  m_retriggerable(retriggerable), m_triggered(false)
{
}

bool OneShot::update()
{
  if (StateMachine::update()) {
    // If in triggered state and timeout period has elapsed,
    // turn off triggered state.
    if (m_triggered && ((long) (micros() - m_timeout) >= 0)) {
      m_triggered = false;
    }
    return true;
  }
  return false;
}

void OneShot::trigger()
{
  if (m_retriggerable || !m_triggered) {
      // Set time of timeout.
      m_timeout = micros() + m_delay;
      // Set triggered state.
      m_triggered = true;
  }
}

bool OneShot::isTriggered() const
{
  // Return triggered state.
  return m_triggered;
}

void OneShot::enableRetrigger(const bool enable)
{
  m_retriggerable = enable;
}

bool OneShot::retriggerEnabled() const
{
  return m_retriggerable;
}

void OneShot::clear() {
  m_triggered = false;
}
