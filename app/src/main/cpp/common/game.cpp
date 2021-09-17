//
// Created by Simonppg on 11/6/2018.
//

#include "game.hpp"

//Examples
#include "SandBox.hpp"
#include "Test1.hpp"
#include "Test2.hpp"
#include "Test3.hpp"
#include "Test4.hpp"

#ifdef __ANDROID_NDK__
#include "../hal/src/android/logger.hpp"
#else
#include "../hal/src/linux/logger.hpp"
#endif

void Game::camera_forward() { pScene->camera->z--;
    //LOGI("%.2f",pScene->camera->z);
}
void Game::camera_back() { pScene->camera->z++;}
void Game::camera_left() { pScene->camera->x--;}
void Game::camera_right() { pScene->camera->x++;}
void Game::camera_reset() { pScene->camera->update_xyz(X, Y, Z); }

Game * Game::init(int pos) {
    // Don't call OpenGL functions here
    LOGI("Game::init %d", pos);

    if (pos == 0)
        return new Game(new SandBox());
    else if (pos == 1)
        return new Game(new Test1());
    else if (pos == 2)
        return new Game(new Test2());
    else if (pos == 3)
        return new Game(new Test3());
    else
        return new Game(new Test4());
}

Game::Game(IScene *pScene)
{
    this->pScene = pScene;
}

void Game::surfaceCreated() {
    //LOGE("OpenGL version: %s", glGetString(GL_VERSION));
    //LOGE("GLSL version: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
    pScene->surfaceCreated();
}

void Game::surfaceChanged(int width, int height) {
    pScene->surfaceChanged(width, height);
}

void Game::update() {
    pScene->update();
}

void Game::render() {
    pScene->render();
}

void Game::pause() {
    pScene->pause();
}

void Game::resume() {
    pScene->resume();
}

bool Game::on_touch_event(double xpos, double ypos)
{
    return pScene->events(xpos, ypos);;
}
