#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void frameBufferSizeCallback(GLFWwindow*, int, int);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    GLFWwindow* window = glfwCreateWindow(1440, 810, "Tabletop-Player", NULL, NULL);
    if (window == NULL) {
        printf("ERROR: Failed to create a window\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("ERROR: Failed to bind GLFW with GLAD\n");
        return 1;
    }
    glViewport(0, 0, 1440, 810);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void frameBufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}