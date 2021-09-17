#include "BreakItAll.hpp"
#include <iostream>
#include <GLES3/gl3.h>

bool isCompilationOk(GLenum shader) {
    GLint compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    return compiled;
}

int getInfoLogLenght(GLenum shader) {
    GLint infoLen = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
    return infoLen;
}

void showShaderInfoLog(GLenum shader) {
    int infoLen = getInfoLogLenght(shader);
    if (!infoLen) { return; }

    char *buf = (char*) malloc(sizeof(char) * infoLen);
    if (!buf) { return; }

    glGetShaderInfoLog(shader, infoLen, NULL, buf);
    // LOGE("%s", buf);
    free(buf);
}

static GLuint loadShader(GLenum shaderType, const char* shaderSource) {
    // In this function 0 is and error
    int error = 0;

    // glCreateShader return 0 when there is an error
    GLuint shader = glCreateShader(shaderType);
    if(!shader) { return error; }

    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    if(isCompilationOk(shader)) { return shader; }

    showShaderInfoLog(shader);
    glDeleteShader(shader);

    return error;
}

static GLuint createProgram(const char* vertexSource, const char * fragmentSource)
{
    if(vertexSource == NULL || fragmentSource == NULL)
        return 0;

    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    if (!vertexShader)
    {
        // LOGE("Could not load vertexShader\n");
        return 0;
    }
    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (!fragmentShader)
    {
        // LOGE("Could not load fragmentShader\n");
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
                char* buf = (char*) malloc(sizeof(char) * bufLength);
                if (buf)
                {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                    // LOGE("Could not link program: %s", buf);
                    free(buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

unsigned int programID;

void BreakItAll::init() {
    std::cout << std::endl << "Break it all" << std::endl << std::endl;

    //TODO: Move all GLES code to a GLESWrapper lib
    glEnable(GL_DEPTH_TEST);

    const char *vert = "attribute vec3 vPosition;\n\
                void main(void) {\n\
                    gl_Position = vec4(vPosition, 1.0);\n\
                }";

    const char *frag = "#ifdef GL_ES\n\
                precision mediump float;\n\
                #endif\n\
                void main()\n\
                {\n\
                    gl_FragColor = vec4(1.0);\n\
                }";

    static GLfloat vVertices[] = { 0.0f, 0.5f, 0.0f,
                               -0.5f, -0.5f, 0.0f,
                               0.5f, -0.5f, 0.0f };

    programID = createProgram(vert, frag);
    glUseProgram(programID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);
}

void BreakItAll::render() {
    glUseProgram(programID);
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glUseProgram(0);
}

void BreakItAll::pause() {}

void BreakItAll::resume() {}

void BreakItAll::exampleList(vector<string> *examples) {
    *examples = this->examples;
}
