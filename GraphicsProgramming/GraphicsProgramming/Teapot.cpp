#include "Teapot.h"
#include <iostream>
#include <fstream>
Vertex* Teapot::indexedVertices = nullptr;

Color* Teapot::indexedColors = nullptr;

GLushort* Teapot::indices = nullptr;

int Teapot::numVertices = 0;
int Teapot::numColors = 0;
int Teapot::numIndices = 0;
Teapot::Teapot(int x, int y, int z)
{
	_Position.x = x;
	_Position.y = y;
	_Position.z = z;
}

Teapot::~Teapot()
{

}

bool Teapot::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file" << path << std::endl;
		return false;
	}
	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++) {
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}
	inFile >> numColors;
	indexedColors = new Color[numColors];
	for (int i = 0; i < numColors; i++) {
		inFile >> indexedColors[i].r;
		inFile >> indexedColors[i].g;
		inFile >> indexedColors[i].b;
	}
	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++) {
		inFile >> indices[i];

	}
	inFile.close();
	return true;
}

void Teapot::Draw()
{
	if (indexedVertices != nullptr && indexedColors != nullptr && indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
		glColorPointer(3, GL_FLOAT, 0, indexedColors);
		glTranslatef(_Position.x, _Position.y, _Position.z);
		//glTranslatef(0, 0, 0);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	}
}

void Teapot::Update()
{
	_rotation += 0.5f;
}


