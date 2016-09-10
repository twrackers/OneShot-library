#ifndef _ONE_SHOT__H_
#define _ONE_SHOT__H_

#include <StateMachine.h>

class OneShot : public StateMachine
{
  private:
    const unsigned int m_delay;
    unsigned long m_timeout;
    bool m_triggered;
    
  public:
    OneShot(const unsigned int dly);
    virtual bool update();
    void trigger();
    bool isTriggered() const;    
};

#endif
