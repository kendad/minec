#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "globals.h"

bool IS_MOUSE_CAPTURED = true;

float SCALING_BIAS = 2.8f;
float SCALING_BIAS_PREV = SCALING_BIAS;

float RAYCAST_ITERATOR = 0.5;

GLFWwindow* window = nullptr;
Camera* gCamera = nullptr;
mCube* gMCube = nullptr;

int X_OFFSET=1;
int Y_OFFSET=0;
int Z_OFFSET=0;

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
	//set mouse cursor callback
	glfwSetCursorPosCallback(window, mouse_callback);
	//set mouse click callback
	glfwSetMouseButtonCallback(window, mouse_click_callback);
	//set mouse scroll callback
	glfwSetScrollCallback(window, mouse_scroll_callback);
	//set keyboard input callback
	glfwSetKeyCallback(window, keyboard_input_callback);

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

void mouse_click_callback(GLFWwindow* window,int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		gCamera->modifyWorld();
	}
}

void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	if (X_OFFSET != 0) {
		if (yoffset > 0) X_OFFSET = 1;
		if (yoffset < 0) X_OFFSET = -1;
	}
	if (Y_OFFSET != 0) {
		if (yoffset > 0) Y_OFFSET = 1;
		if (yoffset < 0) Y_OFFSET = -1;
	}
	if (Z_OFFSET != 0) {
		if (yoffset > 0) Z_OFFSET = 1;
		if (yoffset < 0) Z_OFFSET = -1;
	}
}

void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//set mouse Cursor Mode
	if (key == GLFW_KEY_M && action == GLFW_PRESS) {
		IS_MOUSE_CAPTURED = !IS_MOUSE_CAPTURED;
		if (IS_MOUSE_CAPTURED) glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		else glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	//set which direction we want to modify
	if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
		Z_OFFSET = 1; X_OFFSET = 0; Y_OFFSET = 0;
	}
	if (key == GLFW_KEY_X && action == GLFW_PRESS) {
		X_OFFSET = 1; Z_OFFSET = 0; Y_OFFSET = 0;
	}
	if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
		Y_OFFSET = 1; X_OFFSET = 0; Z_OFFSET = 0;
	}
}
//#######################################################################################################################
bool checkScalingBias() {//-->change scaling bias value in order to change terrain from IMGUI
	if (SCALING_BIAS == SCALING_BIAS_PREV) { return false; }
	if (SCALING_BIAS != SCALING_BIAS_PREV) { SCALING_BIAS_PREV = SCALING_BIAS; return true; }
}