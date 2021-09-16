//
// Created by simonppg on 3/28/19.
//

#ifndef BREAK_IT_ALL_TEST1_H
#define BREAK_IT_ALL_TEST1_H

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

#endif //BREAK_IT_ALL_TEST1_H
