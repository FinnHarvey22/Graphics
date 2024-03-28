#include "GLUTCallbacks.h"
#include "HelloGL.h"
Vertex HelloGL::vertices[] = { 
1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)

-1,-1, 1, 1,-1, 1, 1, 1, 1, // v2-v3-v0

1, 1, 1, 1,-1, 1, 1,-1,-1, // v0-v3-v4 (right)

1,-1,-1, 1, 1,-1, 1, 1, 1, // v4-v5-v0

1, 1, 1, 1, 1,-1, -1, 1,-1, // v0-v5-v6 (top)

-1, 1,-1, -1, 1, 1, 1, 1, 1, // v6-v1-v0

-1, 1, 1, -1, 1,-1, -1,-1,-1, // v1-v6-v7 (left)

-1,-1,-1, -1,-1, 1, -1, 1, 1, // v7-v2-v1

-1,-1,-1, 1,-1,-1, 1,-1, 1, // v7-v4-v3 (bottom)

1,-1, 1, -1,-1, 1, -1,-1,-1, // v3-v2-v7

1,-1,-1, -1,-1,-1, -1, 1,-1, // v4-v7-v6 (back)

-1, 1,-1, 1, 1,-1, 1,-1,-1 }; // v6-v5-v4

Color HelloGL::colors[] = { 
1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)

1, 0, 0, 1, 0, 1, 1, 1, 1, // v2-v3-v0

1, 1, 1, 1, 0, 1, 0, 0, 1, // v0-v3-v4 (right)

0, 0, 1, 0, 1, 1, 1, 1, 1, // v4-v5-v0

1, 1, 1, 0, 1, 1, 0, 1, 0, // v0-v5-v6 (top)

0, 1, 0, 1, 1, 0, 1, 1, 1, // v6-v1-v0

1, 1, 0, 0, 1, 0, 0, 0, 0, // v1-v6-v7 (left)

0, 0, 0, 1, 0, 0, 1, 1, 0, // v7-v2-v1

0, 0, 0, 0, 0, 1, 1, 0, 1, // v7-v4-v3 (bottom)

1, 0, 1, 1, 0, 0, 0, 0, 0, // v3-v2-v7

0, 0, 1, 0, 0, 0, 0, 1, 0, // v4-v7-v6 (back)

0, 1, 0, 0, 1, 1, 0, 0, 1 }; // v6-v5-v4
Vertex HelloGL::indexedVertices[] = { 
1, 1, 1, -1, 1, 1, // v0,v1,

-1,-1, 1, 1,-1, 1, // v2,v3

1,-1,-1, 1, 1,-1, // v4,v5

-1, 1,-1, -1,-1,-1 }; // v6,v7

Color HelloGL::indexedColors[] = { 
1, 1, 1, 1, 1, 0, // v0,v1,

1, 0, 0, 1, 0, 1, // v2,v3

0, 0, 1, 0, 1, 1, // v4,v5

0, 1, 0, 0, 0, 0 }; //v6,v7

GLushort HelloGL::indices[] = { 
0, 1, 2, 2, 3, 0, // front

0, 3, 4, 4, 5, 0, // right

0, 5, 6, 6, 1, 0, // top

1, 6, 7, 7, 2, 1, // left

7, 4, 3, 3, 2, 7, // bottom

4, 7, 6, 6, 5, 4 }; // back

HelloGL::HelloGL(int argc, char* argv[]) 
{
	rotationOct = 0.0f;
	rotationTri = 0.0f;
	rotationSqu = 0.0f;
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 3.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//glCullFace(GL_FRONT);
	glutMainLoop();


}
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//DrawOctagon();
	//DrawSquare();
	//DrawTriangle();
	//glutWireIcosahedron();
	//DrawCubeArray();
	//DrawIndexedCubeAlt();
	DrawPyramid();
	glFlush();
	glutSwapBuffers();
}
void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
	//rotationOct += 1.0f;

	if (rotationOct >= 360.0f)
	{
		rotationOct = 0.0f;
	}
	rotationSqu += 30.0f;

	if (rotationSqu >= 360.0f)
	{
		rotationSqu = 0.0f;
	}
	rotationTri -= 0.5f;

	if (rotationTri >= 360.0f)
	{
		rotationTri = 0.0f;
	}
}
void HelloGL::DrawOctagon()
{
	glPushMatrix();
	glTranslatef(0.5, 0.5, -5.0);
	glRotatef(rotationOct, 0.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.075, 0.1); //top left
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2f(0.075, 0.1); // top right
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.15, 0); //top right most
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.075, -0.1); // bottom right
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(-0.075, -0.1); // bottom left
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.15, 0); //bottom left most
		glEnd();
	}
	glPopMatrix();

}
void HelloGL::DrawSquare() 
{
	glPushMatrix();
	glTranslatef(0, 0, -5);
	glRotatef(rotationSqu, 0.0f, 0.0f, -1.0f);
	
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.1, 0.1); //top left
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2f(0.1, 0.1); // top right
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.1, -0.1); // bottom right
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(-0.1, -0.1); // bottom left
		glEnd();
	}
	glPopMatrix();
}
void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glTranslatef(-0.5, -0.5, -5.0);
	glRotatef(rotationTri, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2f(0.0, 0.1); // top right
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.1, -0.1); // bottom right
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(-0.1, -0.1); // bottom left
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawCubeArray()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}
	glEnd();
	glPopMatrix();
}
void HelloGL::DrawIndexedCube()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b );
		glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
	}
	glEnd();
	glPopMatrix();


}
void HelloGL::DrawIndexedCubeAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
void HelloGL::DrawPyramid()
{
	glPushMatrix();
	
	glBegin(GL_TRIANGLES);
	{
		// Front face
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3f(0, 1, 0);
		glVertex3f(1, 0, -1);
		glColor3f(0, 0, 1);
		glVertex3f(-1, 0, -1);

		// Left face
		glColor3f(1, 0, 0);
		glVertex3f(0, 1,0);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 0, -1); // bottom left
		glColor3f(0, 0, 1);
		glVertex3f(-1, 0, 1);

		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 0, 1); // bottom left
		glColor3f(0, 0, 1);
		glVertex3f(1, 0, 1);

		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3f(0, 1, 0);
		glVertex3f(1, 0, 1); // bottom left
		glColor3f(0, 0, 1);
		glVertex3f(1, 0, -1);
		
		glColor3f(1, 0, 0);
		glVertex3f(1, 0, 1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 0, -1); // bottom left
		glColor3f(0, 0, 1);
		glVertex3f(1, 0, -1);

		glColor3f(1, 0, 0);
		glVertex3f(-1, 0, -1);
		glColor3f(0, 1, 0);
		glVertex3f(1, 0, 1); // bottom left
		glColor3f(0, 0, 1);
		glVertex3f(-1, 0, 1);

		/*glColor3f(1, 0, 0);
		glVertex3f(-1, 0, -1);
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3f(1, 0, 0);
		glVertex3f(-1, 0, 1);*/


	/*	glColor3f(1, 0, 0);
		glVertex3f(1, -1, 1);
		glVertex3f(0, 0, 2.5);
		glVertex3f(-1, -1, 1);

		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glVertex3f(0, 0, 2.5);
		glVertex3f(-1, 1, 1);

		glVertex3f(-1, 1, 1);
		glVertex3f(0, 0, 2.5);
		glVertex3f(1, 1, 1);

		glVertex3f(1, 1, 1);
		glVertex3f(1, -1, 1);
		glVertex3f(-1, 1, 1);

		glVertex3f(-1, 1, 1);
		glVertex3f(-1, -1, 1);
		glVertex3f(1, -1, 1);*/
	}
		//glColor3f(1, 0, 0);
		//glVertex3f(0, 0, 2.5);
		//glVertex3f(1, 1, 1);
		//glVertex3f(1, -1, 1);

		//glVertex3f(1, -1, 1);
		//glVertex3f(0, 0, 2.5);
		//glVertex3f(-1, -1, 1);

		//glVertex3f(-1, -1, 1);
		//glVertex3f(0, 0, 2.5);
		//glVertex3f(-1, 1, 1);

		//glVertex3f(-1, 1, 1);
		//glVertex3f(0, 0, 2.5);
		//glVertex3f(1, 1, 1);

		//glVertex3f(1, 1, 1);
		//glVertex3f(1, -1, 1);
		//glVertex3f(-1, 1, 1);

		//glVertex3f(-1, 1, 1);
		//glVertex3f(-1, -1, 1);
		//glVertex3f(1, -1, 1);

		glEnd();

		glPopMatrix();
}
void HelloGL::DrawPrism()
{
	glPushMatrix();


	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0);
	glVertex3f(1, 0, -1);
	glColor3f(0, 0, 1);
	glVertex3f(-1, 0, -1);

	glEnd();

	glPopMatrix();
}
void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd') 
	{
		camera->eye.x += 0.1f;
	}
	if (key == 'a') 
	{
		camera->eye.x -= 0.1f;
	}
	if (key == 'w')
	{
		camera->eye.y += 0.1f;
	}
	if (key == 's')
	{
		camera->eye.y -= 0.1f;
	}
}

HelloGL::~HelloGL(void)
{

}