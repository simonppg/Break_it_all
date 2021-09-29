#ifndef COMMON_TEST1_HPP
#define COMMON_TEST1_HPP

#include "IScene.hpp"

class Test1 : public IScene {

public:
    Test1();
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;
};

#endif // COMMON_TEST1_HPP
