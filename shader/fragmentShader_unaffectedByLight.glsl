#version 330 core
in vec2 texturePosition;

out vec4 FragColor;

uniform vec3 color;

uniform sampler2D texture1;
uniform bool readTexture;

void main()
{
	vec3 result = color;

	if(readTexture)	//case with texture
	{	
		FragColor =  texture(texture1, texturePosition) * vec4(result, 1.0);
	}
	else			//case without
	{
		FragColor =  vec4(result, 1.0);
	}
}