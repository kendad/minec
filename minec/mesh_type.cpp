#include "mesh_type.h"
#include <iostream>
std::vector<CubeVertex> cubeVertexData;

void generateWorld() {
	int sizeOfWorldX = 100;
	int sizeOfWorldY = 3;
	int sizeOfWorldZ = 100;
	for (int x = 0; x < sizeOfWorldX; x++) {
		for (int y = 0; y < sizeOfWorldY; y++) {
			for (int z = 0; z < sizeOfWorldZ; z++) {
				updateCubeVertices(x, y, z);
			}
		}
	}
}

void updateCubeVertices(int x, int y, int z) {
	for (int i = 0; i < sizeof(grassCube) / sizeof(grassCube[0]); i+=5) {
		CubeVertex tmpVertex;
		tmpVertex.x = grassCube[i];
		tmpVertex.y = grassCube[i + 1];
		tmpVertex.z = grassCube[i + 2];

		tmpVertex.v = grassCube[i + 3];
		tmpVertex.u = grassCube[i + 4];

		//update the positions
		tmpVertex.x += x;
		tmpVertex.y += y;
		tmpVertex.z -= z;
		//update the vertices vector
		cubeVertexData.push_back(tmpVertex);
	}
}