//
// Created by simonppg on 4/23/19.
//

#ifndef BREAK_IT_ALL_OBJECT_HPP
#define BREAK_IT_ALL_OBJECT_HPP

#include "Camera.hpp"
#include "Mesh.hpp"
#include "Point3D.hpp"
#include "ShaderProg.hpp"
#include "Renderer.hpp"
#include "DrawContext.hpp"

class Object {
protected:
    ShaderProg *prog;
    Renderer *renderer;
    DrawContext *draw_context;
    Camera *camera;
    float size_x, size_y, size_z;
    vec3 rotation;
    float angle;
    Mesh *mesh;
    Point3D *position = nullptr;

public:
    Object(Camera *pCamera, ShaderProg *pProg, Mesh *pMesh);

    Point3D *getPosition();

    void draw();
    void updatePosition(Point3D *position);
    void update_size(float size_x, float size_y, float size_z);
    void set_rotation_angle(float angle);
    void animate_x();
    void animate_y();
    void animate_z();

    float velocity;
    float acceleration = 0;
    float x_direction = 1;
};

#endif //BREAK_IT_ALL_OBJECT_HPP
