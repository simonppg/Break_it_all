#ifndef COMMON_FIELD_OF_VIEW_H
#define COMMON_FIELD_OF_VIEW_H

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

#endif //COMMON_FIELD_OF_VIEW_H
