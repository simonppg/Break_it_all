//
// Created by simonppg on 4/19/19.
//

#ifndef BREAK_IT_ALL_MATH_H
#define BREAK_IT_ALL_MATH_H

#include <vector>

using std::vector;

class Math {
public:
    static vector<float> get_grid(float width, float height, float row, float col);
    static float get_sections_size(float segment, float spaces);
    static float * get_circle(float radius, int number_of_vertices);
    static float * get_cube();
    static short * get_cube_index();
};

#endif //BREAK_IT_ALL_MATH_H
