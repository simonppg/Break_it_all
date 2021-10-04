#ifndef COMMON_SANDBOX_HPP
#define COMMON_SANDBOX_HPP

#include "IScene.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"
#include "Object.hpp"
#include "ShaderProg.hpp"
#include "Math.hpp"
#include "../shared/FilesManager.hpp"

class SandBox : public IScene {
private:
    Math *math = new Math();

public:
    SandBox(FilesManager *filesManager);
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;

    Mesh *meshes[1];
    Object *objects[40];
    ShaderProg *shaderProgs[1];
    Renderer *renderer;
};


#endif // COMMON_SANDBOX_HPP
