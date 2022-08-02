// Copyright (c) 2022 Simon Puente
#ifndef COMMON_SCREEN_TOUCHED_HPP
#define COMMON_SCREEN_TOUCHED_HPP

#include "Event.hpp"

class ScreenTouched : public Event {
private:
  double xPosition, yPosition;

public:
  ScreenTouched(double xPosition, double yPosition);

  EventType type();
  double getXPosition();
  double getYPosition();
};

#endif // COMMON_SCREEN_TOUCHED_HPP
