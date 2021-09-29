#ifndef BREAK_IT_ALL_SHADERPROG_HPP
#define BREAK_IT_ALL_SHADERPROG_HPP

class ShaderProg {
public:
    ShaderProg(const char *vertShaderPath, const char *fragShaderPath);

    char *vertex_file;
    char *fragment_file;

    void createProgram();

    unsigned int programID;
};

#endif //BREAK_IT_ALL_SHADERPROG_HPP
