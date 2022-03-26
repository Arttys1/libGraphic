#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texPosition;
layout (location = 2) in vec3 normalVector;

out vec2 texturePosition;
out vec3 normal;
out vec3 fragPos;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * transform * vec4(position, 1.0);
	texturePosition = texPosition;
	normal = normalVector;
	fragPos = vec3(model * vec4(position, 1.0));
}