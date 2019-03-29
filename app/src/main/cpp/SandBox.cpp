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
    }

    triangle[0]->update_xyx(-2.0f, 0, 0);
    triangle[0]->update_size(1);

    triangle[1]->update_xyx(2.0f, 2.0f, 0);
    triangle[1]->update_size(2);

    for (auto &i : circle_of_cubes) {
        i = new Cube(camera);
    }

    for (auto &i : cube) {
        i = new Cube(camera);
    }

    cube[0]->update_xyx(-10, 18, 0);
    cube[0]->update_size(1);
    cube[0]->animate_x();

    cube[1]->update_xyx(0, 18, 0);
    cube[1]->update_size(2);
    cube[1]->animate_y();

    cube[2]->update_xyx(10, 18, 0);
    cube[2]->update_size(3);
    cube[2]->animate_z();

    cube2[0] = 0.0f;
    cube2[1] = 0.0f;
    cube2[2] = 0.0f;
}

void SandBox::surfaceCreated()
{
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
    this->camera->update_perspective();

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
