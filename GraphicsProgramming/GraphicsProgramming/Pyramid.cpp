#include "Pyramid.h"
#include <iostream>
#include <fstream>

Pyramid::Pyramid(Mesh* mesh, int x, int y, int z) : SceneObject(mesh, nullptr)
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
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);	
		glPushMatrix();
		glTranslatef(_Position.x, _Position.y, _Position.z);
		//glTranslatef(0, 0, 0);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);

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


