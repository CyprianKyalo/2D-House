#include <stdio.h>
#include <GL/glut.h>
#include <cmath>
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);  // sets the bitplane area of the window to values previously selected by glClearColor
	//glColor3f(0.37f, 0.22f, 0.07f); // Defines the fill color
	glColor3f(0.1, 0.5, 0.0);
	glBegin(GL_POLYGON); // Defines the type of object you want to draw
	//

	//House
	glVertex2i(2, 2);
	glVertex2i(6, 2);
	glVertex2i(6, 6);
	glVertex2i(2, 6);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(1.5, 6);
	glVertex2d(6.5, 6);
	glVertex2d(6.5, 7);
	glVertex2d(1.5, 7);
	glEnd();

	// Left Window
	glColor3f(0.3, 0.5, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(2.3, 3.9);
	glVertex2d(3.2, 3.9);
	glVertex2d(3.2, 4.9);
	glVertex2d(2.3, 4.9);
	glEnd();

	// Left Window grids
	glColor3f(0.6, 0.2, 0.3);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2d(2.3, 4.4);
	glVertex2d(3.2, 4.4);
	glVertex2d(2.75, 3.9);
	glVertex2d(2.75, 4.9);
	glEnd();

	// Door
	glColor3f(0.3, 0.5, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(3.5, 2);
	glVertex2d(4.5, 2);
	glVertex2d(4.5, 5);
	glVertex2d(3.5, 5);
	glEnd();

	// Right Window
	glColor3f(0.3, 0.5, 0.8);
	glBegin(GL_POLYGON);
	glVertex2d(4.8, 3.9);
	glVertex2d(5.7, 3.9);
	glVertex2d(5.7, 4.9);
	glVertex2d(4.8, 4.9);
	glEnd();

	// Right Window grids
	glColor3f(0.6, 0.2, 0.3);
	glBegin(GL_LINES);
	glVertex2d(4.8, 4.4);
	glVertex2d(5.7, 4.4);
	glVertex2d(5.25, 3.9);
	glVertex2d(5.25, 4.9);
	glEnd();

	// First  Circle
	glColor3ub(255, 255, 0); // yellow background
	float i = 0.0f;
	float r = 0.30f;
	float o = 9.3f;
	float x = 6.35f;
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0.0f; i <= 360; i++)
		glVertex2f(r * cos(3.14 * i / 180.0) + x, r * sin(3.14 * i / 180.0) + o);

	glEnd();


	// Second  Circle
	glColor3f(0, 0, 0);  //black background
	float p = 0.0f;
	float q = 0.35f;
	float z = 9.45f;
	float l = 6.45f;
	glBegin(GL_TRIANGLE_FAN);
	for (p = 0.0f; p <= 360; p++)
		glVertex2f(r * cos(3.14 * p / 180.0) + l, q * sin(3.14 * p / 180.0) + z);

	glEnd();

	//Door Knob
	glColor3f(0.6, 0.2, 0.3);
	float t = 0.0f;
	float m = 0.08f;
	float n = 3.4f;
	float v = 4.35f;
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0.0f; t <= 360; t++)
		glVertex2f(m * cos(3.14 * t / 180.0) + v, m * sin(3.14 * t / 180.0) + n);
	glEnd();


	// Top of House
	glColor3f(0.6, 0.2, 0.3);
	float a = 0.0f;
	float b = 1.5f;
	float c = 7.00f;
	float d = 4.00f;
	glBegin(GL_TRIANGLE_FAN);
	for (a = 0.0f; a <= 180; a++)
		glVertex2f(b * cos(3.14 * a / 180.0) + d, b * sin(3.14 * a / 180.0) + c);
	glEnd();

	glFlush();  // Forces previously issued OpenGL commands to begin execution
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // Initializes the GLUT library
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1200, 700);
	glutCreateWindow("Rectangle");

	glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
	glMatrixMode(GL_PROJECTION);              // sets the viewing projection, properties of the camera that views the object
	glLoadIdentity();                           // start with identity matrix
	glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setting the coordinate system

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}	 