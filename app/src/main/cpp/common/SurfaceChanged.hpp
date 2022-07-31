#ifndef COMMON_SURFACE_CHANGED_HPP
#define COMMON_SURFACE_CHANGED_HPP

#include "Event.hpp"

class SurfaceChanged : public Event {
private:
  double w, h;

public:
  SurfaceChanged(double w, double h);

  EventType type();
  double width();
  double height();
};

#endif // COMMON_SURFACE_CHANGED_HPP
