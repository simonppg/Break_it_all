#include "CursorPositionChanged.hpp"
#include "EventType.hpp"

CursorPositionChanged::CursorPositionChanged (double xPosition, double yPosition) : xPosition(xPosition), yPosition (yPosition) {}

EventType CursorPositionChanged::type() { return CURSOR_POSITION_CHANGED; }
double CursorPositionChanged::getXPosition() { return xPosition; }
double CursorPositionChanged::getYPosition() { return yPosition; }

