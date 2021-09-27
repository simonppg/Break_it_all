#ifndef KEY_PRESSED_H
#define KEY_PRESSED_H

#include "Event.hpp"
#include "Key.hpp"

class KeyPressed : public Event {
private:
    Key aKey;
    PressState aPressState;

public:
    KeyPressed(Key key, PressState pressState);

    EventType type();
    Key key();
    PressState pressState();
};

#endif //KEY_PRESSED_H
