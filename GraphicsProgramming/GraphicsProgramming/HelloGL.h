#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Gl\freeglut.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16
class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();
	
	void DrawOctagon();
	void DrawSquare();
	void DrawTriangle();
	
	void Update();
private:
	float rotationOct;
	float rotationSqu;
	float rotationTri; 
};

