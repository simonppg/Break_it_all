// Copyright (c) 2021 Simon Puente
#include "Renderer.hpp"

#include <GLES3/gl3.h>
#include <cstdlib>

#include "MeshType.hpp"
#include "ShaderLoader.hpp"

Renderer::Renderer() {
  gl = new Gl();
  shaderLoader = new ShaderLoader();
}

Renderer::~Renderer() {
  delete gl;
  gl = nullptr;
  delete shaderLoader;
  shaderLoader = nullptr;
}

void Renderer::showProgramInfoLog(GLuint program) {
  int infoLength = gl->getProgramInfoLength(program);
  if (!infoLength) {
    return;
  }

  string log = gl->getProgramInfoLog(program, infoLength);

  // TODO(Simon Puente): use shared/Logger
  std::cout << log;
}

void Renderer::load_model(Mesh *pMesh) {
  gl->genBuffer(&pMesh->vbo);
  gl->bindBuffer(GL_ARRAY_BUFFER, pMesh->vbo);
  gl->bufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(pMesh->numVertices),
                 pMesh->vertex, GL_STATIC_DRAW);

  if (pMesh->type == MeshType::ONE) {
    gl->genBuffer(&pMesh->iab);
    gl->bindBuffer(GL_ELEMENT_ARRAY_BUFFER, pMesh->iab);
    gl->bufferData(GL_ELEMENT_ARRAY_BUFFER,
                   INDEX_BUFFER_SIZE(pMesh->numIndices), pMesh->indices,
                   GL_STATIC_DRAW);
  }
}

void Renderer::draw(DrawContext *pDrawContex) {
  Mesh *mesh = pDrawContex->mesh;
  GLint uniform;

  gl->useProgram(pDrawContex->programID);
  uniform = glGetUniformLocation(pDrawContex->programID, "matrix");

  if (mesh->type == MeshType::ONE) {
    gl->bindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    gl->enableVertexAttribArray(0);
    gl->enableVertexAttribArray(1);
    gl->vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    gl->vertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                            reinterpret_cast<char *>((sizeof(float) * 3)));
    gl->bindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->iab);

    glUniformMatrix4fv(uniform, 1, GL_FALSE,
                       &pDrawContex->matrix_transform[0][0]);
    glDrawElements(GL_TRIANGLES, mesh->numIndices, GL_UNSIGNED_SHORT, 0);
  } else if (mesh->type == MeshType::TWO) {
    gl->bindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    gl->vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
    gl->enableVertexAttribArray(0);
    glUniformMatrix4fv(uniform, 1, GL_FALSE,
                       &pDrawContex->matrix_transform[0][0]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, mesh->numVertices);
  }

  gl->useProgram(0);
}

uint32_t Renderer::createProgram(const string vertexSource,
                                 const string fragmentSource) {
  // In this function 0 is and error
  const int error = 0;

  if (vertexSource.empty()) {
    return error;
  }
  if (fragmentSource.empty()) {
    return error;
  }

  uint32_t vertexShader =
      shaderLoader->loadShader(GL_VERTEX_SHADER, vertexSource);
  if (!vertexShader) {
    // LOGE("Could not load vertexShader\n");
    return error;
  }

  uint32_t fragmentShader =
      shaderLoader->loadShader(GL_FRAGMENT_SHADER, fragmentSource);
  if (!fragmentShader) {
    // LOGE("Could not load fragmentShader\n");
    return error;
  }

  auto programOrNull = gl->createProgram();
  if (!programOrNull.has_value()) {
    return error;
  }

  uint32_t program = programOrNull.value();

  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);

  if (!gl->isProgramLinkOk(program)) {
    showProgramInfoLog(program);
    glDeleteProgram(program);
    program = error;
  }

  return program;
}
