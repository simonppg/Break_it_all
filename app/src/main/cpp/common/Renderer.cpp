// Copyright (c) 2021 Simon Puente
#include "Renderer.hpp"

#include <GLES3/gl3.h>
#include <cstdlib>

#include "MeshType.hpp"

Renderer::Renderer() { gl = new Gl(); }

Renderer::~Renderer() {
  delete gl;
  gl = nullptr;
}

bool isProgramLinkOk(GLuint program) {
  GLint linkStatus = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
  return linkStatus;
}

int getProgramInfoLength(GLuint program) {
  GLint bufLength = 0;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
  return bufLength;
}

void showProgramInfoLog(GLuint program) {
  int infoLength = getProgramInfoLength(program);
  if (!infoLength) {
    return;
  }

  char *buf = reinterpret_cast<char *>(malloc(sizeof(char) * infoLength));
  if (!buf) {
    return;
  }

  glGetProgramInfoLog(program, infoLength, NULL, buf);
  // LOGE("%s", buf);
  free(buf);
}

void Renderer::load_model(Mesh *pMesh) {
  glGenBuffers(1, &pMesh->vbo);
  glBindBuffer(GL_ARRAY_BUFFER, pMesh->vbo);
  glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(pMesh->numVertices),
               pMesh->vertex, GL_STATIC_DRAW);

  if (pMesh->type == MeshType::ONE) {
    glGenBuffers(1, &pMesh->iab);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pMesh->iab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(pMesh->numIndices),
                 pMesh->indices, GL_STATIC_DRAW);
  }
}

void Renderer::draw(DrawContext *pDrawContex) {
  Mesh *mesh = pDrawContex->mesh;
  GLint uniform;

  gl->useProgram(pDrawContex->programID);
  uniform = glGetUniformLocation(pDrawContex->programID, "matrix");

  if (mesh->type == MeshType::ONE) {
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                          reinterpret_cast<char *>((sizeof(float) * 3)));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->iab);

    glUniformMatrix4fv(uniform, 1, GL_FALSE,
                       &pDrawContex->matrix_transform[0][0]);
    glDrawElements(GL_TRIANGLES, mesh->numIndices, GL_UNSIGNED_SHORT, 0);
  } else if (mesh->type == MeshType::TWO) {
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
    glEnableVertexAttribArray(0);
    glUniformMatrix4fv(uniform, 1, GL_FALSE,
                       &pDrawContex->matrix_transform[0][0]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, mesh->numVertices);
  }

  glUseProgram(0);
}

GLuint Renderer::createProgram(const string vertexSourceStr,
                               const string fragmentSourceStr) {
  const char *vertexSource = vertexSourceStr.c_str();
  const char *fragmentSource = fragmentSourceStr.c_str();
  // In this function 0 is and error
  const int error = 0;

  if (vertexSource == NULL) {
    return error;
  }
  if (fragmentSource == NULL) {
    return error;
  }

  GLuint vertexShader = shaderLoader.loadShader(GL_VERTEX_SHADER, vertexSource);
  if (!vertexShader) {
    // LOGE("Could not load vertexShader\n");
    return error;
  }

  GLuint fragmentShader =
      shaderLoader.loadShader(GL_FRAGMENT_SHADER, fragmentSource);
  if (!fragmentShader) {
    // LOGE("Could not load fragmentShader\n");
    return error;
  }

  GLuint program = glCreateProgram();
  if (!program) {
    return error;
  }

  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);

  if (!isProgramLinkOk(program)) {
    showProgramInfoLog(program);
    glDeleteProgram(program);
    program = error;
  }

  return program;
}
