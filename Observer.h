#ifndef OBSERVER_H
#define OBSERVER_H

/*--------------------------------------------------------------------

  Description: Any object that wishes to be notified when the state
               of another object changes.

---------------------------------------------------------------------*/

class Observer
{
public:
    virtual void update() = 0;
};

#endif // OBSERVER_H
