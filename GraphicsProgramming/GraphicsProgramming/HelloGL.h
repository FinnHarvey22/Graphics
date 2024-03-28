#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Gl\freeglut.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16

struct Vector3 
{
	float x, y, z;
};
struct Camera 
{
	Vector3 eye, center, up;
};
struct Color 
{
	GLfloat r, g, b;
};
struct Vertex 
{
	GLfloat x, y, z;
};

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();
	
	void DrawOctagon();
	void DrawSquare();
	void DrawTriangle();
	void DrawCube();
	void DrawCubeArray();
	
	void Update();
	void Keyboard(unsigned char key, int x, int y);
private:
	float rotationOct;
	float rotationSqu;
	float rotationTri; 
	Camera* camera;
	static Vertex vertices[];
	static Color colors[];
};

