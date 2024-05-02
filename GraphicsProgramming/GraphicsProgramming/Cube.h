#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Structures.h"
class Cube
{
private:
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
	GLfloat _rotation;
	Vector3 _Position;

public:
	Cube(int x, int y, int z);
	~Cube();

	void Draw();
	void Update();
};

