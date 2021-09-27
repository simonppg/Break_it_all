#include "CursorPositionChanged.hpp"

CursorPositionChanged::CursorPositionChanged (double xPosition, double yPosition) : xPosition(xPosition), yPosition (yPosition) {}

double CursorPositionChanged::getXPosition() { return xPosition; }
double CursorPositionChanged::getYPosition() { return yPosition; }

