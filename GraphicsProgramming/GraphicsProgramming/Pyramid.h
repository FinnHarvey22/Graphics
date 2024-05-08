#pragma once
#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Structures.h"
#include "SceneObject.h"

class Pyramid : public SceneObject
{
private:

	/*static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;*/
	GLfloat _rotation;
	Vector3 _Position;

public:
	Pyramid(Mesh* mesh, int x, int y, int z);
	~Pyramid();

	void Draw();
	void Update();
};

