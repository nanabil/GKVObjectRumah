#include <stdlib.h>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION //buat textur
#include "stb_image.h" //buat textur


static float ypoz = 0, zpoz = 0, xpoz = 0, a = 0, b = 0, c = -10;
void gedung(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float z1, float z2, float z3) {
	glColor3f(0.2, 0.5, 0.7); //dinding depan
	glVertex3d(x1, y1, z2);
	glVertex3d(x2, y2, z2);
	glVertex3d(x3, y3, z2);
	glVertex3d(x4, y4, z2);

	glColor3f(0.37, 0.99, 0.177);
	glVertex3d(x2, y2, z2);
	glVertex3d(x2, y2, z1);
	glVertex3d(x3, y3, z1);
	glVertex3d(x3, y3, z2);

	glColor3f(0.37, 0.99, 0.177);
	glVertex3d(x1, y1, z1);
	glVertex3d(x2, y2, z1);
	glVertex3d(x3, y3, z1);
	glVertex3d(x4, y4, z1);

	glColor3f(0.37, 0.99, 0.177);
	glVertex3d(x1, y1, z2);
	glVertex3d(x1, y1, z1);
	glVertex3d(x4, y4, z1);
	glVertex3d(x4, y4, z2);

	glColor3f(0.37, 0.99, 0.177);
	glVertex3d(x1, y1, z2);
	glVertex3d(x2, y2, z2);
	glVertex3d(x2, y2, z1);
	glVertex3d(x1, y1, z1);

	glColor3f(0.37, 0.99, 0.177);
	glVertex3d(x3, y3, z2);
	glVertex3d(x4, y4, z2);
	glVertex3d(x4, y4, z1);
	glVertex3d(x3, y3, z1);
}

void atap1 (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float z1, float z2, float z3) {
	glColor3f(0.67, 0.40, 0.40);
	glVertex3d(x3, y3, z1);
	glVertex3d(x3, y3, z2);
	glVertex3d(x3, y1, z3);

	glColor3f(0.67, 0.40, 0.40);
	glVertex3d(x4, y4, z2);
	glVertex3d(x4, y4, z1);
	glVertex3d(x4, y4, z3);
	   }

void atap2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float z1, float z2, float z3) {
	glColor3f(0.213, 0.148, 0.63);
	glVertex3d(x4, y4, z1);
	glVertex3d(x3, y3, z1);
	glVertex3d(x3, y1, z3);
	glVertex3d(x4, y1, z3);

	glColor3f(0.213, 0.148, 0.63);
	glVertex3d(x3, y3, z2);
	glVertex3d(x4, y4, z2);
	glVertex3d(x4, y1, z3);
	glVertex3d(x3, y1, z3);
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-12, 12, -6, 6, -35, 35);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, 2.2, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);

	//bind vao 0
	//glBindVertexArray(0);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(a, b, c);
	glRotatef(xpoz, 1, 0, 0);

	glRotatef(ypoz, 0, 1, 0);
	glRotatef(zpoz, 0, 0, 1);
	glBegin(GL_QUADS);

	gedung(-8, -2, 8, -2, 8, 2, -8, 2, -5, 3, 0);
	gedung(2, -2, 8, -2, 8, 2, 2, 2, -5, 4, 0);
	gedung(-8, -2, -7, -2, -7, 2, -8, 2, -5, 4, 0);

	gedung(-8, -2, -7, -2, -7, 0, -8, 0, -5, 5.5, 0);
	gedung(7, -2, 8, -2, 8, 0, 7, 0, -5, 5.5, 0);
	atap2(-3, 5, 0, 0, 8, 2, -8, 2, -5.5, 4.5, 0);

	glColor3f(0.34, 0.12, 0.2); // plafon depan
	glVertex3d(8, 1.8, -3);
	glVertex3d(-8, 1.8, -3);
	glVertex3d(-8, 1.8, 4.5);
	glVertex3d(8, 1.8, 4.5);

	glVertex3d(8, 1.8, 4.5);
	glVertex3d(-8, 1.8, 4.5);
	glVertex3d(-8, 2, 4.5);
	glVertex3d(8, 2, 4.5);

	glColor3f(0.34, 0.12, 0.2); // plafon belakang
	glVertex3d(8, 1.8, -5.5);
	glVertex3d(-8, 1.8, -5.5);
	glVertex3d(-8, 1.8, 4.5);
	glVertex3d(8, 1.8, 4.5);

	glVertex3d(8, 1.8, -5.5);
	glVertex3d(8, 1.8, -5.5);
	glVertex3d(-8, 2, -5.5);
	glVertex3d(-8, 2, -5.5);

	glColor3f(0.9, 0.8, 0.345);
	glVertex3d(4, -0.5, 4.1); //cendela kamar (cendela paling kanan yg besar)
	glVertex3d(6, -0.5, 4.1);
	glVertex3d(6, 1, 4.1);
	glVertex3d(4, 1, 4.1);

	glColor3f(0.456, 0.5, 0.7);
	glVertex3d(2.7, -0.5, 4.1); // cendela kamar 2 (cendela paling kanan kedua yg kecil)
	glVertex3d(3.8, -0.5, 4.1);
	glVertex3d(3.8, 1, 4.1);
	glVertex3d(2.7, 1, 4.1);

	glColor3f(0.8, 0.3, 0.4);
	glVertex3d(-2, -2, 3.05); //pintu depan
	glVertex3d(2, -2, 3.05);
	glVertex3d(2, 1.3, 3.05);
	glVertex3d(-2, 1.3, 3.05);

	glColor3f(0.8, 0.3, 0.4);
	glVertex3d(-2, -2, -5.05); // pintu blkng
	glVertex3d(2, -2, -5.05);
	glVertex3d(2, 1, -5.05);
	glVertex3d(2, 1, -5.05);
	glVertex3d(-2, 1, -5.05);



	
	glEnd();
	glBegin(GL_TRIANGLES);
	atap1(-3, 5, 0, 0, 8, 2, -8, 2, -5.5, 4.5, 0); //(penutup atap bagian kanan)
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.100, 0.100, 0.100);
	glVertex3d(8, 1.8, 4.5);
	glVertex3d(-8, 1.8, 4.5);
	glVertex3d(-8, 1.8, 4.5);
	glVertex3d(8, 1.8, -5.5);
	
	glColor3f(0.100, 0.100, 0.100);
	glVertex3d(-4.5, -1, -5.05);
	glVertex3d(-4.5, 1, -5.05);
	glVertex3d(4.5, -1, -5.05);
	glVertex3d(4.5, 1, -5.05);
	glEnd();
	glutSwapBuffers();
	   }

void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case 'x':
		xpoz = xpoz + 5;
		if (xpoz > 360) xpoz = 0;
		glutPostRedisplay();
		break;

	case 'y':
		ypoz = ypoz + 5;
		if (ypoz > 360) ypoz = 0;
		glutPostRedisplay();
		break;

	case 'z':
		zpoz = zpoz + 5;
		if (zpoz > 360) zpoz = 0;
		glutPostRedisplay();
		break;

	case 'w':
		b = b + 1;
		glutPostRedisplay();
		break;

	case 's':
		b = b - 1;
		glutPostRedisplay();
		break;

	case 'a':
		a = a + 1;
		glutPostRedisplay();
		break;

	case 'd':
		a = a - 1;
		glutPostRedisplay();
		break;

	case 'q':
		c = c + 1;
		glutPostRedisplay();
		break;

	case 'e':
		c = c - 1;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Our Fantasy Realism");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;

}