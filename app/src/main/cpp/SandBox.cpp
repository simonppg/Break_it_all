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

GLuint vbo; //TODO: remove hardcoded number
GLuint iab;
float pov_in_degrees = 0.0f;
int i;
struct tm *time2;

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

    s = Square_new();

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
    char *vert = load_file("simple.vert");
    char *frag = load_file("square.frag");

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

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(this->s->numVertices), this->s->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &iab);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(this->s->numIndices), this->s->indices, GL_STATIC_DRAW);

    programID = Utils::createProgram(vert, frag);

    if(vert)
        free(vert);

    if(frag)
        free(frag);

    LOGI("send data");
    // TODO: free buffers
}

void SandBox::render() {
    GLint uniform;
    time_t theTime;
    mat4 translate;
    mat4 rotate;

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
        i->set_rotation_angle(pov_in_degrees);
        i->draw();
    }

    glUseProgram(programID);
    theTime = time(0);

    // Cube 2
    uniform = glGetUniformLocation(programID, "matrix");

    for (i=0; i<24; i++) {
        time2 = localtime(&theTime);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                              (char *) (sizeof(float) * 3));
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);

        translate = glm::translate(this->camera->cameraTranslate,
                                   vec3(sin(.35f*time2->tm_sec+i)*8.0f,cos(.52f*time2->tm_sec+i)*8.0f,  sin(.70f*time2->tm_sec+i)*8.0f));
        rotate = glm::rotate(translate, glm::radians((float)time2->tm_sec), vec3(0, 1, 0));

        glUniformMatrix4fv(uniform, 1, GL_FALSE, &rotate[0][0]);
        glDrawElements(GL_TRIANGLES, this->s->numIndices, GL_UNSIGNED_SHORT, 0);
    }
}

void SandBox::surfaceChanged(int width, int height) {
    this->camera->update_width_height(width, height);
    glViewport(0, 0, width, height);
}

void SandBox::pause() {}

void SandBox::resume() {}

void SandBox::update() {}

bool SandBox::events(double xpos, double ypos) {
    pov_in_degrees += 2.5f;
    return true;
}
