#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Structures.h"

class Cube
{
private:
	Mesh* _mesh;
	/*static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;*/
	GLfloat _rotation;
	Vector3 _Position;

public:
	Cube(Mesh* mesh,int x, int y, int z);
	~Cube();

	void Draw();
	void Update();
	//Cube(Mesh* mesh, float x, float y, float z);
};

