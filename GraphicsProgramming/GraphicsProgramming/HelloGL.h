#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Gl\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#define REFRESHRATE 16

#define NUM_CUBES 200

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();
	
	/*void DrawOctagon();
	void DrawSquare();
	void DrawTriangle();
	
	void DrawPrism();*/
	void DrawPyramid();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void InitObjects();
	void InitGL(int argc, char* argv[]);
private:
	float rotationOct;
	float rotationSqu;
	float rotationTri; 
	Camera* camera;
	Cube* cube[NUM_CUBES];
	/*static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];*/
};

