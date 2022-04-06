#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.h"


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

extern bool IS_MOUSE_CAPTURED;

extern float SCALING_BIAS;
extern float SCALING_BIAS_PREV;

//window value created on intilization
extern GLFWwindow* window;

extern Camera* gCamera;

//intialize GLFW for processing
extern void INIT();


//#######################################################################################################################
// CALLBACK FUNCTIONS
//#######################################################################################################################
//window resize callback function
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//process user input
extern void processInput(GLFWwindow* window, float& deltaTime);
//mouse callback function
extern void mouse_callback(GLFWwindow* window, double xPos, double yPos);
//#######################################################################################################################
//check if the ScalingBias has changed
bool checkScalingBias();