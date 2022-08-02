// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_EVENTFACTORY_HPP_
#define APP_SRC_MAIN_CPP_COMMON_EVENTFACTORY_HPP_

#include "Event.hpp"
#include "Key.hpp"

class EventFactory {
public:
  Event *cursorPositionChanged(double xPos, double yPos);
  Event *keyPressed(Key key, PressState pressState);
};

#endif // APP_SRC_MAIN_CPP_COMMON_EVENTFACTORY_HPP_
