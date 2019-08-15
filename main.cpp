#include <iostream>
#include <thread>
#include <chrono>

// GLAD
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>
#include "Shader.h"

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

/**
 * Encapsulates the data for a single vertex.
 * Must match the vertex shader's input.
 */
typedef struct Vertex_s {
    float position[2];
} Vertex;

/**
 * Creates a VBO containing the given vertices.
 * @param vertices
 * @param numVertices
 * @return
 */
GLuint vboCreate(const Vertex *vertices, GLuint numVertices) {
    GLuint buffer;
    int nBuffers = 1;
    glGenBuffers(nBuffers, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    // Copy the vertex data in, and deactivate
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * numVertices, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Check for problems
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
    {
        std::cout << "Error: " << err << "\n";
        buffer = 0;
    }
    return buffer;
}

/**
 * Frees the vbo
 * @param vbo
 */
void vboFree(GLuint vbo) {
    glDeleteBuffers(1, &vbo);
}

// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 4.1" << std::endl;
    // Init GLFW
    if (!glfwInit()) {
        std::cout << "didnt init properly";
        return 2;
    }
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GL_FALSE);

    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Test", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    if (window == nullptr)
    {
        const char* result = nullptr;
        glfwGetError(&result);
        std::cout << result;
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    GLuint shaderProg = shaderProgLoad("Simple2D.vert", "Simple2D.frag");
    if (!shaderProg) {
        // Error messages already displayed..
        return EXIT_FAILURE;
    }
    glUseProgram(shaderProg);

    const Vertex vertices[] = {
        { 1.0f, -1.0f },
        { 1.0f, 1.0f },
        {-1.0f, 1.0f }
    };
    GLsizei vertSize = sizeof(Vertex);
    GLsizei numVertices = sizeof(vertices) / vertSize;

    GLuint buffer = vboCreate(vertices, numVertices);

    if (!buffer) {
        std::cout << "No VBO\n";
        return EXIT_FAILURE;
    }

    // Set up for rendering the triangle (activate the VBO)
    GLuint positionIndex = 0; // Position is vertex attribute 0
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(positionIndex, 2, GL_FLOAT, GL_FALSE, 2, (void*)0);
    glEnableVertexAttribArray(positionIndex);

    // Main loop
//    while (!glfwWindowShouldClose(window))
//    {
        // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        // DRAAW
        // Clear the colorbuffer
        glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
        glClear((unsigned) GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << ".";
        std::cout.flush();
//    }

    // Terminates GLFW, clearing any resources allocated by GLFW.
    vboFree(buffer);
    buffer = 0;
    shaderProgDestroy(shaderProg);
    shaderProg = 0;
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
