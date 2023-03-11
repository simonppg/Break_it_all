#include "Gl.hpp"
#include <GLES3/gl3.h>
#include <vector>

using std::nullopt;
using std::vector;

void Gl::useProgram(uint32_t program) { glUseProgram(program); }
void Gl::clearProgram() { glUseProgram(0); }
optional<uint32_t> Gl::createProgram() {
  auto program = glCreateProgram();
  if (program == 0) {
    return nullopt;
  }

  return program;
}

void Gl::linkProgram(uint32_t programId) { glLinkProgram(programId); }
void Gl::deleteProgram(uint32_t program) { glDeleteProgram(program); }

bool Gl::isProgramLinkOk(uint32_t program) {
  GLint linkStatus = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
  return linkStatus == GL_TRUE;
}

int32_t Gl::getProgramInfoLength(uint32_t program) {
  int32_t infoLogLength = 0;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
  return infoLogLength;
}

string Gl::getProgramInfoLog(uint32_t program, int32_t infoLogLength) {
  vector<char> buffer(infoLogLength);
  glGetProgramInfoLog(program, infoLogLength, NULL, buffer.data());
  string infoLog(begin(buffer), end(buffer));
  return infoLog;
}

optional<uint32_t> Gl::createVertextShader() {
  return createShader(GL_VERTEX_SHADER);
}

optional<uint32_t> Gl::createFragmentShader() {
  return createShader(GL_FRAGMENT_SHADER);
}

optional<uint32_t> Gl::createShader(int32_t shaderType) {
  auto shaderId = glCreateShader(shaderType);
  if (shaderId == 0) {
    return nullopt;
  }

  return shaderId;
}

void Gl::deleteShader(uint32_t shaderId) { glDeleteShader(shaderId); }

void Gl::compileShader(uint32_t shaderId) { glCompileShader(shaderId); }

void Gl::shaderSource(uint32_t shaderId, int32_t numberOfShaders,
                      string shaderSource) {
  const char *pShaderSource = shaderSource.c_str();
  glShaderSource(shaderId, numberOfShaders, &pShaderSource, NULL);
}

void Gl::attachShader(uint32_t programID, uint32_t shaderId) {
  glAttachShader(programID, shaderId);
}

bool Gl::isShaderCompilationOk(uint32_t shader) {
  GLint compilationStatus = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationStatus);
  return compilationStatus == GL_TRUE;
}

int32_t Gl::getInfoLogLength(uint32_t shader) {
  int32_t infoLogLength = 0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
  return infoLogLength;
}

string Gl::getShaderInfoLog(uint32_t shader, int32_t infoLogLength) {
  vector<char> buffer(infoLogLength);
  glGetShaderInfoLog(shader, infoLogLength, NULL, buffer.data());
  string infoLog(begin(buffer), end(buffer));
  return infoLog;
}

void Gl::genBuffer(uint32_t *buffer) {
  uint32_t numberOfBuffers = 1;
  glGenBuffers(numberOfBuffers, buffer);
}

void Gl::bindBuffer(int32_t bufferBindingTarget, uint32_t buffer) {
  glBindBuffer(bufferBindingTarget, buffer);
}

void Gl::bufferData(int32_t bufferBindingTarget, uintptr_t size,
                    const void *data, int32_t usage) {
  glBufferData(bufferBindingTarget, size, data, usage);
}

void Gl::enableVertexAttribArray(uint32_t index) {
  glEnableVertexAttribArray(index);
}

void Gl::vertexAttribPointer(uint32_t index, int32_t size, int32_t type,
                             bool normalized, uint32_t stride,
                             const void *pointer) {
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void Gl::viewport(int32_t x, int32_t y, uint32_t width, uint32_t height) {
  glViewport(x, y, width, height);
}

void Gl::clearColor(float red, float green, float blue, float alpha) {
  glClearColor(red, green, blue, alpha);
}

void Gl::clear(uint32_t mask) { glClear(mask); }
void Gl::clear() { glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); }

void Gl::enable(int32_t capability) { glEnable(capability); }
void Gl::enable() { glEnable(GL_DEPTH_TEST); }

uint32_t Gl::getuniformlocation(uint32_t program, string name) {
  return glGetUniformLocation(program, name.c_str());
}
