//
//  main.cpp
//  opengl-testing
//
//  Created by Loïc Pirez on 09/09/2021.
//

#include <iostream>
#include "include/deps.hpp"

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        std::cerr << "ERROR: could not start GLFW3" << std::endl;
        return 1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

    GLFWwindow *window;
    window = glfwCreateWindow(1024, 768, "Hello World", NULL, NULL);

    if (window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glewExperimental = true;

    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
        glClear(GL_COLOR_BUFFER_BIT);
            
        loop();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    return 0;
}
