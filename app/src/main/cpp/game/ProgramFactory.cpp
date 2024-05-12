#include "ProgramFactory.hpp"
#include "Assets.hpp"
#include "Math.hpp"

ProgramFactory::ProgramFactory(FilesManager *filesManager) {
  this->filesManager = filesManager;

  programMap[Program::CIRCLE] =
      new ShaderProg(filesManager, Assets::CIRCLE_VERT, Assets::CIRCLE_FRAG);

  programMap[Program::SIMPLE] =
      new ShaderProg(filesManager, Assets::SIMPLE_VERT, Assets::SIMPLE_FRAG);
}

ShaderProg *ProgramFactory::get(Program program) { return programMap[program]; }
