#include "EventBus.hpp"
#include <iostream>
#include <utility>

using std::pair;

EventBus::EventBus() {
  // subMap = new SubMap;
}

void EventBus::publish(Event *event) {
  logEvent(event);
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

void EventBus::logEvent(Event *event) {
  EventType eventType = event->type();

  if (eventType == EventType::SURFACE_CHANGED) {
    // logger->logi("SURFACE_CHANGED");
    std::cout << "SURFACE_CHANGED";
  } else if (eventType == EventType::CURSOR_POSITION_CHANGED) {
    // logger->logi("CURSOR_POSITION_CHANGED");
    std::cout << "CURSOR_POSITION_CHANGED";
  } else if (eventType == EventType::KEY_PRESSED) {
    // logger->logi("KEY_PRESSED");
    std::cout << "KEY_PRESSED";
  } else if (eventType == EventType::SCREEN_TOUCHED) {
    // logger->logi("SCREEN_TOUCHED");
    std::cout << "SCREEN_TOUCHED";
  } else if (eventType == EventType::SURFACE_CHANGED) {
    // logger->logi("SURFACE_CHANGED");
    std::cout << "SURFACE_CHANGED";
  } else {
    // logger->logi("UNKNOWN");
    std::cout << "UNKNOWN";
  }
}
