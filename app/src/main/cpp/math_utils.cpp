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
