//
// Created by simonppg on 19/03/18.
//

#ifndef BREAK_IT_ALL_UTILS_H
#define BREAK_IT_ALL_UTILS_H

#include <GLES3/gl3.h>

#ifdef __cplusplus
extern "C" {
#endif

// Camera/viewport config
static const int WIDTH = 450;
static const int HEIGHT = 800;
static const float NCP = 0.1f;
static const float FCP = 100.0f;
static const float FOV = 60.0f;
static const float X = 0.0f;
static const float Y = 0.0f;
static const float Z = 40.0f;

#ifdef __cplusplus
}
#endif

class Utils {
private:
    static GLuint loadShader(GLenum shaderType, const char *shaderSource);
public:
    static GLuint createProgram(const char* vertexSource, const char * fragmentSource);
};

#endif //BREAK_IT_ALL_UTILS_H

