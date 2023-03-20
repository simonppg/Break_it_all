#ifndef APP_SRC_MAIN_CPP_SHARED_EVENTBUS_KEYPRESSED_HPP_
#define APP_SRC_MAIN_CPP_SHARED_EVENTBUS_KEYPRESSED_HPP_

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

#endif // APP_SRC_MAIN_CPP_SHARED_EVENTBUS_KEYPRESSED_HPP_
