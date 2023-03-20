#include <iostream>

#include "Dimension.hpp"

using std::ostream;

Dimension::Dimension(void) : width(450.0f), height(800.0f) { setUpBorders(); }
Dimension::Dimension(float width, float height) : width(width), height(height) {
  setUpBorders();
}
Dimension::Dimension(const Dimension &dimension)
    : width{dimension.width}, height{dimension.height} {
  setUpBorders();
}

float Dimension::getWidth() { return width; }
float Dimension::getHeight() { return height; }
float Dimension::aspectRatio() { return width / height; }

ostream &operator<<(ostream &strm, const Dimension &dimension) {
  return strm << "Dimension(width:" << dimension.width
              << ",height:" << dimension.height << ")";
}

bool Dimension::isPortrait() { return height > width; }
bool Dimension::isLandscape() { return height < width; }
bool Dimension::isSquare() { return height == width; }
Dimension Dimension::flip() { return Dimension(height, width); }
bool Dimension::isOutside(Point3D point) { return !isInside(point); }

bool Dimension::isInside(Point3D point) {
  float x = point.getX();
  float y = point.getY();

  return left <= x && x <= right && bottom <= y && y <= top;
}

void Dimension::setUpBorders() {
  right = width / 2;
  left = -width / 2;
  top = height / 2;
  bottom = -height / 2;
}
