#include "ShaderProg.hpp"
#include "Renderer.hpp"

#ifdef __ANDROID_NDK__
#include "../android/filesManager.hpp"
#else
#include "../linux/filesManager.hpp"
#endif

ShaderProg::ShaderProg(const char *vertShaderPath, const char *fragShaderPath) {
    vertex_file = load_file(vertShaderPath);
    fragment_file = load_file(fragShaderPath);
    renderer = Renderer();
}

void ShaderProg::createProgram() {
    programID = renderer.createProgram(vertex_file, fragment_file);
}
