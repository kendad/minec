#version 330 core 

out vec4 FragColor; 
in vec2 TexCoord;

uniform sampler2D texture1;

void main() { 
    FragColor=texture(texture1,TexCoord)*vec4(0.3f,0.3f,0.3f,1.0f); 
}