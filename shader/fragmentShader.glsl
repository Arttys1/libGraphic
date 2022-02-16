#version 330 core
in vec2 texturePosition;
out vec4 FragColor;
uniform vec3 color;
uniform sampler2D ourTexture;
uniform bool readTexture;
void main()
{
	if(readTexture)	//case with texture
	{	
		FragColor =  texture(ourTexture, texturePosition) * vec4(color, 1.0);
	}
	else			//case without
	{
		FragColor =  vec4(color, 1.0);
	}
}