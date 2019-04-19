//
// Created by simonppg on 3/31/19.
//

#include "Test4.hpp"
#include "math_utils.hpp"

Test4::Test4() {
    camera = new Camera(WIDTH, HEIGHT, X, Y, Z, NCP, FCP, FOV);
    camera->set_projection_type(ORTHO);

    square = new Square(camera);
    square->update_xyx(-200, -100, 0);
    square->update_size(20);
    square->animate_x();

    for (auto &i : cube) {
        i = new Cube(camera);
    }
}

void Test4::render() {
    // Note: this should be called after change xyz or w/h
    this->camera->update_projection();

    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Square
    square->draw();

    // Cube
    for (auto &i : cube) {
        i->draw();
    }
}

void Test4::surfaceCreated() {
    glEnable(GL_DEPTH_TEST);
    // Square
    square->createProgram();

    // Cube
    for (auto &i : cube) {
        i->createProgram();
    }
    Cube::load_model();
    Square::load_model();
}

void Test4::surfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
    camera->update_width_height(width, height);

    float h = (float)height/2;
    vector<float> vPos = Math::get_grid(width, h, ROW, COL);
    float x_size = 90.0f*((float)width/COL)/100;
    float y_size = 80.0f*(h/ROW)/100;

    for (int i = 0; i < ROW * COL; i++) {
        cube[i]->update_size(x_size/2, y_size/2, 1);
        cube[i]->update_xyx(vPos[i * 2], vPos[i * 2 + 1], 0);
    }
}

void Test4::pause() {}

void Test4::resume() {}

void Test4::update() {}

bool Test4::events(double xpos, double ypos) {
    return false;
}
