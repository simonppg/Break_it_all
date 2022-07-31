#ifndef COMMON_ISCENE_HPP
#define COMMON_ISCENE_HPP

#include "Camera.hpp"

#include <GLES3/gl3.h>

class IScene {
protected:
    unsigned int programID;
public:
    virtual void surfaceCreated() = 0;
    virtual void render() = 0;
    virtual void surfaceChanged(Dimension) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void update() = 0;
    virtual bool events(double d, double d1) = 0;

    Camera *camera = nullptr;
};

#endif // COMMON_ISCENE_HPP
