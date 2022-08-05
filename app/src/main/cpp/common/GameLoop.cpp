// Copyright (c) 2021 Simon Puente
#include "GameLoop.hpp"

#include <chrono>

using std::chrono::milliseconds;
using std::chrono::duration;
using std::chrono::system_clock;
using std::chrono::high_resolution_clock;
using std::milli;

GameLoop::GameLoop(Logger *logger, Iterable *iterable) {
  this->logger = logger;
  this->iterable = iterable;
}

void GameLoop::loop() {
  double ONE_BILLION_NANOSECONDS = 1'000'000'000;

  float MAX_FRAMES_PER_SECOND = 60; // FPS
  float MAX_UPDATES_PER_SECOND = 60; // UPS

  double fOPTIMAL_TIME = ONE_BILLION_NANOSECONDS / MAX_FRAMES_PER_SECOND;
  double uOPTIMAL_TIME = ONE_BILLION_NANOSECONDS / MAX_UPDATES_PER_SECOND;

  double uDeltaTime = 0, fDeltaTime = 0;
  int frames = 0, updates = 0;
  auto startTime = high_resolution_clock::now();
  auto timer = high_resolution_clock::now();

  iterable->beforeLoop();

  while (iterable->isRunning()) {
    auto currentTime = high_resolution_clock::now();
    auto deltaTime = (currentTime - startTime).count();
    uDeltaTime += deltaTime;
    fDeltaTime += deltaTime;

    iterable->beforeIteration();

    if(uDeltaTime >= uOPTIMAL_TIME) {
      iterable->update(uDeltaTime / ONE_BILLION_NANOSECONDS);
      updates++;
      uDeltaTime -= uOPTIMAL_TIME;
    }

    if(fDeltaTime >= fOPTIMAL_TIME) {
      iterable->draw();
      frames++;
      fDeltaTime -= fOPTIMAL_TIME;
    }

    auto timer2 = high_resolution_clock::now();
    double elapsed_time_ms = duration<double, milli>(timer2 - timer).count();

    if (elapsed_time_ms >= 1'000) {
      logger->logi("UPS: %d, FPS: %d", updates, frames);

      updates = 0;
      frames = 0;
      elapsed_time_ms = 0;
      timer = timer2;
    }

    iterable->afterIteration();
  }

  iterable->afterLoop();
}
