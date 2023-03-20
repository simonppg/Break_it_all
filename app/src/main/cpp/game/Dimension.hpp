#ifndef APP_SRC_MAIN_CPP_GAME_DIMENSION_HPP_
#define APP_SRC_MAIN_CPP_GAME_DIMENSION_HPP_

#include <iostream>

#include "Point3D.hpp"

using std::ostream;

class Dimension {
public:
  Dimension(void);
  Dimension(float width, float height);
  Dimension(const Dimension &dimension);

  float getWidth();
  float getHeight();
  float aspectRatio();

  bool isPortrait();
  bool isLandscape();
  bool isSquare();

  Dimension flip();
  bool isOutside(Point3D point);
  bool isInside(Point3D point);

private:
  float width, height;
  float top, bottom, right, left;
  friend ostream &operator<<(ostream &strm, const Dimension &dimension);
  void setUpBorders();
};

#endif // APP_SRC_MAIN_CPP_GAME_DIMENSION_HPP_
