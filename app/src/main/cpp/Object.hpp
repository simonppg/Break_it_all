//
// Created by simonppg on 4/23/19.
//

#ifndef BREAK_IT_ALL_OBJECT_HPP
#define BREAK_IT_ALL_OBJECT_HPP

#include "Camera.hpp"
#include "Mesh.hpp"
#include "ShaderProg.hpp"

class Object {

public:
    Object(Camera *pCamera);
    float x,y,z;
    float size_x, size_y, size_z;
    vec3 rotation;
    float angle;
    Mesh *mesh;

    void draw();

    Camera *camera;
    ShaderProg *prog;
    void update_xyz(float x, float y, float z);

    void update_size(float size_x, float size_y, float size_z);
    void set_rotation_angle(float angle);
    void animate_x();

    void animate_y();

    void animate_z();
};

#endif //BREAK_IT_ALL_OBJECT_HPP
