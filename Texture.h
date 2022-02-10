#pragma once
#ifndef H_TEXTURE
#define H_TEXTURE

namespace libGraphic
{
	class Texture
	{
	private:
		unsigned char* data;
		int widthImage;
		int heightImage;
		unsigned int texture;
	public:
		Texture(const char* path);
		~Texture();

		void use();
	};
}

#endif // !H_TEXTURE
