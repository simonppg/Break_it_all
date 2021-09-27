#ifndef KEY_PRESSED_H
#define KEY_PRESSED_H

#include "Event.hpp"

class KeyPressed : public Event {
public:
    EventType type();
};

#endif //KEY_PRESSED_H
