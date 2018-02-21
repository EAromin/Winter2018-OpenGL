#version 330 core

out vec4 color;
uniform vec4 col;
uniform float ambientIntensity;
void main()
{
	vec3 lightColor = vec3(1.0f,1.0f,1.0f); //default is white
    vec3 ambient = 0.55f * lightColor; //replace 0.2f with ambientIntensity
	vec3 result = ambient * vec3(col.x,col.y,col.z);
    color = vec4(result,1.0f);
} 