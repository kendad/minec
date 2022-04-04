#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aNormal;
layout (location=2) in vec2 aTexCoord;

out vec3 Normal;
out vec2 TexCoord;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	gl_Position=projection*view*model*vec4(aPos.x,aPos.y,aPos.z,1.0);
	FragPos=vec3(model*vec4(aPos,1));
	Normal=mat3(transpose(inverse(model)))*aNormal;//try making this normal matrix in cpu and pass it as an uniform value
	TexCoord=aTexCoord;
	}