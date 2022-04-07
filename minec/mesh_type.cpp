#include "mesh_type.h"
#include <iostream>
#include <algorithm>
#include "perlin_noise.h"

std::vector<CubeVertex> cubeVertexData;
std::vector<CubeVertex> editableCubeVertexData;

//Algorithm to find the average value in a floats array
float avegareInArray(float array[], int sizeOfArray, int roundingFactor) {
	float total = 0;
	for (int i = 0; i < sizeOfArray; i++) {
		total += array[i];
	}
	return (total / sizeOfArray) * roundingFactor;
}

void generateWorld() {
	int sizeOfWorldX = 4;
	int sizeOfWorldY = 4;
	int sizeOfWorldZ = 4;
	//updateCubeVertices(sizeOfWorldX,sizeOfWorldY,sizeOfWorldZ);
	//updateCubeVertices_randomNoise();
	updateCubeVertices_perlinNoise();
}

void updateCubeVertices(int x,int y,int z) {
	//draw the front and back faces
	for (int _x = 0; _x < x; _x++) {
		for (int _y = 0; _y < y; _y++) {
			sUpdateCubeVertices(30, 60, _x, _y, 0);//Front Face
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

void sUpdateCubeVertices(int i_start, int i_end,int x ,int y, int z,std::string type) {
	for (int i = i_start; i < i_end; i += 5) {
		CubeVertex tmpVertex;
		tmpVertex.x = (type == "GRASS") ? grassCube[i] : waterCube[i];
		tmpVertex.y = (type == "GRASS") ? grassCube[i + 1] : waterCube[i + 1];
		tmpVertex.z = (type == "GRASS") ? grassCube[i + 2] : waterCube[i + 2];

		tmpVertex.v = (type == "GRASS") ? grassCube[i + 3] : waterCube[i + 3];
		tmpVertex.u = (type == "GRASS") ? grassCube[i + 4] : waterCube[i + 4];

		tmpVertex.x += x;
		tmpVertex.y += y;
		tmpVertex.z -= z;

		//update the vertices vector
		cubeVertexData.push_back(tmpVertex);
	}
}

void updateCubeVertices_randomNoise() {
	for (int x = 0; x < 100; x++) {
		for (int z = 0; z < 100; z++) {
			int randY = 0 + (std::rand() % (10 - 0 + 1));
			for (int y = 0; y <= randY; y++) {
				if (randY <= 4 && x>0 && x<100 && z>0 && z<100) sUpdateCubeVertices(0, sizeof(grassCube) / sizeof(grassCube[0]), x, y, z, "WATER");
				else sUpdateCubeVertices(0, sizeof(grassCube) / sizeof(grassCube[0]), x, y, z, "GRASS");
			}
		}
	}
}

void updateCubeVertices_perlinNoise() {
	int width = 100; int height = 100;
	int roundingFactor = 100;
	PerlinNoise noise(width,height);
	int avgHeight = (int)avegareInArray(fPerlinNoise2D, width * height, roundingFactor);
	int tmp = 0;
	for (int x = 0; x < 100; x++) {
		for (int z = 0; z < 100; z++) {
			int height = round(fPerlinNoise2D[tmp] * roundingFactor);
			for (int y = 0; y < height; y++) {
				if (height <= (avgHeight-2) && x > 0 && x < 100-2 && z>0 && z < 100-2) sUpdateCubeVertices(0, sizeof(grassCube) / sizeof(grassCube[0]), x, y, z, "WATER");
				else sUpdateCubeVertices(0, sizeof(grassCube) / sizeof(grassCube[0]), x, y, z, "GRASS");
			}
			tmp++;
		}
	}

}