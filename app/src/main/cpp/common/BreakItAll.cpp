#include "BreakItAll.hpp"
#include <iostream>
#include <string>

using std::string;

BreakItAll::BreakItAll() {
  gl = new Gl();
  shaderLoader = new ShaderLoader();
}

BreakItAll::~BreakItAll() {
  delete gl;
  gl = nullptr;
  delete shaderLoader;
  shaderLoader = nullptr;
}

void BreakItAll::showProgramInfoLog(uint32_t program) {
  int infoLength = gl->getProgramInfoLength(program);
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

GLuint BreakItAll::createProgram(const char *vertexSource,
                                 const char *fragmentSource) {
  // In this function 0 is and error
  const int error = 0;

  if (vertexSource == NULL) {
    return error;
  }
  if (fragmentSource == NULL) {
    return error;
  }

  GLuint vertexShader = shaderLoader->loadVertexShader(vertexSource);
  if (!vertexShader) {
    // LOGE("Could not load vertexShader\n");
    return error;
  }

  GLuint fragmentShader = shaderLoader->loadFragmentShader(fragmentSource);
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

  if (!gl->isProgramLinkOk(program)) {
    showProgramInfoLog(program);
    glDeleteProgram(program);
    program = error;
  }

  return program;
}

uint32_t programID;

void BreakItAll::init() {
  std::cout << std::endl << "Break it all" << std::endl << std::endl;

  // TODO(Simon Puente): Move all GLES code to a GLESWrapper lib
  glEnable(GL_DEPTH_TEST);

  const string vert = "attribute vec3 vPosition;\n"
                      "void main(void) {\n"
                      "gl_Position = vec4(vPosition, 1.0);\n"
                      "}";

  const string frag = "#ifdef GL_ES\n"
                      "precision mediump float;\n"
                      "#endif // GL_ES\n"
                      "void main()\n"
                      "{\n"
                      "gl_FragColor = vec4(1.0);\n"
                      "}";

  static GLfloat vVertices[] = {0.0f, 0.5f, 0.0f,  -0.5f, -0.5f,
                                0.0f, 0.5f, -0.5f, 0.0f};

  programID = createProgram(vert.c_str(), frag.c_str());
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
