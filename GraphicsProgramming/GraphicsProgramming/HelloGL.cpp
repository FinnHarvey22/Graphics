#include "HelloGL.h"
#include "GLUTCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[]) 
{
	rotationOct = 0.0f;
	rotationTri = 0.0f;
	rotationSqu = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();


}
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawOctagon();
	DrawSquare();
	DrawTriangle();
	glFlush();
	glutSwapBuffers();
}
void HelloGL::Update()
{
	glutPostRedisplay();
	rotationOct += 1.0f;

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
	glTranslatef(0.5, 0.5, 0);
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
	glTranslatef(-0.5, -0.5, 0);
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

HelloGL::~HelloGL(void)
{

}