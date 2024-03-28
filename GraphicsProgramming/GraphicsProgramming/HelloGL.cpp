#include "GLUTCallbacks.h"
#include "HelloGL.h"
Vertex HelloGL::vertices[] = { 1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)

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

Color HelloGL::colors[] = { 1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)

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


HelloGL::HelloGL(int argc, char* argv[]) 
{
	rotationOct = 0.0f;
	rotationTri = 0.0f;
	rotationSqu = 0.0f;
	camera = new Camera();
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
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
	glutMainLoop();


}
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//DrawOctagon();
	//DrawSquare();
	//DrawTriangle();
	//glutWireIcosahedron();
	DrawCubeArray();
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
void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);

	// face v0-v1-v2

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	// face v2-v3-v0

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v0-v3-v4

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	// face v4-v5-v0

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v0-v5-v6

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	// face v6-v1-v0

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v1-v6-v7

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	// face v7-v2-v1

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	// face v7-v4-v3

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	// face v3-v2-v7

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	// face v4-v7-v6

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	// face v6-v5-v4

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glEnd();
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