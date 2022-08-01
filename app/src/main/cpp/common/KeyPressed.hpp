#ifndef COMMON_KEY_PRESSED_HPP
#define COMMON_KEY_PRESSED_HPP

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

#endif // COMMON_KEY_PRESSED_HPP
