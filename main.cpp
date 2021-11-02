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

	//Door Knob
	glColor3f(0.6, 0.2, 0.3);
	float t = 0.0f;
	float m = 0.08f;
	float n = 3.1f;
	float o = 4.35f;
	glBegin(GL_TRIANGLE_FAN);
	for (t = 0.0f; t <= 360; t++)
		glVertex2f(m * cos(3.14 * t / 180.0) + o, m * sin(3.14 * t / 180.0) + n);
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