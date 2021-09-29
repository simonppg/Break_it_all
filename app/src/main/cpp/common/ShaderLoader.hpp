#ifndef COMMON_SHEADER_LOADER_HPP
#define COMMON_SHEADER_LOADER_HPP

#include <GLES3/gl3.h>

class ShaderLoader {
private:
    bool isCompilationOk(GLenum shader);
    int getInfoLogLength(GLenum shader);

    void showShaderInfoLog(GLenum shader);

public:
    GLuint loadShader(GLenum shaderType, const char* shaderSource);
};

#endif // COMMON_SHEADER_LOADER_HPP
