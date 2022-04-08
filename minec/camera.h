#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "edit_cube.h"

class Camera {
public:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;

	Camera(GLFWwindow* _window, glm::vec3 _position, float _yaw, float _pitch, float _lastX, float _lastY);
	void processKeyboardInput(float& deltaTime);
	void processMouseMovement(double xPos, double yPos, float sensitivity = 0.1f, float pitchLimit = 89.0f);

	//raycast for object detection
	void raycast(eCube& cube);

	//modify world on mouse click
	void modifyWorld();
	void deleteCube();

private:
	float yaw;
	float pitch;
	float lastX, lastY;

	bool firstTime;

	GLFWwindow* window;
};
