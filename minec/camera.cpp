#include "camera.h"

Camera::Camera(GLFWwindow* _window, glm::vec3 _position, float _yaw, float _pitch, float _lastX, float _lastY) {
	window = _window;

	position = _position;
	front = glm::vec3(0.0f, 0.0f, -1.0f);;
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	yaw = _yaw;
	pitch = _pitch;

	lastX = _lastX;
	lastY = _lastY;

	firstTime = true;

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Camera::processKeyboardInput(float& deltaTime) {
	float cameraSpeed = (float)(2.5 * deltaTime);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		position += front * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		position -= front * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		position -= glm::normalize(glm::cross(front, up)) * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		position += glm::normalize(glm::cross(front, up)) * cameraSpeed;
	}
}

void Camera::processMouseMovement(double xPos, double yPos, float sensitivity, float pitchLimit) {
	if (firstTime) {
		lastX = xPos;
		lastY = yPos;
		firstTime = false;
	}
	float xOffset = xPos - lastX;
	float yOffset = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	xOffset *= sensitivity;
	yOffset *= sensitivity;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 updatedFront;
	updatedFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	updatedFront.y = sin(glm::radians(pitch));
	updatedFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(updatedFront);
}