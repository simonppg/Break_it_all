#ifndef APP_SRC_MAIN_CPP_COMMON_EVENT_EVENTBUS_HPP_
#define APP_SRC_MAIN_CPP_COMMON_EVENT_EVENTBUS_HPP_

#include "EventType.hpp"
#include "Event.hpp"
#include <functional>
#include <map>
#include <list>

using std::map;
using std::hash;
using std::unordered_map;
using std::function;
using std::list;
using Subscriber = function<void(Event *)>;
using SubMap = map<EventType, list<Subscriber> *>;

class EventBus {
private:
  SubMap subMap;
  // map <int, int> map1;
public:
  EventBus();
  void publish(Event *);
  void subcribe(EventType, Subscriber);
};

#endif // APP_SRC_MAIN_CPP_COMMON_EVENT_EVENTBUS_HPP_
