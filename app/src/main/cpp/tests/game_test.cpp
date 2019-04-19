#include <gtest/gtest.h>

#include "../math_utils.hpp"

TEST(GameTest, getSectionsSize) {
    float size;

    size = Math::get_sections_size(10, 10);
    ASSERT_EQ(size, 1);
    ASSERT_EQ(size * 10, 10);

    size = Math::get_sections_size(400, 10);
    ASSERT_EQ(size, 40);
    ASSERT_EQ(size * 10, 400);

    size = Math::get_sections_size(800, 9);
    ASSERT_FLOAT_EQ(size, 88.888888889);
    ASSERT_EQ(size * 9, 800);
}

TEST(GameTest, gridSize) {
    int row = 10;
    int col = 9;
    vector<float> Va, Vb, Vc, Vd;

    Va = Math::get_grid(400, 800, 2, 2);
    ASSERT_EQ(Va.size(), 2 * 2 * 2);

    Vb = Math::get_grid(400, 800, row, col);
    ASSERT_EQ(Vb.size(), row * col * 2);

    Vc = Math::get_grid(400, 800, row + 10, col + 10);
    ASSERT_EQ(Vc.size(), (row + 10) * (col + 10) * 2);

    Vd = Math::get_grid(10, 10, 10, 10);
    ASSERT_EQ(Vd.size(), 200);
}

TEST(GameTest, gridXPos) {
    vector<float> Va;

    Va = Math::get_grid(10, 100, 10, 10);
    ASSERT_EQ(Va.size(), 200);

    for(unsigned int i = 0; i < Va.size(); i = i + 20) {
        ASSERT_EQ(Va[i], -4.5);
        ASSERT_EQ(Va[i + 2], -3.5);
        ASSERT_EQ(Va[i + 4], -2.5);
        ASSERT_EQ(Va[i + 6], -1.5);
        ASSERT_EQ(Va[i + 8], -0.5);
        ASSERT_EQ(Va[i + 10], 0.5);
        ASSERT_EQ(Va[i + 12], 1.5);
        ASSERT_EQ(Va[i + 14], 2.5);
        ASSERT_EQ(Va[i + 16], 3.5);
        ASSERT_EQ(Va[i + 18], 4.5);
    }
}

TEST(GameTest, gridYPos) {
    vector<float> Va;

    Va = Math::get_grid(10, 100, 10, 10);
    ASSERT_EQ(Va.size(), 200);
    float y_offset = 95;

    for(unsigned int i = 0; i < Va.size(); i = i + 20) {
        for (int j = 1; j < 10; j = j + 2) {
            ASSERT_EQ(Va[i + j], y_offset);
        }
        y_offset -= 10;
    }
}