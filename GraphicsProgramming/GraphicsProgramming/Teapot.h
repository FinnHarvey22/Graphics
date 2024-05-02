#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Structures.h"

class Teapot
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;
	GLfloat _rotation;
	Vector3 _Position;

public:
	Teapot(int x, int y, int z);
	~Teapot();

	void Draw();
	void Update();

	static bool Load(char* path);
};

