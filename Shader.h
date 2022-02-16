#pragma once
#include "GL/glew.h"
#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace libGraphic
{
	class Shader
	{
	private:
		unsigned int id;
		void checkCompileErrors(unsigned int shader, std::string type);
		std::string* readFile(const char* path) const;

	public:
		Shader(const char* pathVertexShader, const char* pathfragmentShader);
		~Shader();

		void use() const;
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
		void setMat4(const std::string& name, glm::mat4 value) const;
		void setMat3(const std::string& name, glm::mat3 value) const;
		void setVec3(const std::string& name, glm::vec3 value) const;
		unsigned int getId() const;
	};
}
