//
// Created by simonppg on 3/31/19.
//

#include "Test4.hpp"

#include "math/math_utils.hpp"

static float pov_in_degrees = 0.0f;
#define NUMBER_OF_VERTICES 15
static float radius = 1.0;

static float h = (float)HEIGHT/2;
static vector<float> vPos = Math::get_grid(WIDTH, h, ROW, COL);
static float x_size = 90.0f*((float)WIDTH/COL)/100;
static float y_size = 80.0f*(h/ROW)/100;

static float ball_size = (float)WIDTH/30;
static float cube_x_size = ((float)WIDTH/2)/3;
static float cube_y_size = cube_x_size/7;

Test4::Test4() {
    camera = new Camera(WIDTH, HEIGHT, X, Y, Z, NCP, FCP, FOV);
    camera->set_projection_type(ORTHO);
    renderer = new Renderer();

    shaderProgs[0] = new ShaderProg("simple.vert", "simple.frag");
    shaderProgs[1] = new ShaderProg("circle.vert", "circle.frag");
    meshes[0] = new Mesh(Math::get_cube(), 16, Math::get_cube_index(), 36);
    meshes[1] = new Mesh(Math::get_circle(radius, NUMBER_OF_VERTICES), NUMBER_OF_VERTICES);

    for (int i = 0; i < ROW * COL; i++) {
        objects[i] = new Object(camera, shaderProgs[1], meshes[0]);
        objects[i]->update_size(x_size/2, y_size/2, 1);
        objects[i]->update_xyz(vPos[i * 2], vPos[i * 2 + 1], 0);
    }

    ball = new Object(camera, shaderProgs[1], meshes[1]);
    ball->update_size(ball_size, ball_size, 1);
    ball->update_xyz(0, -h + h/3, 0);
    ball->animate_x();

    paddle = new Object(camera, shaderProgs[1], meshes[0]);
    paddle->update_size(cube_x_size, cube_y_size, 1);
    paddle->update_xyz(0, -h + cube_y_size*2, 1);
    paddle->animate_y();
}

void Test4::render() {
    // Note: this should be called after change xyz or w/h
    this->camera->update_projection();

    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    for(auto &i : objects)
    {
        i->draw();
    }
    ball->draw();
    paddle->draw();
}

void Test4::surfaceCreated() {
    glEnable(GL_DEPTH_TEST);

    for(auto &i : shaderProgs) {
        i->createProgram();
    }

    for(auto &i : meshes) {
        renderer->load_model(i);
    }
}

void Test4::surfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
    camera->update_width_height(width, height);

    h = (float)height/2;
    vPos = Math::get_grid(width, h, ROW, COL);
    x_size = 90.0f*((float)width/COL)/100;
    y_size = 80.0f*(h/ROW)/100;

    for (int i = 0; i < ROW * COL; i++) {
        objects[i]->update_size(x_size/2, y_size/2, 1);
        objects[i]->update_xyz(vPos[i * 2], vPos[i * 2 + 1], 0);
    }

    ball_size = (float)width/30;
    cube_x_size = ((float)width/2)/3;
    cube_y_size = cube_x_size/7;

    ball->update_size(ball_size, ball_size, 1);
    ball->update_xyz(0, -h + h/3, 0);

    paddle->update_size(cube_x_size, cube_y_size, 1);
    paddle->update_xyz(0, -h + cube_y_size*2, 1);
}

void Test4::update() {
    /*for(auto &i : objects) {
        i->set_rotation_angle(pov_in_degrees);
    }*/
    //ball->set_rotation_angle(pov_in_degrees);
    //paddle->set_rotation_angle(pov_in_degrees);
}

bool Test4::events(double xpos, double ypos) {
    LOGI("%.2f, %.2f", xpos, ypos);

    //ball->update_xyz((-camera->w/2) + xpos, (camera->h / 2) - ypos, 0);
    paddle->update_xyz((-camera->w/2) + xpos, (-camera->h/2) + cube_y_size*2, 0);
    pov_in_degrees += 5.0f;
    return true;
}

void Test4::pause() {}
void Test4::resume() {}