#include <glad/glad.h>

unsigned int createShader(unsigned int, char*);

void createAndBindShaders() {
    unsigned int program;
    program = glCreateProgram();
    
    unsigned int vertexShader = createShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentSource);
}

unsigned int createShader(unsigned int type, char* source) {
    unsigned int shader;
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    return shader;
}