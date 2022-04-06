#include "mesh_type.h"
#include <iostream>
#include <algorithm>


std::vector<CubeVertex> cubeVertexData;

void generateWorld() {
	int sizeOfWorldX = 4;
	int sizeOfWorldY = 4;
	int sizeOfWorldZ = 4;
	updateCubeVertices(sizeOfWorldX,sizeOfWorldY,sizeOfWorldZ);
}

void updateCubeVertices(int x,int y,int z) {
	//draw the front and back faces
	for (int _x = 0; _x < x; _x++) {
		for (int _y = 0; _y < y; _y++) {
			sUpdateCubeVertices(30, 60, _x, _y, 0);//front Face
			sUpdateCubeVertices(0, 30, _x, _y, z - 1);//Back Face
		}
	}
	//draw the left and right faces
	for (int _z = 0; _z < z; _z++) {
		for (int _y = 0; _y < y; _y++) {
			sUpdateCubeVertices(60, 90, 0, _y, _z);//Left Face
			sUpdateCubeVertices(90, 120, x - 1, _y, _z);//Right Face
		}
	}
	//draw the top and bottom faces
	for (int _x = 0; _x < x; _x++) {
		for (int _z = 0; _z < z; _z++) {
			sUpdateCubeVertices(120, 150, _x, 0, _z);//Bottom Face
			sUpdateCubeVertices(150, sizeof(grassCube) / sizeof(grassCube[0]), _x, y - 1, _z);
		}
	}
}

void sUpdateCubeVertices(int i_start, int i_end,int x ,int y, int z) {
	for (int i = i_start; i < i_end; i += 5) {
		CubeVertex tmpVertex;
		tmpVertex.x = grassCube[i];
		tmpVertex.y = grassCube[i + 1];
		tmpVertex.z = grassCube[i + 2];

		tmpVertex.v = grassCube[i + 3];
		tmpVertex.u = grassCube[i + 4];

		tmpVertex.x += x;
		tmpVertex.y += y;
		tmpVertex.z -= z;

		//update the vertices vector
		cubeVertexData.push_back(tmpVertex);
	}
}