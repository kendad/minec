#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class Texture {
public:
	Texture(std::string filePath, bool flip = true, bool hasAlpha = true);

	void activate(unsigned int shaderID, std::string textureName, int textureUnit);

	unsigned int ID;
};
