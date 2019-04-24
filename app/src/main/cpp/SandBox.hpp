//
// Created by simonppg on 3/27/19.
//

#ifndef BREAK_IT_ALL_SANDBOX_H
#define BREAK_IT_ALL_SANDBOX_H

#include "IScene.hpp"
#include "Camera.hpp"
#include "Triangle.hpp"
#include "Cube.hpp"
#include "Mesh.hpp"
#include "Object.hpp"
#include "ShaderProg.hpp"

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

    Mesh *meshes[1];
    Object *cubo[40];
    ShaderProg *shaderProgs[1];
};


#endif //BREAK_IT_ALL_SANDBOX_H
