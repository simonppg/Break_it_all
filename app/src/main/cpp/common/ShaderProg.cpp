#include "ShaderProg.hpp"

#include <GLES3/gl3.h>

#include "Renderer.hpp"

ShaderProg::ShaderProg(FilesManager *filesManager, const string vertShaderPath,
                       const string fragShaderPath) {
  vertexFile = filesManager->loadFile(vertShaderPath);
  fragmentFile = filesManager->loadFile(fragShaderPath);
  shaderLoader = new ShaderLoader();
  gl = new Gl();
}

ShaderProg::~ShaderProg() {
  delete shaderLoader;
  shaderLoader = nullptr;
  delete gl;
  gl = nullptr;
}

void ShaderProg::createProgram() {
  programID = createProgramm(vertexFile, fragmentFile);
}

void ShaderProg::use() { gl->useProgram(programID); }

uint32_t ShaderProg::getUniformLocation(string uniformName) {
  return gl->getuniformlocation(programID, uniformName);
}

void ShaderProg::showProgramInfoLog(GLuint program) {
  int infoLength = gl->getProgramInfoLength(program);
  if (!infoLength) {
    return;
  }

  string log = gl->getProgramInfoLog(program, infoLength);

  // TODO(Simon Puente): use shared/Logger
  std::cout << log;
}

uint32_t ShaderProg::createProgramm(const string vertexSource,
                                    const string fragmentSource) {
  // In this function 0 is and error
  const int error = 0;

  if (vertexSource.empty()) {
    return error;
  }
  if (fragmentSource.empty()) {
    return error;
  }

  uint32_t vertexShader =
      shaderLoader->loadShader(GL_VERTEX_SHADER, vertexSource);
  if (!vertexShader) {
    // LOGE("Could not load vertexShader\n");
    return error;
  }

  uint32_t fragmentShader =
      shaderLoader->loadShader(GL_FRAGMENT_SHADER, fragmentSource);
  if (!fragmentShader) {
    // LOGE("Could not load fragmentShader\n");
    return error;
  }

  auto programOrNull = gl->createProgram();
  if (!programOrNull.has_value()) {
    return error;
  }

  uint32_t program = programOrNull.value();

  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);

  if (!gl->isProgramLinkOk(program)) {
    showProgramInfoLog(program);
    glDeleteProgram(program);
    program = error;
  }

  return program;
}
