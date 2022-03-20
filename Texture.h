#pragma once
#ifndef H_TEXTURE
#define H_TEXTURE

namespace libGraphic
{
	class Texture
	{
	private:
		unsigned int texture;
		int id;
	public:
		Texture(const char* path);
		~Texture();
		int getId() const;

		void use();
		static void initTexture();
	};
}

#endif // !H_TEXTURE
