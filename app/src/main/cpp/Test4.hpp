//
// Created by simonppg on 3/31/19.
//

#ifndef BREAK_IT_ALL_TEST4_H
#define BREAK_IT_ALL_TEST4_H

#include "IScene.hpp"
#include "Square.hpp"
#include "Cube.hpp"

class Test4 : public IScene {

public:
    Test4();
    void surfaceCreated() override;
    void surfaceChanged(int width, int height) override;
    void render() override;
    void pause() override;
    void resume() override;
    void update() override;
    bool events(double xpos, double ypos) override;

    Square *square;
#define ROW 15
#define COL 9
    Cube *cube[ROW * COL];
};

#endif //BREAK_IT_ALL_TEST4_H
