#include "camera.h"
#include "globals.h"
#include "mesh_type.h"

int gLocation = 0;
std::string vectorName = "WORLD";//"WORLD" or "MOD"

//Create a block with transperency
void transparentBlock(int location,eCube& cube);

Camera::Camera(GLFWwindow* _window, glm::vec3 _position, float _yaw, float _pitch, float _lastX, float _lastY) {
	window = _window;

	position = _position;
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	yaw = _yaw;
	pitch = _pitch;

	lastX = _lastX;
	lastY = _lastY;

	firstTime = true;
	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Camera::processKeyboardInput(float& deltaTime) {
	float cameraSpeed = (float)(50 * deltaTime);

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
	if (IS_MOUSE_CAPTURED) {
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
	else {
		firstTime = true;
	}
}

void Camera::raycast(eCube& cube) {
	glm::vec3 ray = position + (front * RAYCAST_ITERATOR);//generate ray from camera and scale it to x val:-default=3.5f
	//go through the cubeVertexData Vector and check if the rays position is inside any of the cubes
	for (int i = 0; i < cubeVertexData.size(); i += 36) {
		//top-right of the top face
		glm::vec3 max = glm::vec3(cubeVertexData[i + 32].x, cubeVertexData[i + 32].y, cubeVertexData[i + 32].z);
		//bottom right of my bottom face
		glm::vec3 min = glm::vec3(cubeVertexData[i + 28].x, cubeVertexData[i + 28].y, cubeVertexData[i + 28].z);
		//check if ray position lies inside the cube
		bool condition1 = min.x <= ray.x && ray.x <= max.x;
		bool condition2 = min.y <= ray.y && ray.y <= max.y;
		bool condition3 = max.z <= ray.z && ray.z <= min.z;
		//if all conditions are TRUE then collision has been detected at psoition 'i'
		if (condition1 == true && condition2 == true && condition3 == true) {
			vectorName = "WORLD";
			transparentBlock(i, cube);
			RAYCAST_ITERATOR = 0.5;//reset Raycast iterator
		}
	}
	//go through the modifiedCubeVertexData Vector and check if the rays position is inside any of the cubes
	for (int i = 0; i < modifiedCubeVertexData.size(); i += 36) {
		//top-right of the top face
		glm::vec3 max = glm::vec3(modifiedCubeVertexData[i + 32].x, modifiedCubeVertexData[i + 32].y, modifiedCubeVertexData[i + 32].z);
		//bottom right of my bottom face
		glm::vec3 min = glm::vec3(modifiedCubeVertexData[i + 28].x, modifiedCubeVertexData[i + 28].y, modifiedCubeVertexData[i + 28].z);
		//check if ray position lies inside the cube
		bool condition1 = min.x <= ray.x && ray.x <= max.x;
		bool condition2 = min.y <= ray.y && ray.y <= max.y;
		bool condition3 = max.z <= ray.z && ray.z <= min.z;
		//if all conditions are TRUE then collision has been detected at psoition 'i'
		if (condition1 == true && condition2 == true && condition3 == true) {
			vectorName = "MOD";
			transparentBlock(i, cube);
			RAYCAST_ITERATOR = 0.5;//reset Raycast iterator
		}
	}
	RAYCAST_ITERATOR += 1;
	if (RAYCAST_ITERATOR >= 30) RAYCAST_ITERATOR = 0.5;
}

void transparentBlock(int location,eCube& cube) {
	gLocation = location;
	if (vectorName == "WORLD") {
		editableCubeVertexData.clear();
		for (int i = 0; i < 36; i++) {
			CubeVertex tempVertex;
			tempVertex.x = cubeVertexData[location + i].x;
			tempVertex.y = cubeVertexData[location + i].y;
			tempVertex.z = cubeVertexData[location + i].z;
			tempVertex.u = cubeVertexData[location + i].u;
			tempVertex.v = cubeVertexData[location + i].v;
			editableCubeVertexData.push_back(tempVertex);
		}
	}
	if (vectorName == "MOD") {
		editableCubeVertexData.clear();
		for (int i = 0; i < 36; i++) {
			CubeVertex tempVertex;
			tempVertex.x = modifiedCubeVertexData[location + i].x;
			tempVertex.y = modifiedCubeVertexData[location + i].y;
			tempVertex.z = modifiedCubeVertexData[location + i].z;
			tempVertex.u = modifiedCubeVertexData[location + i].u;
			tempVertex.v = modifiedCubeVertexData[location + i].v;
			editableCubeVertexData.push_back(tempVertex);
		}
	}

	cube.configure();
}

void Camera::modifyWorld() {
	if (editableCubeVertexData.size() > 0) {
		if (vectorName == "WORLD") {
			for (int i = 0; i < 36; i++) {
				CubeVertex tempVertex;
				tempVertex.x = cubeVertexData[gLocation + i].x+X_OFFSET;
				tempVertex.y = cubeVertexData[gLocation + i].y+Y_OFFSET;
				tempVertex.z = cubeVertexData[gLocation + i].z+Z_OFFSET;
				tempVertex.u = cubeVertexData[gLocation + i].u;
				tempVertex.v = cubeVertexData[gLocation + i].v;

				modifiedCubeVertexData.push_back(tempVertex);
			}
		}
		if (vectorName == "MOD") {
			for (int i = 0; i < 36; i++) {
				CubeVertex tempVertex;
				tempVertex.x = modifiedCubeVertexData[gLocation + i].x+X_OFFSET;
				tempVertex.y = modifiedCubeVertexData[gLocation + i].y+Y_OFFSET;
				tempVertex.z = modifiedCubeVertexData[gLocation + i].z+Z_OFFSET;
				tempVertex.u = modifiedCubeVertexData[gLocation + i].u;
				tempVertex.v = modifiedCubeVertexData[gLocation + i].v;

				modifiedCubeVertexData.push_back(tempVertex);
			}
		}
	}
	gMCube->configure();
}