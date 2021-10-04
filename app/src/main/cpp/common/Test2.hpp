#ifndef COMMON_TEST2_HPP
#define COMMON_TEST2_HPP

#include "IScene.hpp"
#include "Renderer.hpp"
#include "../shared/FilesManager.hpp"

class Test2 : public IScene {
private:
    Renderer renderer;
    FilesManager *filesManager;

public:
    Test2(FilesManager *filesManager);
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;
};

#endif // COMMON_TEST2_HPP
