// Copyright (c) 2021 Simon Puente
#include "Test4.hpp"
#include "../shared/FilesManager.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "Object.hpp"
#include "Point3D.hpp"
#include "Projection.hpp"

static const float CAMERA_WIDTH = 450.0f;
static const float CAMERA_HEIGHT = 800.0f;
static float pov_in_degrees = 0.0f;
#define NUMBER_OF_VERTICES 15
static float radius = 1.0;

static float h = CAMERA_HEIGHT / 2;
static float x_size = 90.0f * (CAMERA_WIDTH / COL) / 100;
static float y_size = 80.0f * (h / ROW) / 100;

static float ball_size = CAMERA_WIDTH / 30;
static float cube_x_size = (CAMERA_WIDTH / 2) / 3;
static float cube_y_size = cube_x_size / 7;

static clock_t last_time;

Test4::Test4() {
  camera =
      new Camera(Dimension(CAMERA_WIDTH, CAMERA_HEIGHT), Point3D(0, 0, 40));
  camera->setProjection(Projection::ORTHOGRAPHIC);
  renderer = new Renderer();

  shaderProgs[0] = new ShaderProg("simple.vert", "simple.frag");
  shaderProgs[1] = new ShaderProg("circle.vert", "circle.frag");
  meshes[0] = new Mesh(math->get_cube(), 16, math->get_cube_index(), 36);
  auto circle = math->get_circle(radius, NUMBER_OF_VERTICES);
  meshes[1] = new Mesh(circle, NUMBER_OF_VERTICES);

  Dimension gridDimension(CAMERA_WIDTH, h);

  vPos = math->generateGrid(gridDimension, ROW, COL);
  for (int i = 0; i < ROW * COL; i++) {
    objects[i] = new Object(camera, shaderProgs[1], meshes[0]);
    objects[i]->update_size(x_size / 2, y_size / 2, 1);
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  ball = new Object(camera, shaderProgs[1], meshes[1]);
  ball->update_size(ball_size, ball_size, 1);
  ball->updatePosition(Point3D(0, camera->bottom + camera->top / 3, 0));
  ball->animate_x();

  paddle = new Object(camera, shaderProgs[1], meshes[0]);
  paddle->update_size(cube_x_size, cube_y_size, 1);
  paddle->updatePosition(Point3D(0, camera->bottom + cube_y_size * 2, 1));
  paddle->animate_y();

  ball2 = new Object(camera, shaderProgs[1], meshes[1]);
  ball2->update_size(ball_size, ball_size, 1);
  ball2->updatePosition(Point3D(camera->left, camera->top, 0));
  ball2->animate_x();
}

void Test4::render() {
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  for (auto &i : objects) {
    i->draw();
  }
  ball->draw();
  paddle->draw();
  ball2->draw();
}

void Test4::surfaceCreated() {
  glEnable(GL_DEPTH_TEST);

  for (auto &i : shaderProgs) {
    i->createProgram();
  }

  for (auto &i : meshes) {
    renderer->load_model(i);
  }
}

void Test4::surfaceChanged(int width, int height) {
  glViewport(0, 0, width, height);
  camera->updateDimension(Dimension(width, height));

  // h = (float)height/2;
  // h = camera->top;
  Dimension gridDimension(width, camera->top);

  vPos = math->generateGrid(gridDimension, ROW, COL);
  x_size = 90.0f * (static_cast<float>(width) / COL) / 100;
  y_size = 80.0f * (camera->top / ROW) / 100;

  for (int i = 0; i < ROW * COL; i++) {
    objects[i]->update_size(x_size / 2, y_size / 2, 1);
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  ball_size = static_cast<float>(width)/ 30;
  cube_x_size = (static_cast<float>(width)/ 2) / 3;
  cube_y_size = cube_x_size / 7;

  ball->update_size(ball_size, ball_size, 1);
  ball->updatePosition(Point3D(0, camera->bottom + camera->top / 3, 0));

  paddle->update_size(cube_x_size, cube_y_size, 1);
  paddle->updatePosition(Point3D(0, camera->bottom + cube_y_size * 2, 1));

  ball2->updatePosition(Point3D(camera->right, camera->bottom, 0));
}

void Test4::update() {
  // dt = time_since last_update
  auto time = static_cast<double>(clock());
  float dt = static_cast<float>((time - last_time) / CLOCKS_PER_SEC);

  Point3D ballPosition = ball->getPosition();
  ball->velocity += ball->acceleration * dt;
  if (ballPosition.getX() >= camera->getDimension().getWidth() / 2)
    ball->x_direction = -1;
  if (ballPosition.getX() <= -camera->getDimension().getWidth() / 2)
    ball->x_direction = 1;

  Point3D newBallPosition =
      ballPosition.incrementX(ball->velocity * dt * ball->x_direction);
  ball->updatePosition(newBallPosition);

  // LOGI("%f, %f, %f, %f", dt, ball->velocity, ball->velocity * dt, ball->x);

  last_time = clock();
}

bool Test4::events(double xpos, double ypos) {
  Dimension cameraDimension = camera->getDimension();

  float newX = (-cameraDimension.getWidth() / 2) + xpos;
  float newY = (-cameraDimension.getHeight() / 2) + cube_y_size * 2;

  paddle->updatePosition(Point3D(newX, newY, 0));
  pov_in_degrees += 5.0f;
  return true;
}

void Test4::pause() {}
void Test4::resume() {}
