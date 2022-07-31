// Copyright (c) 2022 Simon Puente
#include "SurfaceChanged.hpp"
#include "EventType.hpp"

SurfaceChanged::SurfaceChanged(double w, double h) : w(w), h(h) {}

EventType SurfaceChanged::type() { return EventType::SURFACE_CHANGED; }
double SurfaceChanged::width() { return w; }
double SurfaceChanged::height() { return h; }
