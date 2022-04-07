#include "crosshair.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Crosshair::Crosshair() {
	shader = new Shader("Shaders/crosshair.vs", "Shaders/crosshair.fs");
	texture = new Texture("Textures/crosshair.png", false, true);
	configure();
}

unsigned int Crosshair::getShaderID() { return shader->ID; }

void Crosshair::configure() {
	//activate the shader first before binding the buffers
	shader->use();
	//generate the buffers
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	//bind the VAO first
	glBindVertexArray(VAO);

	//bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(crosshairPlane), crosshairPlane, GL_STATIC_DRAW);

	//Attribute configuration at 0-->vertex Positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//Attribute configuration at 2-->texture coords
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	//unbind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//unbind the VAO
	glBindVertexArray(0);
}

void Crosshair::activate() {
	shader->use();
	//set texture in shader.fs
	texture->activate(shader->ID, "texture1", 0);
}

void Crosshair::render() {
	//activate the shader for use and also update the texture units
	activate();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void Crosshair::update() {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(0.2f));
	unsigned int modelLoc = glGetUniformLocation(shader->ID, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}