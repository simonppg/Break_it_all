#ifndef COMMON_MATH_H
#define COMMON_MATH_H

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

#endif //COMMON_MATH_H
