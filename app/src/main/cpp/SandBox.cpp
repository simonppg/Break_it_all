//
// Created by simonppg on 3/27/19.
//

#include <GLES3/gl3.h>
#include <ctime>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdlib>

using glm::mat4;
using glm::vec3;

float pov_in_degrees = 0.0f;

#include "SandBox.hpp"
#include "Cube.hpp"

SandBox::SandBox() {
    camera = new Camera(WIDTH, HEIGHT, X, Y, Z, NCP, FCP, FOV);

    for (auto &i : triangle) {
        i = new Triangle(camera);
        i->update_xyx(sin(rand() % 20 -10) + rand() % 20 -10,
                cos(rand() % 36 -18) + rand() % 36 -18,
                tan(rand() % 100 + 1) + rand() % 100 -10);
        i->update_size(rand() % 3);
    }

    for (auto &i : cube) {
        i = new Cube(camera);
        i->update_xyx(sin(rand() % 20 -10) + rand() % 20 -10,
                      cos(rand() % 36 -18) + rand() % 36 -18,
                      rand() % 100 -10);
        i->update_size(rand() % 3, rand() % 3, rand() % 3);
        i->animate_x();
    }

    cube[0]->update_xyx(-10, 5, 0);
    cube[0]->update_size(5, 1, 1);
    cube[0]->animate_x();

    cube[1]->update_xyx(0, 5, 0);
    cube[1]->update_size(2, 1, 1);
    cube[1]->animate_y();

    cube[2]->update_xyx(10, 5, 0);
    cube[2]->update_size(3, 1, 1);
    cube[2]->animate_z();
}

void SandBox::surfaceCreated()
{
    glEnable(GL_DEPTH_TEST);
    // Triangle
    for(auto &i : triangle)
    {
        i->createProgram();
    }
    Triangle::load_model();

    // Cube
    for (auto &i : cube) {
        i->createProgram();
    }
    Cube::load_model();

    // TODO: free buffers
}

void SandBox::render() {
    // Note: this should be called after change xyz or w/h
    this->camera->update_projection();

    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Triangle1
    for(auto &i : triangle)
    {
        i->draw();
    }

    // Cube 1
    for (auto &i : cube) {
        i->draw();
    }
}

void SandBox::surfaceChanged(int width, int height) {
    this->camera->update_width_height(width, height);
    glViewport(0, 0, width, height);
}

void SandBox::pause() {}

void SandBox::resume() {}

void SandBox::update() {
    for (auto &i : cube) {
        i->set_rotation_angle(pov_in_degrees);
    }
}

bool SandBox::events(double xpos, double ypos) {
    pov_in_degrees += 5.0f;
    return true;
}
