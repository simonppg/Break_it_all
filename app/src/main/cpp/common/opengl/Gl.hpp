#ifndef APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_

#include <cstdint>
#include <optional>
#include <string>

using std::optional;
using std::string;

class Gl {
public:
  optional<uint32_t> createProgram();
  void deleteProgram(uint32_t programId);
  void useProgram(uint32_t programId);
  void clearProgram();
  void linkProgram(uint32_t programId);
  bool isProgramLinkOk(uint32_t programId);
  int32_t getProgramInfoLength(uint32_t programId);
  string getProgramInfoLog(uint32_t programId, int32_t infoLogLength);

  optional<uint32_t> createShader(int32_t shaderType);
  optional<uint32_t> createVertextShader();
  optional<uint32_t> createFragmentShader();
  void deleteShader(uint32_t shaderId);
  void compileShader(uint32_t shaderId);
  void shaderSource(uint32_t shaderId, int32_t numberOfShaders,
                    string shaderSource);
  void attachShader(uint32_t programId, uint32_t shaderId);
  bool isShaderCompilationOk(uint32_t shaderId);
  int32_t getInfoLogLength(uint32_t shaderId);
  string getShaderInfoLog(uint32_t shaderId, int32_t infoLogLength);

  void genBuffer(uint32_t *buffer);
  void bindBuffer(int32_t bufferBindingTarget, uint32_t buffer);
  void bufferData(int32_t bufferBindingTarget, uintptr_t size, const void *data,
                  int32_t usage);

  void enableVertexAttribArray(uint32_t index);
  void vertexAttribPointer(uint32_t index, int32_t size);
  void vertexAttribPointer(uint32_t index, int32_t size, int32_t type,
                           bool normalized, uint32_t stride,
                           const void *pointer);

  void viewport(int32_t x, int32_t y, uint32_t width, uint32_t height);
  void clearColor(float red, float green, float blue, float alpha);
  void clear(uint32_t mask);
  void clear();
  void enable(int32_t capability);
  void enable();

  uint32_t getuniformlocation(uint32_t program, string name);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
