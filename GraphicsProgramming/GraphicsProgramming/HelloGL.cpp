#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) 
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();

	
}
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	glFlush();
}
void HelloGL::DrawPolygon()
{

	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.3, 0.5); //top left
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex2f(0.3, 0.5); // top right
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.6, 0); //top right most
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.3, -0.5); // bottom right
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(-0.3, -0.5); // bottom left
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(-0.6, 0); //bottom left most
		glEnd();
	}

}

HelloGL::~HelloGL(void)
{

}