#ifndef COMMON_EVENT_HPP
#define COMMON_EVENT_HPP

#include "EventType.hpp"

class Event {
public:
    virtual EventType type() = 0;
};

#endif // COMMON_EVENT_HPP
