// Copyright (c) 2021 Simon Puente
#include "ShaderProg.hpp"
#include "Renderer.hpp"
#include <GLES3/gl3.h>

ShaderProg::ShaderProg(const string vertShaderStr, const string fragShaderStr) {
  vertexFile = vertShaderStr;
  fragmentFile = fragShaderStr;
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
