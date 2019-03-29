//
// Created by Simonppg on 11/6/2018.
//

#include "game.hpp"

//Examples
#include "SandBox.hpp"
#include "Test1.hpp"
#include "Test2.hpp"
#include "Test3.hpp"

void Game::camera_forward() { this->camera->z--;}
void Game::camera_back() { this->camera->z++;}
void Game::camera_left() { this->camera->x--;}
void Game::camera_right() { this->camera->x++;}
void Game::camera_reset() { this->camera->update_xyz(X, Y, Z); }

Game * Game::init(int pos) {
    // Don't call OpenGL functions here
    LOGI("Game::init %d", pos);

    if (pos == 0)
        return new Game(pos, new SandBox());
    else if (pos == 1)
        return new Game(pos, new Test1());
    else if (pos == 2)
        return new Game(pos, new Test2());
    else
        return new Game(pos, new Test3());
}

Game::Game(int pos, IScene *pScene)
{
    this->pScene = pScene;
}

void Game::surfaceCreated() {
    LOGI("on_surface_created");
    LOGI("GL_VERSION: %d GL_RENDERER: %d", GL_VERSION, GL_RENDERER);
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