#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texPosition;
uniform mat4 transform;
out vec2 texturePosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
	gl_Position = projection * view * model * transform * vec4(position, 1.0);
	texturePosition = texPosition;
}