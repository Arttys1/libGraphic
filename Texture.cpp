#include "Texture.h"
#include <GL/glew.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace libGraphic
{
	static int maxId;
	Texture::Texture(const char* path) 
		: data(nullptr), widthImage(0), heightImage(0), texture(0), id(++maxId)
	{
		glGenTextures(1, &texture);
		glActiveTexture(GL_TEXTURE0 + id); // activate the texture unit first before binding texture
		glBindTexture(GL_TEXTURE_2D, texture);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);	//allow color image

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture
		data = stbi_load(path, &widthImage, &heightImage, 0, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthImage, heightImage, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
	}
	Texture::~Texture()
	{
		//clean memory
		if (data != NULL)
		{
			//delete data;
			data = NULL;
		}
		glDeleteBuffers(1, &texture);
	}
	int Texture::getId() const
	{
		return id;
	}
	void Texture::use()
	{
		glActiveTexture(GL_TEXTURE0 + id);
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	void Texture::initTexture()
	{
		maxId = 0;
	}
}