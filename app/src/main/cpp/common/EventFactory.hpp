// Copyright (c) 2022 Simon Puente
#ifndef COMMON_EVENT_FACTORY_HPP
#define COMMON_EVENT_FACTORY_HPP

#include "Event.hpp"
#include "Key.hpp"

class EventFactory {
public:
  Event *cursorPositionChanged(double xPos, double yPos);
  Event *keyPressed(Key key, PressState pressState);
};

#endif // COMMON_EVENT_FACTORY_HPP
