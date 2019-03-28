//
// Created by simonppg on 3/27/19.
//

#ifndef BREAK_IT_ALL_TEST2_H
#define BREAK_IT_ALL_TEST2_H

#include "IScene.hpp"

class Test2 : public IScene {

public:
    Test2();
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
};

#endif //BREAK_IT_ALL_TEST2_H
