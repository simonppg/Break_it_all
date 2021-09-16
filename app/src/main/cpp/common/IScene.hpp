//
// Created by simonppg on 3/27/19.
//

#ifndef BREAK_IT_ALL_ISCENE_H
#define BREAK_IT_ALL_ISCENE_H

#include "Camera.hpp"

#include <GLES3/gl3.h>

class IScene {
protected:
    unsigned int programID;
public:
    virtual void surfaceCreated() = 0;
    virtual void render() = 0;
    virtual void surfaceChanged(int width, int height) = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void update() = 0;
    virtual bool events(double d, double d1) = 0;

    Camera *camera = nullptr;
};

#endif //BREAK_IT_ALL_ISCENE_H
