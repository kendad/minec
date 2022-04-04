#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(std::string filePath, bool flip, bool hasAlpha) {
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, colorChannels;
	stbi_set_flip_vertically_on_load(flip);
	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &colorChannels, 0);
	if (data) {
		if (hasAlpha) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		else {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Error Loading Texture" << "\n";
	}
	stbi_image_free(data);
}

void Texture::activate(unsigned int shaderID, std::string textureName, int textureUnit) {
	glUniform1i(glGetUniformLocation(shaderID, textureName.c_str()), textureUnit);
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, ID);
}