// Copyright (c) 2022 Simon Puente
#ifndef COMMON_CURSOR_POSITION_CHANGED_HPP
#define COMMON_CURSOR_POSITION_CHANGED_HPP

#include "Event.hpp"

class CursorPositionChanged : public Event {
private:
  double xPosition, yPosition;

public:
  CursorPositionChanged(double xPosition, double yPosition);

  EventType type();
  double getXPosition();
  double getYPosition();
};

#endif // COMMON_CURSOR_POSITION_CHANGED_HPP
