#include "ProgramFactory.hpp"
#include "Assets.hpp"
#include "Math.hpp"

ProgramFactory::ProgramFactory(FilesManager *filesManager) {
  this->filesManager = filesManager;

  programMap[Program::CIRCLE] =
      new ShaderProg(filesManager, Assets::CIRCLE_VERT, Assets::CIRCLE_FRAG);
}

ShaderProg *ProgramFactory::circle() { return programMap[Program::CIRCLE]; }
