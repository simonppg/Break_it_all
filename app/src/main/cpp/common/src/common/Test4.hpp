//
// Created by simonppg on 3/31/19.
//

#ifndef BREAK_IT_ALL_TEST4_H
#define BREAK_IT_ALL_TEST4_H

#include "IScene.hpp"
#include "Object.hpp"
#include "ShaderProg.hpp"
#include "Renderer.hpp"

class Test4 : public IScene {
protected:
#define ROW 15
#define COL 9
    Mesh *meshes[2];
    ShaderProg *shaderProgs[2];
    Object *objects[ROW * COL];
    Object *ball;
    Object *paddle;
    Renderer *renderer;
public:
    Test4();
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;
};

#endif //BREAK_IT_ALL_TEST4_H
