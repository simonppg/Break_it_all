#ifndef BREAK_IT_ALL_TEST2_H
#define BREAK_IT_ALL_TEST2_H

#include "IScene.hpp"
#include "Renderer.hpp"

class Test2 : public IScene {
private:
    Renderer renderer;

public:
    Test2();
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;
};

#endif //BREAK_IT_ALL_TEST2_H
