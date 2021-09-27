#include "EventFactory.hpp"

#include "CursorPositionChanged.hpp"
#include "KeyPressed.hpp"
#include "Key.hpp"

Event* EventFactory::cursorPositionChanged(double xPos, double yPos) { return new CursorPositionChanged(xPos, yPos); }

Event* EventFactory::keyPressed(Key key, PressState pressState) { return new KeyPressed(key, pressState); }
