// Copyright (c) 2021 Simon Puente
#include "Test4.hpp"

#include <string>

#include "../shared/FilesManager.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "Object.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Projection.hpp"

static bool hitRightLimit(Dimension dimension, Point3D point) {
  return point.getX() >= dimension.getWidth() / 2;
}

static bool hitLeftLimit(Dimension dimension, Point3D point) {
  return point.getX() <= -dimension.getWidth() / 2;
}

Test4::Test4(FilesManager *filesManager) {
  auto cameraSize = Dimension(CAMERA_WIDTH, CAMERA_HEIGHT);
  camera = new Camera(cameraSize, Point3D(0, 0, 40));
  camera->setProjection(Projection::ORTHOGRAPHIC);
  renderer = new Renderer();

  const string simpleVert = filesManager->loadFile("simple.vert");
  const string simpleFrag = filesManager->loadFile("simple.frag");
  const string circleVert = filesManager->loadFile("circle.vert");
  const string circleFrag = filesManager->loadFile("circle.frag");

  shaderProgs[0] = new ShaderProg(simpleVert, simpleFrag);
  shaderProgs[1] = new ShaderProg(circleVert, circleFrag);
  meshes[0] = new Mesh(math->get_cube(), 16, math->get_cube_index(), 36);
  int NUMBER_OF_VERTICES = 15;
  float radius = 1.0;
  auto circle = math->get_circle(radius, NUMBER_OF_VERTICES);
  meshes[1] = new Mesh(circle, NUMBER_OF_VERTICES);

  Dimension gridDimension(CAMERA_WIDTH, h);

  vPos = math->generateGrid(gridDimension, ROW, COL);
  for (int i = 0; i < ROW * COL; i++) {
    objects[i] = new Object(shaderProgs[1], meshes[0]);
    objects[i]->updateSize(Point3D(x_size / 2, y_size / 2, 1));
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  ball = new Object(shaderProgs[1], meshes[1]);
  ball->updateSize(ballSize);
  ball->updatePosition(Point3D(0, camera->bottom + camera->top / 3, 0));
  ball->animate_x();
  ball->velocity = 0.01;

  paddle = new Object(shaderProgs[1], meshes[0]);
  paddle->updateSize(Point3D(cube_x_size, cube_y_size, 1));
  paddle->updatePosition(Point3D(0, camera->bottom + cube_y_size * 2, 1));
  paddle->animate_y();

  ball2 = new Object(shaderProgs[1], meshes[1]);
  ball2->updateSize(ballSize);
  ball2->updatePosition(Point3D(camera->left, camera->top, 0));
  ball2->animate_x();
}

void Test4::render() {
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  for (auto &i : objects) {
    i->draw(camera->cameraTranslate);
  }
  ball->draw(camera->cameraTranslate);
  paddle->draw(camera->cameraTranslate);
  ball2->draw(camera->cameraTranslate);
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

void Test4::surfaceChanged(Dimension dimension) {
  double width = dimension.getWidth();
  double height = dimension.getHeight();

  glViewport(0, 0, width, height);
  camera->updateDimension(dimension);

  Dimension gridDimension(width, camera->top);

  vPos = math->generateGrid(gridDimension, ROW, COL);
  x_size = 90.0f * (static_cast<float>(width) / COL) / 100;
  y_size = 80.0f * (camera->top / ROW) / 100;

  for (int i = 0; i < ROW * COL; i++) {
    objects[i]->updateSize(Point3D(x_size / 2, y_size / 2, 1));
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  ball_size = static_cast<float>(width) / 30;
  cube_x_size = (static_cast<float>(width) / 2) / 3;
  cube_y_size = cube_x_size / 7;

  ball->updateSize(ballSize);
  ball->updatePosition(Point3D(0, camera->bottom + camera->top / 3, 0));

  paddle->updateSize(Point3D(cube_x_size, cube_y_size, 1));
  paddle->updatePosition(Point3D(0, camera->bottom + cube_y_size * 2, 1));

  ball2->updatePosition(Point3D(camera->right, camera->bottom, 0));
}

void Test4::update(double dt) {
  Point3D ballPosition = ball->getPosition();
  ball->velocity += ball->acceleration * dt;

  if (hitRightLimit(camera->getDimension(), ballPosition))
    xDirection = -1;
  if (hitLeftLimit(camera->getDimension(), ballPosition))
    xDirection = 1;

  Point3D newBallPosition =
      ballPosition.incrementX(ball->velocity * dt * xDirection);
  ball->updatePosition(newBallPosition);

  // LOGI("%f, %f, %f, %f", dt, ball->velocity, ball->velocity * dt, ball->x);
}

bool Test4::events(Point2D point) {
  Dimension cameraDimension = camera->getDimension();

  float newX = (-cameraDimension.getWidth() / 2) + point.getX();
  float newY = (-cameraDimension.getHeight() / 2) + cube_y_size * 2;

  paddle->updatePosition(Point3D(newX, newY, 0));
  povInDegrees += 5.0f;
  return true;
}

void Test4::pause() {}
void Test4::resume() {}
