#ifndef COMMON_TEST4_HPP
#define COMMON_TEST4_HPP

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

#endif // COMMON_TEST4_HPP
