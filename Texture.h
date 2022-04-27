#pragma once
#ifndef H_TEXTURE
#define H_TEXTURE

#include <memory>
#include <unordered_map>

namespace libGraphic
{
	class Texture
	{
	private:
		static std::unordered_map<std::string, std::shared_ptr<Texture>> textureLoaded;
		static int maxId;

		unsigned int texture;
		int id;
	public:
		Texture(const char* path);
		~Texture();
		int getId() const;

		void use();
		static std::shared_ptr<Texture> LoadTexture(const std::string filePath);

	};
}

#endif // !H_TEXTURE
