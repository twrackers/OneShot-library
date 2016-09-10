#include "OneShot.h"

OneShot::OneShot(const unsigned int dly) :
  StateMachine(1, true), m_delay(dly), m_timeout(0L), m_triggered(false)
{
}

bool OneShot::update()
{
  if (StateMachine::update()) {
    if (m_triggered && (millis() >= m_timeout)) {
      m_triggered = false;
    }
  }
}

void OneShot::trigger()
{
  m_timeout = millis() + m_delay;
  m_triggered = true;
}

bool OneShot::isTriggered() const{
  return m_triggered;
}
