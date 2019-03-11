//
// Created by Simonppg on 11/6/2018.
//

#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::mat4;
using glm::vec3;

#include "game.hpp"
#include "colors.hpp"
#include "triangle.hpp"
#include "square.hpp"

#ifdef __ANDROID_NDK__
#include "android/logger.hpp"
#include "android/filesManager.hpp"
#else
#include "linux/logger.hpp"
#include "linux/filesManager.hpp"
#endif

Game *game = NULL;

#ifdef __cplusplus
extern "C" {
#endif

GLuint programID;

GLuint vbo[2]; //TODO: remove hardcoded number
GLuint indexArrayBufferID;
GLuint indexArrayBufferID2;

void on_surface_created() {
    LOGI("on_surface_created");

    glEnable(GL_DEPTH_TEST);

    game = new Game();
    game->sendDataToOpenGL();

    // TODO: free game
}

void on_surface_changed(int width, int height) {
    game->w = width;
    game->h = height;
    glViewport(0, 0, width, height);
}

void on_draw_frame() {
    /* Sleeping to avoid thrashing the Android log. */
    usleep(500);
    //LOGI("New Frame Ready to be Drawn!!!!");
    game->renderFrame();
}

float pov_in_degrees = 0.0f;

bool on_touch_event()
{
    pov_in_degrees = pov_in_degrees + 2.5f;
    char buffer[64];
    snprintf(buffer, sizeof buffer, "%f", pov_in_degrees);

    LOGI(buffer);
    return true;
}

#ifdef __cplusplus
}
#endif

Game::Game()
{
    w = 800;
    h = 600; //TODO remove hardcoded numbers
    t = Triangle_new(RED);
    s = Square_new();
    camera[0] = 0.0f;
    camera[1] = 0.0f;
    camera[2] = 8.0f;

    cube[0] = 0.0f;
    cube[1] = -2.0f;
    cube[2] = 0.0f;
}

void Game::sendDataToOpenGL()
{
    Triangle *tri;
    Square *cube;

    char *vert = load_file("simple.vert");
    char *frag = load_file("square.frag");

    tri = game->t;
    cube = game->s;

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
    glGenBuffers(1, &vbo[1]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(cube->numVertices), cube->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexArrayBufferID2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(cube->numIndices), cube->indices, GL_STATIC_DRAW);

    programID = createProgram(vert, frag);
    glUseProgram(programID);

    if(vert)
        free(vert);

    if(frag)
        free(frag);

    LOGI("send data");
    // TODO: free buffers
}

void Game::renderFrame() {

    if(game->w <= 0 || game->h <= 0)
        return;

    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);

    // Triangle1
    mat4 perspective = glm::perspective(glm::radians(60.0f), ((float)game->w/ game->h), 0.9f, 10.0f);
    mat4 cameraTranslate = glm::translate(perspective, vec3(-game->camera[0], -game->camera[1], -game->camera[2]));
    mat4 translate = glm::translate(cameraTranslate, vec3(game->cube[0] - 2.0f, game->cube[1], game->cube[2]));
    mat4 rotate = glm::rotate(translate, glm::radians(0.0f), vec3(1,0,0));

    GLint uniform = glGetUniformLocation(programID, "matrix");
    glUniformMatrix4fv(uniform, 1, GL_FALSE, &translate[0][0]);
    glDrawElements(GL_TRIANGLES, game->t->numIndices, GL_UNSIGNED_SHORT, 0);

    // Triangle 2
    translate = glm::translate(cameraTranslate, vec3(game->cube[0] + 2.0f, game->cube[1] + 2.0f, game->cube[2]));
    rotate = glm::rotate(translate, glm::radians(pov_in_degrees), vec3(0,1,0));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &rotate[0][0]);
    glDrawElements(GL_TRIANGLES, game->t->numIndices, GL_UNSIGNED_SHORT, 0);

    // Cube 1
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID2);

    translate = glm::translate(cameraTranslate, vec3(game->cube[0], game->cube[1]+2.0f, game->cube[2]));
    rotate = glm::rotate(translate, glm::radians(0.0f), vec3(0,0,1));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &rotate[0][0]);
    glDrawElements(GL_TRIANGLES, game->s->numIndices, GL_UNSIGNED_SHORT, 0);

    // Cube 2
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID2);

    translate = glm::translate(cameraTranslate, vec3(game->cube[0]+1.0f, game->cube[1] -0.5f, game->cube[2]));
    rotate = glm::rotate(translate, glm::radians(45.0f), vec3(0,1,0));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &rotate[0][0]);
    glDrawElements(GL_TRIANGLES, game->s->numIndices, GL_UNSIGNED_SHORT, 0);
}
