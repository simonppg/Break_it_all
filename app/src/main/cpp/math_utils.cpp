//
// Created by simonppg on 4/19/19.
//

#include "math_utils.hpp"

#include <cmath>

float Math::get_sections_size(float segment, float spaces) {
    return segment/spaces;
}

vector<float> Math::get_grid(float width, float height, float row, float col) {
    vector<float> v;
    float x_section = get_sections_size(width, col);
    float y_section = get_sections_size(height, row);
    float x_offset = -width/2 + x_section/2;
    float y_offset = height - y_section/2;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            v.push_back(x_offset);
            v.push_back(y_offset);
            x_offset = x_offset + x_section;
        }
        x_offset = -width/2 + x_section/2;
        y_offset = y_offset - y_section;
    }
    return v;
}

vector<float> Math::get_circle(float radius, int number_of_vertices) {
    vector<float> v;
    for(double i = 0; i < 2 * M_PI; i += 2 * M_PI / number_of_vertices) {
        v.push_back(cos(i) * radius);    //X coordinate
        v.push_back(sin(i) * radius);    //Y coordinate
        v.push_back(0.0);                //Z coordinate
    }
    return v;
}

short* Math::get_cube_index() {
    short *indices;
#define size 36
    indices = (short *) malloc(sizeof(short) * size);

    short p[] =
            {
                    // right face 0,1,4,5
                    0, 1, 4,
                    1, 4, 5,

                    // left face 2,3,6,7
                    2, 3, 6,
                    3, 6, 7,

                    // down face 0,1,2,3
                    0, 1, 2,
                    0, 2, 3,

                    // up face 4,5,6,7
                    4, 5, 6,
                    4, 6, 7,

                    // front face 1,2,5,6
                    1, 2, 5,
                    2, 5, 6,

                    // back face 0,3,4,7
                    0, 3, 4,
                    3, 4, 7
            };

    for (int i = 0; i < size; ++i) {
        indices[i] = p[i];
    }

    return indices;
#undef size
}

float* Math::get_cube() {
    float *vertex;
#define size 48
    vertex = (float *) malloc(sizeof(float) * size);

    float p[size] =
            {
                    1.0, -1.0, -1.0,// right down back
                    1.0, 0.0, 0.0,

                    1.0, -1.0, 1.0, // right down front
                    1.0, 1.0, 0.0,

                    -1.0, -1.0, 1.0, // left down front
                    0.0, 1.0, 0.0,

                    -1.0, -1.0, -1.0, // left down back
                    0.0, 0.0, 0.0,

                    1.0, 1.0, -1.0, // right up back
                    1.0, 0.0, 1.0,

                    1.0, 1.0, 1.0, // right up front
                    1.0, 1.0, 1.0,

                    -1.0, 1.0, 1.0, // left up front
                    0.0, 1.0, 1.0,

                    -1.0, 1.0, -1.0, // left up back
                    0.0, 0.0, 1.0
            };

    for (int i = 0; i < size; ++i) {
        vertex[i] = p[i];
    }

    return vertex;
#undef size
}
