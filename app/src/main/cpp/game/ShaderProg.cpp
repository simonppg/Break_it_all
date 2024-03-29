#include "ShaderProg.hpp"

Gl ShaderProg::gl;

ShaderProg::ShaderProg(FilesManager *filesManager, const string vertShaderPath,
                       const string fragShaderPath) {
  vertexFile = filesManager->loadFile(vertShaderPath);
  fragmentFile = filesManager->loadFile(fragShaderPath);
}

void ShaderProg::createProgram() {
  programID = createProgramm(vertexFile, fragmentFile);
}

void ShaderProg::use() { gl.useProgram(programID); }
void ShaderProg::clearProgram() { gl.clearProgram(); }

uint32_t ShaderProg::getUniformLocation(string uniformName) {
  return gl.getuniformlocation(programID, uniformName);
}

void ShaderProg::showProgramInfoLog(uint32_t program) {
  int infoLength = gl.getProgramInfoLength(program);
  if (!infoLength) {
    return;
  }

  string log = gl.getProgramInfoLog(program, infoLength);

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

  uint32_t vertexShader = shaderLoader.loadVertexShader(vertexSource);
  if (!vertexShader) {
    // LOGE("Could not load vertexShader\n");
    return error;
  }

  uint32_t fragmentShader = shaderLoader.loadFragmentShader(fragmentSource);
  if (!fragmentShader) {
    // LOGE("Could not load fragmentShader\n");
    return error;
  }

  auto programOrNull = gl.createProgram();
  if (!programOrNull.has_value()) {
    return error;
  }

  uint32_t program = programOrNull.value();

  gl.attachShader(program, vertexShader);
  gl.attachShader(program, fragmentShader);
  gl.linkProgram(program);

  if (!gl.isProgramLinkOk(program)) {
    showProgramInfoLog(program);
    gl.deleteProgram(program);
    program = error;
  }

  return program;
}
