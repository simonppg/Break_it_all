// Copyright (c) 2022 Simon Puente
#ifndef COMMON_DIMENSION_HPP
#define COMMON_DIMENSION_HPP

#include <iostream>

using std::ostream;

class Dimension {
public:
  Dimension(void);
  Dimension(float width, float height);
  Dimension(const Dimension &dimension);

  float getWidth();
  float getHeight();
  float aspectRatio();

private:
  float width, height;
  friend ostream &operator<<(ostream &strm, const Dimension &dimension);
};

#endif // COMMON_DIMENSION_HPP
