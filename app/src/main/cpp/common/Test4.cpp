// Copyright (c) 2021 - 2022 Simon Puente
#include "Test4.hpp"

#include <string>

#include "../shared/FilesManager.hpp"
#include "Assets.hpp"
#include "Ball.hpp"
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

Test4::Test4(FilesManager *filesManager, Camera *camera) {
  gl = new Gl();
  this->camera = camera;
  camera->changeProjection(Projection::ORTHOGRAPHIC);
  renderer = new Renderer();
  math = new Math();
  redBall = new Ball();
  redBall->setPosition(camera->getPosition());
  greenBall = new Ball();
  greenBall->setPosition(camera->getPosition());

  const string simpleVert = filesManager->loadFile(Assets::SIMPLE_VERT);
  const string simpleFrag = filesManager->loadFile(Assets::SIMPLE_FRAG);
  const string circleVert = filesManager->loadFile(Assets::CIRCLE_VERT);
  const string circleFrag = filesManager->loadFile(Assets::CIRCLE_FRAG);

  shaderProgs[0] = new ShaderProg(simpleVert, simpleFrag);
  shaderProgs[1] = new ShaderProg(circleVert, circleFrag);
  meshes[0] =
      new Mesh(math->generateCube(), 16, math->generateCubeIndexs(), 36);
  int NUMBER_OF_VERTICES = 15;
  float radius = 1.0;
  auto circle = math->generateCircle(radius, NUMBER_OF_VERTICES);
  meshes[1] = new Mesh(circle, NUMBER_OF_VERTICES);

  float h = cameraSize.getHeight() / 2;
  Dimension gridDimension(cameraSize.getWidth(), h);

  float ySize = 80.0f * (h / ROW) / 100;
  float xSize = 90.0f * (cameraSize.getWidth() / COL) / 100;
  vector<float> vPos = math->generateGrid(gridDimension, ROW, COL);
  for (int i = 0; i < ROW * COL; i++) {
    objects[i] = new Object(shaderProgs[1], meshes[0]);
    objects[i]->updateSize(Point3D(xSize / 2, ySize / 2, 1));
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  ball = new Object(shaderProgs[1], meshes[1]);
  float ball_size = cameraSize.getWidth() / 30;
  Point3D ballSize(ball_size, ball_size, 1);
  ball->updateSize(ballSize);
  ball->updatePosition(Point3D(0, camera->bottom + camera->top / 3, 0));
  ball->animate_x();
  ball->velocity = 0.01;

  float cubeXSize = (cameraSize.getWidth() / 2) / 3;
  float cubeYSize = cubeXSize / 7;
  paddle = new Object(shaderProgs[1], meshes[0]);
  paddle->updateSize(Point3D(cubeXSize, cubeYSize, 1));
  paddle->updatePosition(Point3D(0, camera->bottom + cubeYSize * 2, 1));
  paddle->animate_y();

  ball2 = new Object(shaderProgs[1], meshes[1]);
  ball2->updateSize(ballSize);
  ball2->updatePosition(Point3D(camera->left, camera->top, 0));
  ball2->animate_x();
}

Test4::~Test4() {
  delete redBall;
  redBall = nullptr;
  delete greenBall;
  greenBall = nullptr;
  for (auto &object : objects) {
    delete object;
    object = nullptr;
  }
  for (auto &mesh : meshes) {
    delete mesh;
    mesh = nullptr;
  }
  for (auto &prog : shaderProgs) {
    delete prog;
    prog = nullptr;
  }
  delete ball;
  ball = nullptr;
  delete ball2;
  ball2 = nullptr;
  delete paddle;
  paddle = nullptr;
  delete renderer;
  renderer = nullptr;
  delete math;
  math = nullptr;
  delete gl;
  gl = nullptr;
}

void Test4::render() {
  gl->clearColor(0.6f, 0.6f, 0.6f, 1.0f);
  gl->clear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  for (auto &i : objects) {
    i->draw(camera);
  }
  ball->draw(camera);
  paddle->draw(camera);
  ball2->draw(camera);
  redBall->draw();
  greenBall->draw();
}

void Test4::surfaceCreated() {
  gl->enable(GL_DEPTH_TEST);

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

  gl->viewport(0, 0, width, height);
  camera->resize(dimension);

  Dimension gridDimension(width, camera->top);

  vector<float> vPos = math->generateGrid(gridDimension, ROW, COL);
  float x_size = 90.0f * (static_cast<float>(width) / COL) / 100;
  float y_size = 80.0f * (camera->top / ROW) / 100;

  for (int i = 0; i < ROW * COL; i++) {
    objects[i]->updateSize(Point3D(x_size / 2, y_size / 2, 1));
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  float ball_size = static_cast<float>(width) / 30;
  float cubeXSize = (static_cast<float>(width) / 2) / 3;
  float cubeYSize = cubeXSize / 7;

  Point3D ballSize(ball_size, ball_size, 1);
  ball->updateSize(ballSize);
  ball->updatePosition(Point3D(0, camera->bottom + camera->top / 3, 0));

  paddle->updateSize(Point3D(cubeXSize, cubeYSize, 1));
  paddle->updatePosition(Point3D(0, camera->bottom + cubeYSize * 2, 1));

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

  float cubeXSize = (cameraSize.getWidth() / 2) / 3;
  float cubeYSize = cubeXSize / 7;
  float newX = (-cameraDimension.getWidth() / 2) + point.getX();
  float newY = (-cameraDimension.getHeight() / 2) + cubeYSize * 2;

  paddle->updatePosition(Point3D(newX, newY, 0));
  povInDegrees += 5.0f;
  return true;
}

void Test4::pause() {}
void Test4::resume() {}
