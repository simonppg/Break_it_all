// Copyright (c) 2022 Simon Puente
#include "ScreenTouched.hpp"
#include "EventType.hpp"

ScreenTouched::ScreenTouched(double xPosition, double yPosition)
    : xPosition(xPosition), yPosition(yPosition) {}

EventType ScreenTouched::type() { return EventType::SCREEN_TOUCHED; }
double ScreenTouched::getXPosition() { return xPosition; }
double ScreenTouched::getYPosition() { return yPosition; }
