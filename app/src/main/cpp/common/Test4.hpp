// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_

#include "Math.hpp"
#include "IScene.hpp"
#include "Object.hpp"
#include "ShaderProg.hpp"
#include "Renderer.hpp"

class Test4 : public IScene {
private:
    vector<float> vPos;
    Math *math = new Math();

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

    Object *ball2;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_
