#ifndef APP_SRC_MAIN_CPP_COMMON_EVENT_EVENTBUS_HPP_
#define APP_SRC_MAIN_CPP_COMMON_EVENT_EVENTBUS_HPP_

#include "Event.hpp"
#include "EventType.hpp"
#include <functional>
#include <list>
#include <map>

using std::function;
using std::list;
using std::map;
using Subscriber = function<void(Event *)>;
using SubMap = map<EventType, list<Subscriber> *>;

class EventBus {
private:
  SubMap subMap;

public:
  EventBus();
  void publish(Event *);
  void subcribe(EventType, Subscriber);
};

#endif // APP_SRC_MAIN_CPP_COMMON_EVENT_EVENTBUS_HPP_
