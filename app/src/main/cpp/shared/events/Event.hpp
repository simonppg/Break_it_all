#ifndef APP_SRC_MAIN_CPP_SHARED_EVENTS_EVENT_HPP_
#define APP_SRC_MAIN_CPP_SHARED_EVENTS_EVENT_HPP_

#include "EventType.hpp"

class Event {
public:
  virtual ~Event() {}
  virtual EventType type() = 0;
};

#endif // APP_SRC_MAIN_CPP_SHARED_EVENTS_EVENT_HPP_
