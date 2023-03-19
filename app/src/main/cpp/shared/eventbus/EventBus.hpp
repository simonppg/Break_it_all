#ifndef APP_SRC_MAIN_CPP_SHARED_EVENTBUS_EVENTBUS_HPP_
#define APP_SRC_MAIN_CPP_SHARED_EVENTBUS_EVENTBUS_HPP_

#include <functional>
#include <list>
#include <map>

#include "Event.hpp"
#include "EventType.hpp"

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

#endif // APP_SRC_MAIN_CPP_SHARED_EVENTBUS_EVENTBUS_HPP_
