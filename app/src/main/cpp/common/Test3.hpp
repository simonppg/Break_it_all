//
// Created by simonppg on 3/28/19.
//

#ifndef BREAK_IT_ALL_TEST3_H
#define BREAK_IT_ALL_TEST3_H

#include "Math.hpp"
#include "IScene.hpp"

class Test3 : public IScene {
private:
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


#endif //BREAK_IT_ALL_TEST3_H
