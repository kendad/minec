#include "mesh_type.h"
#include <iostream>
#include <algorithm>


std::vector<CubeVertex> cubeVertexData;

void generateWorld() {
	int sizeOfWorldX = 100;
	int sizeOfWorldY = 100;
	int sizeOfWorldZ = 100;
	/*for (int x = 0; x < sizeOfWorldX; x++) {
		for (int y = 0; y < sizeOfWorldY; y++) {
			for (int z = 0; z < sizeOfWorldZ; z++) {
				updateCubeVertices(x, y, z);
			}
		}
	}*/
	kela(sizeOfWorldX,sizeOfWorldY,sizeOfWorldZ);
}

void updateCubeVertices(int x, int y, int z) {
	for (int i = 0 ; i < sizeof(grassCube) / sizeof(grassCube[0]); i+=5) {
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

void kela(int x,int y,int z) {
	//draw the front and back faces
	for (int _x = 0; _x < x; _x++) {
		for (int _y = 0; _y < y; _y++) {
			for (int i = 30; i < 60; i += 5) {
				CubeVertex tmpVertex;
				tmpVertex.x = grassCube[i];
				tmpVertex.y = grassCube[i + 1];
				tmpVertex.z = grassCube[i + 2];

				tmpVertex.v = grassCube[i + 3];
				tmpVertex.u = grassCube[i + 4];

				tmpVertex.x += _x;
				tmpVertex.y += _y;

				//update the vertices vector
				cubeVertexData.push_back(tmpVertex);
			}
			for (int i = 0; i < 30; i += 5) {
				CubeVertex tmpVertex;
				tmpVertex.x = grassCube[i];
				tmpVertex.y = grassCube[i + 1];
				tmpVertex.z = grassCube[i + 2];

				tmpVertex.v = grassCube[i + 3];
				tmpVertex.u = grassCube[i + 4];

				tmpVertex.x += _x;
				tmpVertex.y += _y;
				tmpVertex.z -= z-1;
				//update the vertices vector
				cubeVertexData.push_back(tmpVertex);
			}
		}
	}

	//draw the left and right faces
	for (int _z = 0; _z < z; _z++) {
		for (int _y = 0; _y < y; _y++) {
			for (int i = 60; i < 90; i += 5) {
				CubeVertex tmpVertex;
				tmpVertex.x = grassCube[i];
				tmpVertex.y = grassCube[i + 1];
				tmpVertex.z = grassCube[i + 2];

				tmpVertex.v = grassCube[i + 3];
				tmpVertex.u = grassCube[i + 4];

				tmpVertex.z -= _z;
				tmpVertex.y += _y;

				//update the vertices vector
				cubeVertexData.push_back(tmpVertex);
			}
			for (int i = 90; i < 120; i += 5) {
				CubeVertex tmpVertex;
				tmpVertex.x = grassCube[i];
				tmpVertex.y = grassCube[i + 1];
				tmpVertex.z = grassCube[i + 2];

				tmpVertex.v = grassCube[i + 3];
				tmpVertex.u = grassCube[i + 4];

				tmpVertex.x += x-1;
				tmpVertex.z -= _z;
				tmpVertex.y += _y;

				//update the vertices vector
				cubeVertexData.push_back(tmpVertex);
			}
		}
	}

	//draw the top and bottom faces
	for (int _x = 0; _x < x; _x++) {
		for (int _z = 0; _z < z; _z++) {
			for (int i = 120; i < 150; i += 5) {
				CubeVertex tmpVertex;
				tmpVertex.x = grassCube[i];
				tmpVertex.y = grassCube[i + 1];
				tmpVertex.z = grassCube[i + 2];

				tmpVertex.v = grassCube[i + 3];
				tmpVertex.u = grassCube[i + 4];

				tmpVertex.z -= _z;
				tmpVertex.x += _x;

				//update the vertices vector
				cubeVertexData.push_back(tmpVertex);
			}
			for (int i = 150; i < sizeof(grassCube) / sizeof(grassCube[0]); i += 5) {
				CubeVertex tmpVertex;
				tmpVertex.x = grassCube[i];
				tmpVertex.y = grassCube[i + 1];
				tmpVertex.z = grassCube[i + 2];

				tmpVertex.v = grassCube[i + 3];
				tmpVertex.u = grassCube[i + 4];

				tmpVertex.z -= _z;
				tmpVertex.x += _x;
				tmpVertex.y += y - 1;

				//update the vertices vector
				cubeVertexData.push_back(tmpVertex);
			}
		}
	}
}