//
// Created by simonppg on 4/19/19.
//

#include "math_utils.hpp"

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