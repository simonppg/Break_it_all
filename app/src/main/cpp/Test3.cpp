//
// Created by simonppg on 3/28/19.
//

#include "Test3.hpp"

#include <vector>
#include <cmath>

#define NUMBER_OF_VERTICES 160
float radius = 0.5;
std::vector<float> vertexBuffer;

Test3::Test3() {
    camera = new Camera(WIDTH, HEIGHT, X, Y, Z, NCP, FCP, FOV);
    for(double i = 0; i < 2 * M_PI; i += 2 * M_PI / NUMBER_OF_VERTICES) {
        vertexBuffer.push_back(cos(i) * radius);    //X coordinate
        vertexBuffer.push_back(sin(i) * radius);    //Y coordinate
        vertexBuffer.push_back(0.0);                //Z coordinate
    }
}

void Test3::render() {
    GLint uniform;
    mat4 translate;
    mat4 rotate;
    mat4 scale;

    glUseProgram(programID);
    uniform = glGetUniformLocation(programID, "matrix");

    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glVertexAttribPointer(0 , 3, GL_FLOAT, GL_FALSE, 12, vertexBuffer.data());
    glEnableVertexAttribArray(0);

    translate = glm::translate(camera->cameraTranslate, vec3(0, 0, 0));
    rotate = glm::rotate(translate, glm::radians(0.0f), vec3(1, 0, 0));
    scale = glm::scale(rotate, glm::vec3(5));
    glUniformMatrix4fv(uniform, 1, GL_FALSE, &scale[0][0]);

    glDrawArrays(GL_TRIANGLE_FAN, 0, NUMBER_OF_VERTICES);

    glUseProgram(0);
}

void Test3::surfaceCreated() {
    char *vert, *frag;

    vert = load_file("examples/triangle/triangle.vert");
    frag = load_file("examples/triangle/triangle.frag");
    programID = Utils::createProgram(vert, frag);

    if (vert)
        free(vert);
    if (frag)
        free(frag);
}

void Test3::surfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Test3::pause() {
    glDeleteProgram(programID);
}

void Test3::resume() {
    glUseProgram(programID);
}

void Test3::update() {}

bool Test3::events(double xpos, double ypos) {
    return false;
}
