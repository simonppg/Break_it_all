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

GLuint vbo[2]; //TODO: remove hardcoded number
GLuint indexArrayBufferID;
GLuint indexArrayBufferID2;
float pov_in_degrees = 0.0f;
int i;
struct tm *time2;

#include "SandBox.hpp"
#include "Cube.hpp"

GLfloat COLOR[] = {
        1.0f, 0.0f, 0.0f, 1.0f
};

SandBox::SandBox() {
    camera = new Camera(WIDTH, HEIGHT, X, Y, Z, NCP, FCP, FOV);
    t = Triangle_new(COLOR);
    s = Square_new();

    for (int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            cube[i][j] = new Cube(camera);
            cube[i][j]->update_xyx(2 * j - 16, 2 * i - 16 + 9, 0);
        }
    }

    cube[0][0]->update_xyx(-10, 18, 0);
    cube[0][0]->update_size(1);
    cube[0][0]->animate_x();

    cube[0][1]->update_xyx(0, 18, 0);
    cube[0][1]->update_size(2);
    cube[0][1]->animate_y();

    cube[0][2]->update_xyx(10, 18, 0);
    cube[0][2]->update_size(3);
    cube[0][2]->animate_z();

    cube2[0] = 0.0f;
    cube2[1] = 0.0f;
    cube2[2] = 0.0f;
}

void SandBox::surfaceCreated()
{
    Triangle *tri;
    for (auto &i : this->cube) {
        for (auto &j : i) {
            j->createProgram();
        }
    }

    char *vert = load_file("simple.vert");
    char *frag = load_file("square.frag");

    tri = this->t;

    // Triangle
    glGenBuffers(1, &vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(tri->numVertices), tri->vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &indexArrayBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(tri->numIndices), tri->indices, GL_STATIC_DRAW);

    // Cube
    Cube::load_model();

    glGenBuffers(1, &vbo[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(this->s->numVertices), this->s->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexArrayBufferID2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID2);
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
    mat4 scale;

    // Note: this should be called after change xyz or w/h
    this->camera->update_perspective();

    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);

    // Triangle1
    glUseProgram(programID);

    translate = glm::translate(this->camera->cameraTranslate, vec3(this->cube2[0] - 2.0f, this->cube2[1], this->cube2[2]));
    uniform = glGetUniformLocation(programID, "matrix");
    glUniformMatrix4fv(uniform, 1, GL_FALSE, &translate[0][0]);
    glDrawElements(GL_TRIANGLES, this->t->numIndices, GL_UNSIGNED_SHORT, 0);

    // Triangle 2
    translate = glm::translate(this->camera->cameraTranslate, vec3(this->cube2[0] + 2.0f, this->cube2[1] + 2.0f, this->cube2[2]));
    rotate = glm::rotate(translate, glm::radians(pov_in_degrees), vec3(0,1,0));
    scale = glm::scale(rotate, glm::vec3(5.0f, 5.0f, 5.0f));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &scale[0][0]);
    glDrawElements(GL_TRIANGLES, this->t->numIndices, GL_UNSIGNED_SHORT, 0);

    // Cube 1
    /*for (auto &i : this->cube) {
        for (auto &j : i) {
            j->draw();
        }
    }*/

    cube[0][0]->set_rotation_angle(pov_in_degrees);
    cube[0][1]->set_rotation_angle(pov_in_degrees);
    cube[0][2]->set_rotation_angle(pov_in_degrees);

    cube[0][0]->draw();
    cube[0][1]->draw();
    cube[0][2]->draw();

    glUseProgram(programID);
    theTime = time(0);

    // Cube 2
    for (i=0; i<24; i++) {
        time2 = localtime(&theTime);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                              (char *) (sizeof(float) * 3));
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID2);

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
