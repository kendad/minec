#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "texture.h"
#include "mesh_type.h"

class Crosshair {
public:
	Crosshair();

	//update the cube data
	void update();
	//render the cube
	void render();

	//get shader ID
	unsigned int getShaderID();

	//activate the shader
	void activate();

	//update the VBO EBO attribPointers VAO
	void configure();

private:
	Shader* shader;
	Texture* texture;

	unsigned int VBO, VAO, EBO;
};
