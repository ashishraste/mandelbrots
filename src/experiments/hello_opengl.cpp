// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

/* Callbacks for OpenGL window events. */
static void glfw_error_callback(int error, const char* description);

/* Static constants. */
static const int window_width = 1024;
static const int window_height = 768;

int main(void) {
  
  glfwSetErrorCallback(glfw_error_callback);

  // Initialize GLFW.
  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    getchar();
    return -1;
  }
  
  // Minimum-OpenGL-version hints.
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Open a window and initialize its OpenGL context.
  window = glfwCreateWindow(window_width, window_height, "Hello OpenGL", NULL, NULL);
  if (window == NULL ) {
    fprintf( stderr, "Failed to open GLFW window.");
    getchar();
    glfwTerminate();
    return -1;
  }
  
  // Set the current window's context for OpenGL API.
  glfwMakeContextCurrent(window);
  
  // Initialize GLEW.
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    getchar();
    glfwTerminate();
    return -1;
  }
  
  // Enable key capture.
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  
  glClearColor(0.0f, 0.4f, 0.4f, 0.0);
  
  // Run loop.
  do {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
  
  glfwDestroyWindow(window);
  glfwTerminate();
  
  fprintf(stdout, "hello_opengl is exiting safely.");
  return 0;
  
}

static void glfw_error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}
