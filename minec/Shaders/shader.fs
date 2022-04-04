#version 330 core 

out vec4 FragColor; 
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 cameraPos;

struct Material{
	vec3 ambientColor;
	vec3 diffuseColor;
	vec3 specularColor;
	float shininess;
};

uniform Material material;
 

void main() { 
	//Diffuse Lighting
	vec3 norm=normalize(Normal);
	vec3 lightDir=normalize(lightPosition-FragPos);
	float diff=max(dot(norm,lightDir),0.0);
	//vec3 diffuse = diff*lightColor;//intensity of the diffuse light
	vec3 diffuse = (diff*material.diffuseColor)*(lightColor*0.5f);//intensity of the diffuse light

	//ambient Lighting
	float ambientStrength=0.1f;
	//vec3 ambient=lightColor*ambientStrength;//intensity of the ambient light
	vec3 ambient=(lightColor*0.2f)*material.ambientColor;//intensity of the ambient light

	//Specular lighting
	float specularStrength=0.5f;
	vec3 viewDir=normalize(cameraPos-FragPos);
	vec3 reflectDir=reflect(-lightDir,norm);
	float spec=pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
	//vec3 specular=(spec*specularStrength)*lightColor;//intensity of the specular light
	vec3 specular=(spec*material.specularColor)*lightColor;//intensity of the specular light

	//vec3 result=(ambient)*objectColor;
	//vec3 result=(diffuse)*objectColor;
	//vec3 result=(specular)*objectColor;
	vec3 result=(ambient+diffuse+specular)*objectColor;

    //FragColor=mix(texture(texture1,TexCoord),texture(texture2,TexCoord),0.5); 
    FragColor=vec4(result, 1.0);
}