#include "Test4.hpp"

#include <string>

#include "../shared/FilesManager.hpp"
#include "Assets.hpp"
#include "Ball.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "Object.hpp"
#include "ObjectDrawer.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Projection.hpp"

Test4::Test4(FilesManager *filesManager) : Scene() {
  gl = new Gl();
  auto camera = new Camera(cameraSize, Point3D(0, 0, 40));
  camera->changeProjection(Projection::ORTHOGRAPHIC);
  renderer = new Renderer(camera);
  redBall = new Ball(&meshFactory);
  redBall->moveTo(camera->getPosition());
  greenBall = new Ball(&meshFactory);
  greenBall->moveTo(camera->getPosition());

  shaderProgs[0] =
      new ShaderProg(filesManager, Assets::SIMPLE_VERT, Assets::SIMPLE_FRAG);
  shaderProgs[1] =
      new ShaderProg(filesManager, Assets::CIRCLE_VERT, Assets::CIRCLE_FRAG);
  meshes[0] =
      new Mesh(math.generateCube(), 16, math.generateCubeIndexs(), 36);
  int NUMBER_OF_VERTICES = 15;
  float radius = 1.0;
  auto circle = math.generateCircle(radius, NUMBER_OF_VERTICES);
  meshes[1] = new Mesh(circle, NUMBER_OF_VERTICES);

  float h = cameraSize.getHeight() / 2;
  Dimension gridDimension(cameraSize.getWidth(), h);

  float ySize = 80.0f * (h / ROW) / 100;
  float xSize = 90.0f * (cameraSize.getWidth() / COL) / 100;
  vector<float> vPos = math.generateGrid(gridDimension, ROW, COL);
  for (int i = 0; i < ROW * COL; i++) {
    objects[i] = new Object(renderer, shaderProgs[1], meshes[0]);
    objects[i]->updateSize(Point3D(xSize / 2, ySize / 2, 1));
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  ball = new Object(renderer, shaderProgs[1], meshes[1]);
  float ball_size = cameraSize.getWidth() / 30;
  Point3D ballSize(ball_size, ball_size, 1);
  ball->updateSize(ballSize);
  ball->updatePosition(Point3D(0, bottom + top / 3, 0));
  ball->animate_x();
  ball->velocity = 0.01;

  float cubeXSize = (cameraSize.getWidth() / 2) / 3;
  float cubeYSize = cubeXSize / 7;
  paddle = new Object(renderer, shaderProgs[1], meshes[0]);
  paddle->updateSize(Point3D(cubeXSize, cubeYSize, 1));
  paddle->updatePosition(Point3D(0, bottom + cubeYSize * 2, 1));
  paddle->updatePosition(
      Point3D(0, -viewportDimension.getHeight() / 2 + cubeYSize * 2, 1));
  paddle->animate_y();

  ball2 = new Object(renderer, shaderProgs[1], meshes[1]);
  ball2->updateSize(ballSize);
  ball2->updatePosition(Point3D(left, top, 0));
  ball2->animate_x();

  this->enterScene(ball2);
  this->enterScene(ball);
  this->enterScene(paddle);
  for (auto &i : objects) {
    this->enterScene(i);
  }
  this->enterScene(redBall);
  this->enterScene(greenBall);
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
  delete gl;
  gl = nullptr;
}

void Test4::surfaceCreated() {
  gl->enable();

  for (auto &i : shaderProgs) {
    i->createProgram();
  }

  for (auto &i : meshes) {
    renderer->load_model(i);
  }
}

void Test4::surfaceChanged(Dimension dimension) {
  viewportDimension = dimension;
  double width = dimension.getWidth();
  double height = dimension.getHeight();

  gl->viewport(0, 0, width, height);
  // camera->resize(dimension);

  Dimension gridDimension(width, top);

  vector<float> vPos = math.generateGrid(gridDimension, ROW, COL);
  float x_size = 90.0f * (static_cast<float>(width) / COL) / 100;
  float y_size = 80.0f * (top / ROW) / 100;

  for (int i = 0; i < ROW * COL; i++) {
    objects[i]->updateSize(Point3D(x_size / 2, y_size / 2, 1));
    objects[i]->updatePosition(Point3D(vPos[i * 2], vPos[i * 2 + 1], 0));
  }

  float ball_size = static_cast<float>(width) / 30;
  float cubeXSize = (static_cast<float>(width) / 2) / 3;
  float cubeYSize = cubeXSize / 7;

  Point3D ballSize(ball_size, ball_size, 1);
  ball->updateSize(ballSize);
  ball->updatePosition(Point3D(0, bottom + top / 3, 0));

  paddle->updateSize(Point3D(cubeXSize, cubeYSize, 1));
  paddle->updatePosition(Point3D(0, bottom + cubeYSize * 2, 1));

  ball2->updatePosition(Point3D(right, bottom, 0));
}

void Test4::update(double dt) {
  Point3D ballPosition = ball->getPosition();
  ball->velocity += ball->acceleration * dt;

  if (viewportDimension.isOutside(ballPosition))
    xDirection *= -1;

  Point3D newBallPosition =
      ballPosition.incrementX(ball->velocity * dt * xDirection);
  ball->updatePosition(newBallPosition);

  // LOGI("%f, %f, %f, %f", dt, ball->velocity, ball->velocity * dt, ball->x);
}

bool Test4::events(Point2D point) {
  float cubeXSize = (cameraSize.getWidth() / 2) / 3;
  float cubeYSize = cubeXSize / 7;
  float newX = (-viewportDimension.getWidth() / 2) + point.getX();
  float newY = (-viewportDimension.getHeight() / 2) + cubeYSize * 2;

  paddle->updatePosition(Point3D(newX, newY, 0));
  povInDegrees += 5.0f;
  return true;
}

void Test4::pause() {}
void Test4::resume() {}
