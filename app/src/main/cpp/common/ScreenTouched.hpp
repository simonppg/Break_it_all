#ifndef SCREEN_TOUCHED_H
#define SCREEN_TOUCHED_H

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

#endif // SCREEN_TOUCHED_H
