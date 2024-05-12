#ifndef APP_SRC_MAIN_CPP_GAME_PROGRAMFACTORY_HPP_
#define APP_SRC_MAIN_CPP_GAME_PROGRAMFACTORY_HPP_

#include <map>

#include "FilesManager.hpp"
#include "ShaderProg.hpp"

enum class Program { CIRCLE };

using std::map;
using ProgramMap = map<Program, ShaderProg *>;

class ProgramFactory {
public:
  explicit ProgramFactory(FilesManager *);
  ShaderProg *circle();

private:
  FilesManager *filesManager;
  ProgramMap programMap;
};

#endif // APP_SRC_MAIN_CPP_GAME_PROGRAMFACTORY_HPP_
