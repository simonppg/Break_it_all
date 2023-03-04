// Copyright (c) 2022 Simon Puente
#include <iostream>

#include "Dimension.hpp"

using std::ostream;

Dimension::Dimension(void) : width(450.0f), height(800.0f) {}
Dimension::Dimension(float width, float height)
    : width(width), height(height) {}
Dimension::Dimension(const Dimension &dimension)
    : width{dimension.width}, height{dimension.height} {}

float Dimension::getWidth() { return width; }
float Dimension::getHeight() { return height; }
float Dimension::aspectRatio() { return width / height; }

ostream &operator<<(ostream &strm, const Dimension &dimension) {
  return strm << "Dimension(width:" << dimension.width
              << ",height:" << dimension.height << ")";
}

bool Dimension::isPortrait() { return height < width; }
bool Dimension::isLandscape() { return height < width; }
bool Dimension::isSquare() { return height == width; }
