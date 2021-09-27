//
// Created by simonppg on 4/25/19.
//

#include "Renderer.hpp"
#include "MeshType.hpp"

#include <GLES3/gl3.h>
#include <malloc.h>

#ifdef __ANDROID_NDK__
#include "../android/logger.hpp"
#else
#include "../linux/logger.hpp"
#endif

bool isCompilationOk(GLenum shader) {
    GLint compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    return compiled;
}

bool isProgramLinkOk(GLuint program) {
    GLint linkStatus = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    return linkStatus;
}

int getInfoLogLength(GLenum shader) {
    GLint infoLen = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
    return infoLen;
}

int getProgramInfoLength(GLuint program) {
    GLint bufLength = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
    return bufLength;
}

void showShaderInfoLog(GLenum shader) {
    int infoLength = getInfoLogLength(shader);
    if (!infoLength) { return; }

    char *buf = (char*) malloc(sizeof(char) * infoLength);
    if (!buf) { return; }

    glGetShaderInfoLog(shader, infoLength, NULL, buf);
    LOGE("%s", buf);
    free(buf);
}

void showProgramInfoLog(GLuint program) {
    int infoLength = getProgramInfoLength(program);
    if(!infoLength) { return; }

    char *buf = (char *)malloc(sizeof(char) * infoLength);
    if (!buf) { return; }

    glGetProgramInfoLog(program, infoLength, NULL, buf);
    LOGE("%s", buf);
    free(buf);
}

void Renderer::load_model(Mesh *pMesh) {
    glGenBuffers(1, &pMesh->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, pMesh->vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(pMesh->numVertices), pMesh->vertex, GL_STATIC_DRAW);

    if(pMesh->type == MeshType::ONE) {
        glGenBuffers(1, &pMesh->iab);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pMesh->iab);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(pMesh->numIndices), pMesh->indices,
                     GL_STATIC_DRAW);
    }
}

void Renderer::draw(DrawContext *pDrawContex) {
    GLint uniform;

    glUseProgram(pDrawContex->programID);
    uniform = glGetUniformLocation(pDrawContex->programID, "matrix");

    if(pDrawContex->type == MeshType::ONE) {
        glBindBuffer(GL_ARRAY_BUFFER, pDrawContex->vbo);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                              (char *) (sizeof(float) * 3));
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pDrawContex->iab);

        glUniformMatrix4fv(uniform, 1, GL_FALSE, &pDrawContex->matrix_transform[0][0]);
        glDrawElements(GL_TRIANGLES, pDrawContex->numIndices, GL_UNSIGNED_SHORT, 0);
    }
    else if(pDrawContex->type == MeshType::TWO) {
        glBindBuffer(GL_ARRAY_BUFFER, pDrawContex->vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
        glEnableVertexAttribArray(0);
        glUniformMatrix4fv(uniform, 1, GL_FALSE, &pDrawContex->matrix_transform[0][0]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, pDrawContex->numVertices);
    }

    glUseProgram(0);
}

GLuint Renderer::loadShader(GLenum shaderType, const char* shaderSource) {
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

GLuint Renderer::createProgram(const char* vertexSource, const char * fragmentSource) {
    // In this function 0 is and error
    const int error = 0;

    if (vertexSource == NULL) { return error; }
    if (fragmentSource == NULL) { return error; }

    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    if (!vertexShader) {
        LOGE("Could not load vertexShader\n");
        return error;
    }

    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (!fragmentShader) {
        LOGE("Could not load fragmentShader\n");
        return error;
    }

    GLuint program = glCreateProgram();
    if (!program) { return error; }

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    GLint linkStatus = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

    if (!isProgramLinkOk(program)) {
      showProgramInfoLog(program);
      glDeleteProgram(program);
      program = error;
    }

    return program;
}
