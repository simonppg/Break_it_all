// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_FIELDOFVIEW_HPP_
#define APP_SRC_MAIN_CPP_COMMON_FIELDOFVIEW_HPP_

class FieldOfView {
private:
  float ncp; // near clipping plane
  float fcp; // far clipping plane
  float fov; // field of view

public:
  FieldOfView();

  float getNcp();
  float getFcp();
  float getFov();
};

#endif // APP_SRC_MAIN_CPP_COMMON_FIELDOFVIEW_HPP_
