#version 330 core

in vec2 TexCoord;

in vec3 norm;
in vec3 frag_pos;

in vec3 spec_norm;
in vec3 spec_frag_pos;

in vec4 frag_pos_light_space;

out vec4 color;

uniform int shadowtoggle; 

uniform sampler2D theTexture;
uniform sampler2D shadowMap;
uniform vec4 col;
uniform float ambientIntensity;

uniform vec3 light_position;
uniform vec3 view_position;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, projCoords.xy).r; 
    // get depth of current fragment from light's perspective
    float currentDepth = projCoords.z;


	 vec3 normal = normalize(norm);
    vec3 lightDir = normalize(light_position - frag_pos);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.001);


	    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= 9.0;

	    if(projCoords.z > 1.0)
        shadow = 0.0;

    // check whether current frag pos is in shadow
   // float shadow = currentDepth > closestDepth  ? 1.0 : 0.0;
   if(shadowtoggle == 0)
	shadow = 0.0;
   return shadow;
}

void main()
{
	vec3 lightColor = vec3(1.0f,1.0f,1.0f); //default is white
    //vec3 ambient = 0.25f * lightColor; //replace 0.2f with ambientIntensity
	vec3 ambient = ambientIntensity * lightColor;
   
   vec3 light_dir = normalize(light_position - frag_pos);
   vec3 normal = normalize(norm);

   //diffuse readying
   float diffuseintensity = .75f;
   float angle = dot(normal,light_dir);
   float diffusal = max(angle, 0.0);
   vec3 diffuse = diffuseintensity*diffusal * lightColor;

   //specular
   	float specularStrength = .75;
   	vec3 spec_light_dir = normalize(light_position - spec_frag_pos);
	vec3 view_dir = normalize(view_position - spec_frag_pos);
	vec3 reflect_dir = reflect(-spec_light_dir, normalize(spec_norm)); 

	float spec = pow(max(dot(reflect_dir,view_dir), 0.0), 64);
	vec3 specular = specularStrength * spec * lightColor; 

	vec4 result = vec4(ambient + specular  +diffuse,1);
   // color = texture(theTexture,TexCoord) * result * col;

	float shadow = ShadowCalculation(frag_pos_light_space);                      
    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) ; 

	color = vec4(lighting,1.0f) *texture(theTexture,TexCoord) * col;
} 
