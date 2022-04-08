#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.h"
#include "mod_cube.h"


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

extern bool IS_MOUSE_CAPTURED;

extern float SCALING_BIAS;
extern float SCALING_BIAS_PREV;

extern float RAYCAST_ITERATOR;

//window value created on intilization
extern GLFWwindow* window;

extern Camera* gCamera;

extern mCube* gMCube;

//intialize GLFW for processing
extern void INIT();

//Varibales to control Modified Cube Offser
extern int X_OFFSET;
extern int Y_OFFSET;
extern int Z_OFFSET;

//#######################################################################################################################
// CALLBACK FUNCTIONS
//#######################################################################################################################
//window resize callback function
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//process user input
extern void processInput(GLFWwindow* window, float& deltaTime);
//mouse callback cursor function
extern void mouse_callback(GLFWwindow* window, double xPos, double yPos);
//mouse click callback function
extern void mouse_click_callback(GLFWwindow* window,int button, int action, int mods);
//mouse scroll callback
extern void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//keyboard input callback function
extern void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
//#######################################################################################################################

//check if the ScalingBias has changed
bool checkScalingBias();