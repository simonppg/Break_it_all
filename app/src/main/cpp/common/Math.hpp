#ifndef COMMON_MATH_HPP
#define COMMON_MATH_HPP

#include <vector>
#include "Dimension.hpp"

using std::vector;

class Math {
public:
    vector<float> generateGrid(Dimension dimension, float row, float col);
    float * get_circle(float radius, int number_of_vertices);
    float * get_cube();
    short * get_cube_index();
};

#endif // COMMON_MATH_HPP
