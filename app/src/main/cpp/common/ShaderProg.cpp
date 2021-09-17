//
// Created by simonppg on 4/23/19.
//

#include "ShaderProg.hpp"

#include "Renderer.hpp"

#ifdef __ANDROID_NDK__
#include "../hal/src/android/filesManager.hpp"
#else
#include "../hal/src/linux/filesManager.hpp"
#endif

ShaderProg::ShaderProg(const char *vertShaderPath, const char *fragShaderPath) {
    vertex_file = load_file(vertShaderPath);
    fragment_file = load_file(fragShaderPath);
}

void ShaderProg::createProgram() {
    programID = Renderer::createProgram(vertex_file, fragment_file);
}
