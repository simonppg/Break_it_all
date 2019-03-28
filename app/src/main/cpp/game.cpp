//
// Created by Simonppg on 11/6/2018.
//

#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

using glm::mat4;
using glm::vec3;

#include "game.hpp"
#include "colors.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "Test2.hpp"
#include "SandBox.hpp"

#ifdef __ANDROID_NDK__
#include "android/logger.hpp"
#include "android/filesManager.hpp"
#else
#include "linux/logger.hpp"
#include "linux/filesManager.hpp"
#endif

#ifdef __cplusplus
extern "C" {
#endif

bool on_touch_event(double xpos, double ypos)
{
    LOGI("x: %f, y: %f", xpos, ypos);
    //pov_in_degrees += 2.5f;
    //LOGI("%f", pov_in_degrees);

    return true;
}

#ifdef __cplusplus
}
#endif

void Game::camera_forward() { this->camera->z--;}
void Game::camera_back() { this->camera->z++;}
void Game::camera_left() { this->camera->x--;}
void Game::camera_right() { this->camera->x++;}
void Game::camera_reset() { this->camera->update_xyz(X, Y, Z); }

Game::Game(int pos, IScene *pScene)
{
    this->pScene = pScene;
}

Game * Game::init(int pos) {
    Game *game;

    // Don't call OpenGL functions here
    LOGI("Game::init %d", pos);

    if(pos == 0)
        game = new Game(pos, new SandBox());
    else
        game = new Game(pos, new Test2());

    return game;
}

void Game::surfaceCreated() {
    LOGI("on_surface_created");
    LOGI("GL_VERSION: %d GL_RENDERER: %d", GL_VERSION, GL_RENDERER);
    glEnable(GL_DEPTH_TEST);

    pScene->surfaceCreated();

    // TODO: free game
}

void Game::surfaceChanged(int width, int height) {
    pScene->surfaceChanged(width, height);
}

void Game::update() {}

void Game::render() {
    pScene->render();
}