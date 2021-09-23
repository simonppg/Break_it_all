#ifndef COMMON_MATH_H
#define COMMON_MATH_H

#include <vector>

using std::vector;

class Math {
public:
    vector<float> get_grid(float width, float height, float row, float col);
    float get_sections_size(float segment, float spaces);
    float * get_circle(float radius, int number_of_vertices);
    float * get_cube();
    short * get_cube_index();
};

#endif //COMMON_MATH_H
