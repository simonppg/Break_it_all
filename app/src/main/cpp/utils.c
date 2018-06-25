//
// Created by simonppg on 19/03/18.
//

#include <malloc.h>

#include "utils.h"

#ifdef __ANDROID_NDK__
#include "android/logger.h"
#else
#include "linux/logger.h"
#endif

static GLuint loadShader(GLenum shaderType, const char* shaderSource)
{
    GLuint shader = glCreateShader(shaderType);
    if (shader)
    {
        glShaderSource(shader, 1, &shaderSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen)
            {
                char * buf = (char*) malloc(infoLen);
                if (buf)
                {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    //LOGE("Could not Compile Shader %d:\n%s\n", (int)shaderType, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint createProgram(const char* vertexSource, const char * fragmentSource)
{
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    if (!vertexShader)
    {
        //LOGE("Could not load vertexShader\n");
        return 0;
    }
    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (!fragmentShader)
    {
        ///LOGE("Could not load fragmentShader\n");
        return 0;
    }
    GLuint program = glCreateProgram();
    if (program)
    {
        glAttachShader(program , vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program , GL_LINK_STATUS, &linkStatus);
        if( linkStatus != GL_TRUE)
        {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength)
            {
                char* buf = (char*) malloc(sizeof(bufLength));
                if (buf)
                {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    //LOGE("Could not link program:\n%s\n", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

#ifdef __ANDROID__
// TODO: remove this function from common code
char* load_file(AAssetManager *assetManager, const char *filePath) {
    AAsset* file = AAssetManager_open(assetManager, filePath, AASSET_MODE_BUFFER);

    size_t fileLength = (size_t) AAsset_getLength(file);

    char* fileContent = malloc(fileLength+1);

    AAsset_read(file, fileContent, fileLength);

    // For safety you can add a 0 terminating character at the end of your file ...
    fileContent[fileLength] = '\0';

    AAsset_close(file);

    return fileContent;
}
#endif