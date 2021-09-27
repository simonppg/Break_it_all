#ifndef CURSOR_POSITION_CHANGED_H
#define CURSOR_POSITION_CHANGED_H

#include "Event.hpp"

class CursorPositionChanged : public Event {
private:
    double xPosition, yPosition;

public:
    CursorPositionChanged (double xPosition, double yPosition);

    double getXPosition();
    double getYPosition();
};

#endif // CURSOR_POSITION_CHANGED_H
