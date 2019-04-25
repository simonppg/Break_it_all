//
// Created by simonppg on 4/25/19.
//

#include "Renderer.hpp"

#include <GLES3/gl3.h>

void Renderer::load_model(Mesh *pMesh) {
    glGenBuffers(1, &pMesh->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, pMesh->vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(pMesh->numVertices), pMesh->vertex, GL_STATIC_DRAW);

    if(pMesh->type == ONE) {
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

    if(pDrawContex->type == ONE) {
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
    else if(pDrawContex->type == TWO) {
        glBindBuffer(GL_ARRAY_BUFFER, pDrawContex->vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
        glEnableVertexAttribArray(0);
        glUniformMatrix4fv(uniform, 1, GL_FALSE, &pDrawContex->matrix_transform[0][0]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, pDrawContex->numVertices);
    }

    glUseProgram(0);
}
