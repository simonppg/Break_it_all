// Copyright (c) 2022 Simon Puente
#include "EventFactory.hpp"

#include "CursorPositionChanged.hpp"
#include "Key.hpp"
#include "KeyPressed.hpp"

Event *EventFactory::cursorPositionChanged(double xPos, double yPos) {
  return new CursorPositionChanged(xPos, yPos);
}

Event *EventFactory::keyPressed(Key key, PressState pressState) {
  return new KeyPressed(key, pressState);
}
