#include <iostream>
#include "globals.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "shader.h"
#include "texture.h"
#include "camera.h"
#include "cube.h"

//screen settings
const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

//timing
float deltaTime = 0.0f;
float lastTime = 0.0f;

void main() {
	//intialize GLFW & GLAD
	INIT();

	//Camera Class
	Camera camera(window, glm::vec3(0.0f, 0.0f, 3.0f), -90.0f, 0.0f, SCR_WIDTH / 2, SCR_HEIGHT / 2);
	gCamera = &camera;//update the global camera variable

	//#######################################################################################################################
	//create cube for render
	Cube cube("Textures/wall.jpg", true, false);

	//projection matrix
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
	//set projection for CUBE
	cube.activate();
	unsigned int projectionLoc = glGetUniformLocation(cube.getShaderID(), "projection");//for CUBE
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//render Loop
	glEnable(GL_DEPTH_TEST);//enable depth testing
	//glEnable(GL_CULL_FACE);
	while (!glfwWindowShouldClose(window)) {
		//get time
		float currentTime = (float)glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		//process user input
		processInput(window, deltaTime);

		//all render stuff goes here
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Update view Matrix
		glm::mat4 view = glm::lookAt(gCamera->position, gCamera->position + gCamera->front, gCamera->up);
		//set view for CUBE
		cube.activate();
		unsigned int viewLoc = glGetUniformLocation(cube.getShaderID(), "view");//for CUBE
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		unsigned int cameraPos = glGetUniformLocation(cube.getShaderID(), "cameraPos");
		glUniform3fv(cameraPos, 1, glm::value_ptr(gCamera->position));

		//draw stuff here
		//update and render cube
		cube.activate();
		cube.update();
		cube.render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//exit
	glfwTerminate();
	return;
}
