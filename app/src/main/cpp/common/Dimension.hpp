// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_DIMENSION_HPP_
#define APP_SRC_MAIN_CPP_COMMON_DIMENSION_HPP_

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

#endif // APP_SRC_MAIN_CPP_COMMON_DIMENSION_HPP_
