#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globals.h"

bool IS_MOUSE_CAPTURED = true;

GLFWwindow* window = nullptr;
Camera* gCamera = nullptr;

void INIT() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create window context
	GLFWwindow* _window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Learning", NULL, NULL);
	if (_window == NULL) {
		std::cout << "failed to create window" << std::endl;
		glfwTerminate();
		return;
	}
	//update the global window variable
	window = _window;
	//make the current window in the current thread
	glfwMakeContextCurrent(window);
	//resize the window when users changes screen size
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//set mouse callback
	glfwSetCursorPosCallback(window, mouse_callback);

	//load GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "failed to init GLAD" << std::endl;
		return;
	}
}

//#######################################################################################################################
// CALLBACK FUNCTIONS
//#######################################################################################################################
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window, float& deltaTime) {
	float cameraSpeed = (float)(2.5 * deltaTime);

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	gCamera->processKeyboardInput(deltaTime);
}

void mouse_callback(GLFWwindow* window, double xPos, double yPos) {
	gCamera->processMouseMovement(xPos, yPos);
}
//#######################################################################################################################