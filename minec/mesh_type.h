#pragma once

//CUBE DATA
const float grassCube[] = {
    // Back face
    -0.5f, -0.5f, -0.5f,     0.0f, 0.33f,  // Bottom-left 0.0f 0.6
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
    -0.5f,  0.5f,  0.5f,     0.0f, 0.4f, // bottom-left
};

const float waterCube[] = {//flip texture when using water cube
    // Back face
    -0.5f, -0.5f, -0.5f,     0.0f, 0.33f,  // Bottom-left 0.0f 0.6
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
    -0.5f, -0.5f, -0.5f,     1.0f, 0.0f, // top-right
     0.5f, -0.5f, -0.5f,     0.0f, 0.0f, // top-left
     0.5f, -0.5f,  0.5f,     0.0f, 0.33f, // bottom-left
     0.5f, -0.5f,  0.5f,     0.0f, 0.33f, // bottom-left
    -0.5f, -0.5f,  0.5f,     1.0f, 0.33f, // bottom-right
    -0.5f, -0.5f, -0.5f,     1.0f, 0.0f, // top-right
    // Top face
    -0.5f,  0.5f, -0.5f,     0.0f, 0.0f, // top-left
     0.5f,  0.5f,  0.5f,     1.0f, 0.33f, // bottom-right
     0.5f,  0.5f, -0.5f,     1.0f, 0.0f, // top-right     
     0.5f,  0.5f,  0.5f,     1.0f, 0.33f, // bottom-right
    -0.5f,  0.5f, -0.5f,     0.0f, 0.0f, // top-left
    -0.5f,  0.5f,  0.5f,     0.0f, 0.33f, // bottom-left
};

const unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,  // first Triangle
    1, 2, 3   // second Triangle
};
