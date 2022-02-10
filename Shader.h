#pragma once
#include "GL/glew.h"
#include <string>

namespace libGraphic
{
	class Shader
	{
	private:
		unsigned int id;
		void checkCompileErrors(unsigned int shader, std::string type);

	public:
		Shader(const char* pathVertexShader, const char* pathfragmentShader);
		~Shader();

		void use() const;
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
		unsigned int getId() const;
	};
}
