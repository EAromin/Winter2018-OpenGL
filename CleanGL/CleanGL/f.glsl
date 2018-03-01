#version 330 core

in vec2 TexCoord;

out vec4 color;
uniform sampler2D theTexture;
uniform vec4 col;
uniform float ambientIntensity;
void main()
{
	vec3 lightColor = vec3(1.0f,1.0f,1.0f); //default is white
    vec3 ambient = 0.55f * lightColor; //replace 0.2f with ambientIntensity
	vec3 result = ambient * vec3(col.x,col.y,col.z);
    color = texture(theTexture,TexCoord) * vec4(result,1.0f);
} 