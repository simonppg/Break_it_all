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
#include "math_utils.hpp"

SandBox::SandBox() {
    camera = new Camera(WIDTH, HEIGHT, X, Y, Z, NCP, FCP, FOV);

    shaderProgs[0] = new ShaderProg("simple.vert", "simple.frag");

    meshes[0] = new Mesh(Math::get_cube(), 48, Math::get_cube_index(), 36);

    for (auto &i : objects) {
        i = new Object(camera);
        i->mesh = meshes[0];
        i->prog = shaderProgs[0];
        i->update_size(2, 1, 1);
        i->update_xyz(sin(rand() % 20 -10) + rand() % 20 -10,
                            cos(rand() % 36 -18) + rand() % 36 -18,
                            tan(rand() % 100 + 1) + rand() % 100 -10);
        i->animate_y();
    }
}

void SandBox::surfaceCreated()
{
    glEnable(GL_DEPTH_TEST);

    shaderProgs[0]->createProgram();
    meshes[0]->load_model();
    // TODO: free buffers
}

void SandBox::render() {
    // Note: this should be called after change xyz or w/h
    this->camera->update_projection();

    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    for(auto &i : objects)
    {
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
    for(auto &i : objects)
    {
        i->set_rotation_angle(pov_in_degrees);
    }
}

bool SandBox::events(double xpos, double ypos) {
    pov_in_degrees += 5.0f;
    return true;
}
