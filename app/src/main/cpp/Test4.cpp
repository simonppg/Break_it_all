//
// Created by simonppg on 3/31/19.
//

#include "Test4.hpp"
#include <cstdlib>

Test4::Test4() {
    camera = new Camera(WIDTH, HEIGHT, X, Y, Z, NCP, FCP, FOV);
    camera->set_projection_type(ORTHO);

    square = new Square(camera);
    square->update_xyx(-200, -100, 0);
    square->update_size(20);
    square->animate_x();

#define SIZE 10
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            cube[i][j] = new Cube(camera);
            cube[i][j]->update_xyx((i * (SIZE + 31)) - 200, (j * (SIZE + 18)) - 15, 0);
            cube[i][j]->update_size(SIZE);
            cube[i][j]->animate_x();
        }
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
        for (auto &j : i) {
            j->draw();
        }
    }
}

void Test4::surfaceCreated() {
    glEnable(GL_DEPTH_TEST);
    // Square
    square->createProgram();

    // Cube
    for (auto &i : cube) {
        for (auto &j : i) {
            j->createProgram();
        }
    }
    Cube::load_model();
    Square::load_model();
}

void Test4::surfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Test4::pause() {
    //glDeleteProgram(programID);
}

void Test4::resume() {
    //glUseProgram(programID);
}

void Test4::update() {}

bool Test4::events(double xpos, double ypos) {
    return false;
}
