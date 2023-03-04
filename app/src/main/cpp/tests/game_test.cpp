// Copyright (c) 2022 Simon Puente
#include <gtest/gtest.h>

#include "../common/Dimension.hpp"
#include "../common/Math.hpp"
#include "../common/Vector.hpp"

TEST(GameTest, Dimension) {
  Dimension portrait(400, 800);
  Dimension flipedPortrait = portrait.flip();
  ASSERT_TRUE(portrait.isPortrait());
  ASSERT_FALSE(flipedPortrait.isPortrait());
  ASSERT_EQ(400, flipedPortrait.getHeight());
  ASSERT_EQ(800, flipedPortrait.getWidth());

  Dimension landscape(800, 400);
  Dimension flipedLandscape = landscape.flip();
  ASSERT_TRUE(landscape.isLandscape());
  ASSERT_FALSE(flipedLandscape.isLandscape());
  ASSERT_EQ(800, flipedLandscape.getHeight());
  ASSERT_EQ(400, flipedLandscape.getWidth());

  Dimension square(800, 800);
  ASSERT_TRUE(square.isSquare());
}

TEST(GameTest, collisionBetweenPointAndDimension) {
  Dimension box(400, 800);

  Point3D point3DInside(0, 0, 0);
  ASSERT_TRUE(box.isInside(point3DInside));
  ASSERT_FALSE(box.isOutside(point3DInside));

  Point3D point3DOutside(401, 801, 0);
  ASSERT_TRUE(box.isOutside(point3DOutside));
  ASSERT_FALSE(box.isInside(point3DOutside));

  Point3D outsideRight(201, 0, 0);
  ASSERT_TRUE(box.isOutside(outsideRight));
  ASSERT_FALSE(box.isInside(outsideRight));

  Point3D outsideLeft(-201, 0, 0);
  ASSERT_TRUE(box.isOutside(outsideLeft));
  ASSERT_FALSE(box.isInside(outsideLeft));

  Point3D outsideTop(0, 401, 0);
  ASSERT_TRUE(box.isOutside(outsideTop));
  ASSERT_FALSE(box.isInside(outsideTop));

  Point3D outsideBottom(0, -401, 0);
  ASSERT_TRUE(box.isOutside(outsideBottom));
  ASSERT_FALSE(box.isInside(outsideBottom));
}

// TEST(GameTest, getSectionsSize) {
//     float size;
//     Math math = Math();
//
//     size = math.get_sections_size(10, 10);
//     ASSERT_EQ(size, 1);
//     ASSERT_EQ(size * 10, 10);
//
//     size = math.get_sections_size(400, 10);
//     ASSERT_EQ(size, 40);
//     ASSERT_EQ(size * 10, 400);
//
//     size = math.get_sections_size(800, 9);
//     ASSERT_FLOAT_EQ(size, 88.888888889);
//     ASSERT_EQ(size * 9, 800);
// }

TEST(GameTest, gridSize) {
  int row = 10;
  int col = 9;
  vector<float> Va, Vb, Vc, Vd;
  Math math = Math();

  Va = math.generateGrid(Dimension(400, 800), 2, 2);
  ASSERT_EQ(Va.size(), 2 * 2 * 2);

  Vb = math.generateGrid(Dimension(400, 800), row, col);
  ASSERT_EQ(Vb.size(), row * col * 2);

  Vc = math.generateGrid(Dimension(400, 800), row + 10, col + 10);
  ASSERT_EQ(Vc.size(), (row + 10) * (col + 10) * 2);

  Vd = math.generateGrid(Dimension(10, 10), 10, 10);
  ASSERT_EQ(Vd.size(), 200);
}

// TEST(GameTest, gridXPos) {
//     vector<float> Va;
//
//     Va = Math::get_grid(10, 100, 10, 10);
//     ASSERT_EQ(Va.size(), 200);
//
//     for(unsigned int i = 0; i < Va.size(); i = i + 20) {
//         ASSERT_EQ(Va[i], -4.5);
//         ASSERT_EQ(Va[i + 2], -3.5);
//         ASSERT_EQ(Va[i + 4], -2.5);
//         ASSERT_EQ(Va[i + 6], -1.5);
//         ASSERT_EQ(Va[i + 8], -0.5);
//         ASSERT_EQ(Va[i + 10], 0.5);
//         ASSERT_EQ(Va[i + 12], 1.5);
//         ASSERT_EQ(Va[i + 14], 2.5);
//         ASSERT_EQ(Va[i + 16], 3.5);
//         ASSERT_EQ(Va[i + 18], 4.5);
//     }
// }

// TEST(GameTest, gridYPos) {
//     vector<float> Va;
//
//     Va = Math::get_grid(10, 100, 10, 10);
//     ASSERT_EQ(Va.size(), 200);
//     float y_offset = 95;
//
//     for(unsigned int i = 0; i < Va.size(); i = i + 20) {
//         for (int j = 1; j < 10; j = j + 2) {
//             ASSERT_EQ(Va[i + j], y_offset);
//         }
//         y_offset -= 10;
//     }
// }

TEST(GameTest, vectorNew) {
  Vector *v;

  v = new Vector(1, 1, 1);
  ASSERT_FLOAT_EQ(v->x, 1);
  ASSERT_FLOAT_EQ(v->y, 1);
  ASSERT_FLOAT_EQ(v->z, 1);
  delete v;

  v = new Vector(5, 25, 30);
  ASSERT_FLOAT_EQ(v->x, 5);
  ASSERT_FLOAT_EQ(v->y, 25);
  ASSERT_FLOAT_EQ(v->z, 30);
  delete v;
}

TEST(GameTest, vectorLength) {
  Vector *v;

  v = new Vector(0, 0, 0);
  ASSERT_FLOAT_EQ(v->length(), 0);
  delete v;

  v = new Vector(1, 0, 0);
  ASSERT_FLOAT_EQ(v->length(), 1);
  delete v;

  v = new Vector(0, 1, 0);
  ASSERT_FLOAT_EQ(v->length(), 1);
  delete v;

  v = new Vector(0, 0, 1);
  ASSERT_FLOAT_EQ(v->length(), 1);
  delete v;

  v = new Vector(1, 1, 0);
  ASSERT_FLOAT_EQ(v->length(), 1.4142135);
  delete v;

  v = new Vector(1, 1, 1);
  ASSERT_FLOAT_EQ(v->length(), 1.7320508);
  delete v;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
