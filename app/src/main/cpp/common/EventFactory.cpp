#include "EventFactory.hpp"

#include "CursorPositionChanged.hpp"
#include "KeyPressed.hpp"

Event* EventFactory::cursorPositionChanged(double xPos, double yPos) { return new CursorPositionChanged(xPos, yPos); }

Event* EventFactory::keyPressed(int key, int scancode, int action, int mods) { return new KeyPressed(); }
