//
// Created by simonppg on 3/13/19.
//

#include "Cube.hpp"

#include <malloc.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#ifdef __ANDROID_NDK__
#include "android/filesManager.hpp"

#else
#include "linux/filesManager.hpp"
#endif
using glm::mat4;
using glm::vec3;


Cube::Cube(): x{0}, y{0}, z{0} {
    vertex_file = load_file("cube/cube.vert");
    fragment_file = load_file("cube/cube.frag");
    programID = createProgram(vertex_file, fragment_file);
}

Cube::~Cube() {
    if(vertex_file)
        free(vertex_file);

    if(fragment_file)
        free(fragment_file);
}

void Cube::load_model() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(numVertices), vertex, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &iab);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(numIndices), indices, GL_STATIC_DRAW);

}

void Cube::draw() {
    mat4 perspective;
    mat4 cameraTranslate;
    mat4 translate;
    mat4 rotate;

    glUseProgram(programID);
    GLint uniform = glGetUniformLocation(programID, "matrix");

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);

    // TODO: inject viewport width/height and camera position
    perspective = glm::perspective(glm::radians(60.0f), ((float)800/ 600), 0.1f, 1000.0f);
    cameraTranslate = glm::translate(perspective, vec3(-0, -0, -40.0f));
    translate = glm::translate(cameraTranslate, vec3(x - 2.0f, y, z));
    rotate = glm::rotate(translate, glm::radians(0.0f), vec3(1,0,0));

    translate = glm::translate(cameraTranslate, vec3(x, y, z));
    rotate = glm::rotate(translate, glm::radians(0.0f), vec3(0,0,1));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &rotate[0][0]);
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0);
}
