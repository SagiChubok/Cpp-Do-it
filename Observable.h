#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"

#include <QList>

/*--------------------------------------------------------------------

  Description: Any object whose state may be of interest, and in whom
               another object may register an interest.

---------------------------------------------------------------------*/

class Observable
{
public:
    virtual void addObserver(Observer *o);

    virtual void removeObserver(Observer *o);

    virtual void notify();

private:
    QList<Observer*> observers;
};

#endif // OBSERVABLE_H
