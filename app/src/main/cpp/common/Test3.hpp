#ifndef COMMON_TEST3_HPP
#define COMMON_TEST3_HPP

#include "Math.hpp"
#include "IScene.hpp"
#include "Renderer.hpp"

class Test3 : public IScene {
private:
    Renderer renderer;
    Math *math = new Math();

public:
    Test3();
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;
};


#endif // COMMON_TEST3_HPP
