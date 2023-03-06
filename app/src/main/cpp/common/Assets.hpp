#ifndef APP_SRC_MAIN_CPP_COMMON_ASSETS_HPP_
#define APP_SRC_MAIN_CPP_COMMON_ASSETS_HPP_

#include <string>

using std::string;

class Assets {
public:
  inline static const string TRIANGLE_VERT = "examples/triangle/triangle.vert";
  inline static const string TRIANGLE_FRAG = "examples/triangle/triangle.frag";
  inline static const string SIMPLE_VERT = "simple.vert";
  inline static const string SIMPLE_FRAG = "simple.frag";
  inline static const string CIRCLE_VERT = "circle.vert";
  inline static const string CIRCLE_FRAG = "circle.frag";
  inline static const string CUBE_VERT = "cube/cube.vert";
  inline static const string CUBE_FRAG = "cube/cube.frag";
};

#endif // APP_SRC_MAIN_CPP_COMMON_ASSETS_HPP_
