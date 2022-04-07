#pragma once
#include "cube.h"
#include <vector>

//CROSSHAIR PLANE DATA
const float crosshairPlane[] = {
    -0.02f, -0.02f, -1.0f,     0.0f, 0.0f, // Bottom-left 0.0f 0.6
     0.02f,  0.02f, -1.0f,     1.0f, 1.0f, // top-right  1.0f 1.0f
     0.02f, -0.02f, -1.0f,     1.0f, 0.0f, // bottom-right 1.0f 0.6f      
     0.02f,  0.02f, -1.0f,     1.0f, 1.0f, // top-right   1.0f 1.0f
    -0.02f, -0.02f, -1.0f,     0.0f, 0.0f, // bottom-left 0.0f 0.6f 
    -0.02f,  0.02f, -1.0f,     0.0f, 1.0f, // top-left    0.0f 1.0f
};


//CUBE DATA
const float grassCube[] = {
    // Back face
    -0.5f, -0.5f, -0.5f,     0.0f, 0.33f, // Bottom-left 0.0f 0.6
     0.5f,  0.5f, -0.5f,     1.0f, 0.0f, // top-right  1.0f 1.0f
     0.5f, -0.5f, -0.5f,     1.0f, 0.33f, // bottom-right 1.0f 0.6f      
     0.5f,  0.5f, -0.5f,     1.0f, 0.0f, // top-right   1.0f 1.0f
    -0.5f, -0.5f, -0.5f,     0.0f, 0.33f, // bottom-left 0.0f 0.6f 
    -0.5f,  0.5f, -0.5f,     0.0f, 0.0f, // top-left    0.0f 1.0f
    // Front face
    -0.5f, -0.5f,  0.5f,     0.0f, 0.33f, // bottom-left
     0.5f, -0.5f,  0.5f,     1.0f, 0.33f, // bottom-right
     0.5f,  0.5f,  0.5f,     1.0f, 0.0f, // top-right
     0.5f,  0.5f,  0.5f,     1.0f, 0.0f, // top-right
    -0.5f,  0.5f,  0.5f,     0.0f, 0.0f, // top-left
    -0.5f, -0.5f,  0.5f,     0.0f, 0.33f, // bottom-left
    // Left face
    -0.5f,  0.5f,  0.5f,     1.0f, 0.0f, // top-right
    -0.5f,  0.5f, -0.5f,     0.0f, 0.0f, // top-left
    -0.5f, -0.5f, -0.5f,     0.0f, 0.33f, // bottom-left
    -0.5f, -0.5f, -0.5f,     0.0f, 0.33f, // bottom-left
    -0.5f, -0.5f,  0.5f,     1.0f, 0.33f,// bottom-right
    -0.5f,  0.5f,  0.5f,     1.0f, 0.0f, // top-right
    // Right face
     0.5f,  0.5f,  0.5f,     0.0f, 0.0f, // top-left
     0.5f, -0.5f, -0.5f,     1.0f, 0.33f, // bottom-right
     0.5f,  0.5f, -0.5f,     1.0f, 0.0f, // top-right         
     0.5f, -0.5f, -0.5f,     1.0f, 0.33f, // bottom-right
     0.5f,  0.5f,  0.5f,     0.0f, 0.0f, // top-left
     0.5f, -0.5f,  0.5f,     0.0f, 0.33f, // bottom-left     
    // Bottom face
    -0.5f, -0.5f, -0.5f,     1.0f, 0.6f, // top-right
     0.5f, -0.5f, -0.5f,     0.0f, 0.6f, // top-left
     0.5f, -0.5f,  0.5f,     0.0f, 0.4f, // bottom-left
     0.5f, -0.5f,  0.5f,     0.0f, 0.4f, // bottom-left
    -0.5f, -0.5f,  0.5f,     1.0f, 0.4f, // bottom-right
    -0.5f, -0.5f, -0.5f,     1.0f, 0.6f, // top-right
    // Top face
    -0.5f,  0.5f, -0.5f,     0.0f, 0.6f, // top-left
     0.5f,  0.5f,  0.5f,     1.0f, 0.4f, // bottom-right
     0.5f,  0.5f, -0.5f,     1.0f, 0.6f, // top-right     
     0.5f,  0.5f,  0.5f,     1.0f, 0.4f, // bottom-right
    -0.5f,  0.5f, -0.5f,     0.0f, 0.6f, // top-left
    -0.5f,  0.5f,  0.5f,     0.0f, 0.4f // bottom-left
};

const float waterCube[] = {//water cube Vertices
    // Back face
    -0.5f, -0.5f, -0.5f,     0.0f, 1.0f,  // Bottom-left 0.0f 0.6
     0.5f,  0.5f, -0.5f,     1.0f, 0.67f, // top-right  1.0f 1.0f
     0.5f, -0.5f, -0.5f,     1.0f, 1.0f, // bottom-right 1.0f 0.6f      
     0.5f,  0.5f, -0.5f,     1.0f, 0.67f, // top-right   1.0f 1.0f
    -0.5f, -0.5f, -0.5f,     0.0f, 1.0f, // bottom-left 0.0f 0.6f 
    -0.5f,  0.5f, -0.5f,     0.0f, 0.67f, // top-left    0.0f 1.0f
    // Front face
    -0.5f, -0.5f,  0.5f,     0.0f, 1.0f, // bottom-left
     0.5f, -0.5f,  0.5f,     1.0f, 1.0f, // bottom-right
     0.5f,  0.5f,  0.5f,     1.0f, 0.67f, // top-right
     0.5f,  0.5f,  0.5f,     1.0f, 0.67, // top-right
    -0.5f,  0.5f,  0.5f,     0.0f, 0.67f, // top-left
    -0.5f, -0.5f,  0.5f,     0.0f, 1.0f, // bottom-left
    // Left face
    -0.5f,  0.5f,  0.5f,     1.0f, 0.67f, // top-right
    -0.5f,  0.5f, -0.5f,     0.0f, 0.67f, // top-left
    -0.5f, -0.5f, -0.5f,     0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f, -0.5f,     0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f,  0.5f,     1.0f, 1.0f,// bottom-right
    -0.5f,  0.5f,  0.5f,     1.0f, 0.67f, // top-right
    // Right face
     0.5f,  0.5f,  0.5f,     0.0f, 0.67f, // top-left
     0.5f, -0.5f, -0.5f,     1.0f, 1.0f, // bottom-right
     0.5f,  0.5f, -0.5f,     1.0f, 0.67f, // top-right         
     0.5f, -0.5f, -0.5f,     1.0f, 1.0f, // bottom-right
     0.5f,  0.5f,  0.5f,     0.0f, 0.67f, // top-left
     0.5f, -0.5f,  0.5f,     0.0f, 1.0f, // bottom-left     
    // Bottom face
    -0.5f, -0.5f, -0.5f,     1.0f, 0.67f, // top-right
     0.5f, -0.5f, -0.5f,     0.0f, 0.67f, // top-left
     0.5f, -0.5f,  0.5f,     0.0f, 1.0f, // bottom-left
     0.5f, -0.5f,  0.5f,     0.0f, 1.0f, // bottom-left
    -0.5f, -0.5f,  0.5f,     1.0f, 1.0f, // bottom-right
    -0.5f, -0.5f, -0.5f,     1.0f, 0.67f, // top-right
    // Top face
    -0.5f,  0.5f, -0.5f,     0.0f, 0.67f, // top-left
     0.5f,  0.5f,  0.5f,     1.0f, 1.0f, // bottom-right
     0.5f,  0.5f, -0.5f,     1.0f, 0.67f, // top-right     
     0.5f,  0.5f,  0.5f,     1.0f, 1.0f, // bottom-right
    -0.5f,  0.5f, -0.5f,     0.0f, 0.67f, // top-left
    -0.5f,  0.5f,  0.5f,     0.0f, 1.0f, // bottom-left
};

typedef struct CubeVertex {
    float x;
    float y;
    float z;

    float v;//texture-side-dir
    float u;//texture-up-dir
};

//Vector Vertices Cube Data Structures
extern std::vector<CubeVertex> cubeVertexData;
extern std::vector<CubeVertex> editableCubeVertexData;

//generate multiple Cube
void generateWorld();
//-->update vertice vector with random noise
void updateCubeVertices_randomNoise();
//-->update vertice vector with perlin noise
void updateCubeVertices_perlinNoise();
//-->update individual vertices to generate multiple cubes
void updateCubeVertices(int x,int y,int z);
//-->go through the vertices array and update the vertices vector
void sUpdateCubeVertices(int i_start, int i_end, int x, int y, int z, std::string type="GRASS");