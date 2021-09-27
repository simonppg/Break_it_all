#include "EventFactory.hpp"

#include "CursorPositionChanged.hpp"

Event EventFactory::cursorPositionChanged(double xPos, double yPos) { return CursorPositionChanged(xPos, yPos); }
