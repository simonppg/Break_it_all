#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

#include "Event.hpp"

class EventFactory {
public:
    Event cursorPositionChanged(double xPos, double yPos);
};

#endif //EVENT_FACTORY_H
