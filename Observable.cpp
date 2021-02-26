#include "Observable.h"

void Observable::addObserver(Observer *o){
    observers.push_back(o);
}

void Observable::removeObserver(Observer *o){
    observers.removeOne(o);
}

void Observable::notify(){
    for(Observer* observer: observers)
        observer->update();
}
