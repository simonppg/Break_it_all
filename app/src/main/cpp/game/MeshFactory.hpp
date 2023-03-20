#ifndef APP_SRC_MAIN_CPP_GAME_MESHFACTORY_HPP_
#define APP_SRC_MAIN_CPP_GAME_MESHFACTORY_HPP_

#include "Mesh.hpp"

class MeshFactory {
public:
  Mesh *circle(float radius, int numberOfVertices);
};

#endif // APP_SRC_MAIN_CPP_GAME_MESHFACTORY_HPP_
