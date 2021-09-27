#ifndef EVENT_H
#define EVENT_H

#include "EventType.hpp"

class Event {
public:
    virtual EventType type() = 0;
};

#endif // EVENT_H
