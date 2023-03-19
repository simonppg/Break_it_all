#include "EventBus.hpp"
#include <iostream>
#include <utility>

using std::pair;

EventBus::EventBus() {
  // subMap = new SubMap;
}

void EventBus::publish(Event *event) {
  EventType eventType = event->type();

  if (subMap.find(eventType) == subMap.end()) {
    return;
  }

  for (auto subscriber : *subMap[eventType]) {
    subscriber(event);
  }
}

void EventBus::subcribe(EventType eventType, Subscriber subscriber) {
  if (subMap.find(eventType) == subMap.end()) {
    std::cout << "Not Found";
    list<Subscriber> *aList = new list<Subscriber>;
    aList->push_back(subscriber);
    // subMap[eventType] = aList;
    subMap.insert(pair<EventType, list<Subscriber> *>(eventType, aList));
  } else {
    std::cout << "Found";
    list<Subscriber> *subscribers = subMap[eventType];
    subscribers->push_back(subscriber);
  }
}
