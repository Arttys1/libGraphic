#version 330 core
in vec2 texturePosition;
in vec3 normal;
in vec3 fragPos;

out vec4 FragColor;

uniform vec3 cameraPosition;
uniform vec3 color;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 ambientColor;
uniform float ambientStrength;
uniform float specularStrength;

uniform sampler2D texture1;
uniform bool readTexture;

void main()
{
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPosition - fragPos);

	//compute ambient color
	vec3 ambient = ambientStrength * ambientColor;	 
	
	//compute diffuse color	
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	//compute specular color
	vec3 viewDir = normalize(cameraPosition - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm); 
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 2);
	vec3 specular = 1.0 * spec * lightColor; 

	vec3 result = (ambient + diffuse + specular) * color;

	if(readTexture)	//case with texture
	{	
		FragColor =  texture(texture1, texturePosition) * vec4(result, 1.0);
	}
	else			//case without
	{
		FragColor =  vec4(result, 1.0);
	}
}