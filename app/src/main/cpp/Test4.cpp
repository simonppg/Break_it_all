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

    for (auto &i : cube) {
        for (auto &j : i) {
            j = new Cube(camera);
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
    float total_gaps, gap_size, x_size, y_size;

    glViewport(0, 0, width, height);
    camera->update_width_height(width, height);

    total_gaps = COL + 1;
    gap_size = (10.0f * width / 100) / total_gaps;
    x_size = ((width - (total_gaps * gap_size)) / COL) / 2;
    y_size = ((((2*height)/3) - (total_gaps * gap_size)) / ROW) / 2;

    assert(x_size > 0);
    assert(y_size > 0);
    assert((total_gaps * gap_size) + (COL * x_size)*2 == width);
    assert((total_gaps * gap_size) + (ROW * y_size)*2 + height/3== height);

    float x_offset = -width/2 + gap_size + x_size;
    float y_offset = height/2 - gap_size - y_size;
    for (auto &i : cube) {
        for (auto &j : i)
        {
            j->update_size(x_size, y_size/2, 1);
            j->update_xyx(x_offset, y_offset, 0);
            x_offset = x_offset + (x_size*2) + gap_size;
        }
        x_offset = -width/2 + gap_size + x_size;
        y_offset = y_offset - (y_size) - gap_size;
    }
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
