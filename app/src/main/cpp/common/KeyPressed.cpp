#include "KeyPressed.hpp"
#include "EventType.hpp"
#include "Key.hpp"

KeyPressed::KeyPressed(Key key, PressState pressState) : aKey(key), aPressState(pressState) {}

EventType KeyPressed::type() { return EventType::KEY_PRESSED; }
Key KeyPressed::key() { return aKey; }
PressState KeyPressed::pressState() { return aPressState; }

