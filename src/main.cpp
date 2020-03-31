#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main() {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cout << "GLFW Initialization failed!" << std::endl;
    glfwTerminate();
    return 1;
  }

  // Setup GLFW window properties
  // OpenGL version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // Core Profile = No Backwards Compatibility
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // Allow Forward Compatibility
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", NULL, NULL);
  if (!mainWindow) {
    std::cout << "GLFW window creation failed!" << std::endl;
    glfwTerminate();
    return 1;
  }

  // Get buffer size information
  int bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

  // Set context for GLEW to use
  glfwMakeContextCurrent(mainWindow);

  // Allow modern extension features
  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW Initialization failed!" << std::endl;
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    return 1;
  }

  // Setup viewport size
  glViewport(0, 0, bufferWidth, bufferHeight);

  float test = 0.0f;
  float inc = 0.01f;

  std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

  // Loop until window closed
  while (!glfwWindowShouldClose(mainWindow)) {
    // Get + Handle user input events
    glfwPollEvents();

    test += inc;

    // Clear window
    glClearColor(test, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if (test >= 1 || test <= 0) 
      inc = -inc;

    glfwSwapBuffers(mainWindow);
  }

  return 0;
}