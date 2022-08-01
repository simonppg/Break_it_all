#ifndef COMMON_FIELD_OF_VIEW_HPP
#define COMMON_FIELD_OF_VIEW_HPP

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

#endif // COMMON_FIELD_OF_VIEW_HPP
