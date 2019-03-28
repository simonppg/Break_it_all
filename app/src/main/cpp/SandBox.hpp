//
// Created by simonppg on 3/27/19.
//

#ifndef BREAK_IT_ALL_SANDBOX_H
#define BREAK_IT_ALL_SANDBOX_H

#include "IScene.hpp"
#include "Camera.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "Cube.hpp"

class SandBox : public IScene {

public:
    SandBox();
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;

    Camera *camera;
    float cube2[3];
    Triangle *t;
    Square *s;
    Cube *cube[15][15];
};


#endif //BREAK_IT_ALL_SANDBOX_H
