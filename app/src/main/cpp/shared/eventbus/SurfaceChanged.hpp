#ifndef APP_SRC_MAIN_CPP_SHARED_EVENTBUS_SURFACECHANGED_HPP_
#define APP_SRC_MAIN_CPP_SHARED_EVENTBUS_SURFACECHANGED_HPP_

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

#endif // APP_SRC_MAIN_CPP_SHARED_EVENTBUS_SURFACECHANGED_HPP_
