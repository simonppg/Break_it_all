#ifndef COMMON_TEST3_HPP
#define COMMON_TEST3_HPP

#include "Math.hpp"
#include "IScene.hpp"
#include "Renderer.hpp"
#include "../shared/FilesManager.hpp"

class Test3 : public IScene {
private:
    Renderer renderer;
    FilesManager *filesManager;
    Math *math = new Math();

public:
    Test3(FilesManager *filesManager);
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;
};


#endif // COMMON_TEST3_HPP
