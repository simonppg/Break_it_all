#ifndef APP_SRC_MAIN_CPP_SHARED_EVENTBUS_CURSORPOSITIONCHANGED_HPP_
#define APP_SRC_MAIN_CPP_SHARED_EVENTBUS_CURSORPOSITIONCHANGED_HPP_

#include "Event.hpp"

class CursorPositionChanged final : public Event {
private:
  double xPosition, yPosition;

public:
  CursorPositionChanged(double xPosition, double yPosition);

  EventType type();
  double getXPosition();
  double getYPosition();
};

#endif // APP_SRC_MAIN_CPP_SHARED_EVENTBUS_CURSORPOSITIONCHANGED_HPP_
