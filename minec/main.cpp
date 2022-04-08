#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>
#include "globals.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "shader.h"
#include "texture.h"
#include "camera.h"
#include "cube.h"
#include "edit_cube.h"
#include "crosshair.h"
#include "mesh_type.h"

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
	Cube cube("Textures/minecraft.png", false,true);
	eCube eCube("Textures/minecraft.png", false, true);
	//create Crosshair
	Crosshair crosshair;

	//projection matrix
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
	//set projection for CUBE
	cube.activate();
	unsigned int projectionLoc = glGetUniformLocation(cube.getShaderID(), "projection");//for CUBE
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	//set projection for eCUBE
	eCube.activate();
	projectionLoc = glGetUniformLocation(eCube.getShaderID(), "projection");//for eCUBE
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	//set projection for CROSSHAIR
	crosshair.activate();
	projectionLoc = glGetUniformLocation(crosshair.getShaderID(), "projection");//for CROSSHAIR
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//Activate IMGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window,true);
	ImGui_ImplOpenGL3_Init("#version 330");

	//render Loop
	glEnable(GL_DEPTH_TEST);//enable depth testing
	glEnable(GL_BLEND);//enable PNG transperency
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_CULL_FACE);
	while (!glfwWindowShouldClose(window)) {
		//get time
		float currentTime = (float)glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		//process user input
		processInput(window, deltaTime);
		camera.raycast(eCube);

		//all render stuff goes here
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//set up IMGUI for rendering
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		//change world terrain if scaling bias change
		if (checkScalingBias()) {
			cubeVertexData.clear();
			generateWorld();
			cube.configure();
		}


		//Update view Matrix
		glm::mat4 view = glm::lookAt(gCamera->position, gCamera->position + gCamera->front, gCamera->up);
		//set view for CUBE
		cube.activate();
		unsigned int viewLoc = glGetUniformLocation(cube.getShaderID(), "view");//for CUBE
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		//set view for eCUBE
		eCube.activate();
		viewLoc = glGetUniformLocation(eCube.getShaderID(), "view");//for eCUBE
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		//set view for Crosshair
		crosshair.activate();
		viewLoc = glGetUniformLocation(crosshair.getShaderID(), "view");//for CROSSHAIR
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
		

		//draw stuff here
		//update and render cube
		//-->eCube
		eCube.activate();
		eCube.update();
		eCube.render();

		//-->CUBE
		cube.activate();
		cube.update();
		cube.render();
		
		//--crosshair
		crosshair.activate();
		crosshair.update();
		crosshair.render();

		//render IMGUI stuff here
		ImGui::Begin("Controls");
		ImGui::SliderFloat("ScalingBias", &SCALING_BIAS, 0, 10);
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//End IMGUI here
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	//exit
	glfwTerminate();
	return;
}
