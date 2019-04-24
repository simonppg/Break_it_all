//
// Created by simonppg on 4/23/19.
//

#include "ShaderProg.hpp"

#ifdef __ANDROID_NDK__
#include "android/filesManager.hpp"
#else
#include "linux/filesManager.hpp"
#endif

ShaderProg::ShaderProg(const char *vertShaderPath, const char *fragShaderPath) {
    vertex_file = load_file(vertShaderPath);
    fragment_file = load_file(fragShaderPath);
}

void ShaderProg::createProgram() {
    programID = Utils::createProgram(vertex_file, fragment_file);
}