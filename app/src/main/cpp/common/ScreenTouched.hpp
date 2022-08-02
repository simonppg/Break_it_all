// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SCREENTOUCHED_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SCREENTOUCHED_HPP_

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

#endif // APP_SRC_MAIN_CPP_COMMON_SCREENTOUCHED_HPP_
