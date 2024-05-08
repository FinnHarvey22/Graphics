#include "Pyramid.h"
#include <iostream>
#include <fstream>

Pyramid::Pyramid(Mesh* mesh, int x, int y, int z) : SceneObject(mesh)
{

	_Position.x = x;
	_Position.y = y;
	_Position.z = z;
}

Pyramid::~Pyramid()
{

}


void Pyramid::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTranslatef(_Position.x, _Position.y, _Position.z);
		//glTranslatef(0, 0, 0);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	}
}

void Pyramid::Update()
{
	//_rotation += 0.5f;
}


