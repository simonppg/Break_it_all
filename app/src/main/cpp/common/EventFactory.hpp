#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

#include "Event.hpp"
#include "Key.hpp"

class EventFactory {
public:
    Event* cursorPositionChanged(double xPos, double yPos);
    Event* keyPressed(Key key, PressState pressState);
};

#endif //EVENT_FACTORY_H
