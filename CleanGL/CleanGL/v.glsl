
#version 330 core
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texture;
layout (location = 2) in vec3 normal;

out vec2 TexCoord;
out vec3 norm;
out vec3 frag_pos;

out vec3 spec_norm;
out vec3 spec_frag_pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 scale;
void main()
{
	gl_Position = projection * view * model * scale * vec4(position, 1.0f) ;	
	TexCoord = texture;


	norm = vec3(transpose(inverse(model)) * vec4(normal, 1.0f));
	frag_pos = vec3(model * vec4(position, 1.0f));

	spec_norm = vec3(transpose(inverse(view*model)) * vec4(normal, 1.0f));
	spec_frag_pos = vec3( (view*model)  *vec4(position, 1.0f));


}

