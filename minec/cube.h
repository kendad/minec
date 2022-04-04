#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "texture.h"

class Cube {
public:
	Cube(std::string textureFilePath, bool flip, bool hasAlpha);

	//update the cube data
	void update();
	//render the cube
	void render();

	//get shader ID
	unsigned int getShaderID();

	//activate the shader
	void activate();

private:
	Shader* shader;
	Texture* texture;

	unsigned int VBO, VAO, EBO;

	//update the VBO EBO attribPointers VAO
	void configure();
};
