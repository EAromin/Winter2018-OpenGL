#version 330 core

in vec2 TexCoord;

in vec3 norm;
in vec3 frag_pos;

in vec3 spec_norm;
in vec3 spec_frag_pos;



out vec4 color;


uniform sampler2D theTexture;
uniform vec4 col;
uniform float ambientIntensity;

uniform vec3 light_position;
uniform vec3 view_position;

void main()
{
	vec3 lightColor = vec3(1.0f,1.0f,1.0f); //default is white
    //vec3 ambient = 0.25f * lightColor; //replace 0.2f with ambientIntensity
	vec3 ambient = ambientIntensity * lightColor;
   
   vec3 light_dir = normalize(light_position - frag_pos);
   vec3 normal = normalize(norm);

   //diffuse readying
   float angle = dot(normal,light_dir);
   float diffusal = max(angle, 0.0);
   vec3 diffuse = diffusal * lightColor;

   //specular
   	float specularStrength = .75;
   	vec3 spec_light_dir = normalize(light_position - spec_frag_pos);
	vec3 view_dir = normalize(view_position - spec_frag_pos);
	vec3 reflect_dir = reflect(-spec_light_dir, normalize(spec_norm)); 

	float spec = pow(max(dot(reflect_dir,view_dir), 0.0), 64);
	vec3 specular = specularStrength * spec * lightColor; 

   	//vec3 result = ambient * vec3(col.x,col.y,col.z);
	vec4 result = vec4(ambient + specular  +diffuse,1);
	//vec4 result = vec4(specular+ambient,1);
    color = texture(theTexture,TexCoord) * result * col;
} 