#include "cube.h"
#include "mesh_type.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Cube::Cube(std::string textureFilePath, bool flip, bool hasAlpha) {
	shader = new Shader("Shaders/shader.vs", "Shaders/shader.fs");
	texture = new Texture(textureFilePath, flip, hasAlpha);
	configure();
}

unsigned int Cube::getShaderID() { return shader->ID; }

void Cube::configure() {
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//bind the EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

	//Attribute configuration at 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//Attribute configuration at 1
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//Attribute configuration at 2
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);


	//unbind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//unbind the VAO
	glBindVertexArray(0);
	//unbind the EBO-->always unbind this after unbinding VAO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cube::activate() {
	shader->use();
	//set texture in shader.fs
	texture->activate(shader->ID, "texture1", 0);
	//set color in shader.fs
	unsigned int objectColorLoc = glGetUniformLocation(shader->ID, "objectColor");
	unsigned int lightColorLoc = glGetUniformLocation(shader->ID, "lightColor");
	unsigned int lightPositionLoc = glGetUniformLocation(shader->ID, "lightPosition");
	glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
	glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
	glUniform3f(lightPositionLoc, 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(shader->ID, "material.diffuseColor"), 1.0f, 0.5f, 0.31f);
	glUniform3f(glGetUniformLocation(shader->ID, "material.ambientColor"), 1.0f, 0.5f, 0.31f);
	glUniform3f(glGetUniformLocation(shader->ID, "material.specularColor"), 0.5f, 0.5f, 0.5f);
	glUniform1f(glGetUniformLocation(shader->ID, "material.shininess"), 32.0f);
}

void Cube::render() {
	//activate the shader for use and also update the texture units
	activate();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);//3 vertices makes a triangle
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Cube::update() {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	unsigned int modelLoc = glGetUniformLocation(shader->ID, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}