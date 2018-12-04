/*
Hernández González Ricardo Omar

Teclas: a - Rotar desde base hacia arriba
		s - Rotar desde base hacia abajo
		d - Rotar la base sentido antihorario
		f - Rotar la base sentido horario
		q - Rotar desde codo hacia abajo
		w - Rotar desde codo hacia arriba
		n - Rotar muñeca 
		m - Rotar muñeca
		v - Abrir pinza izquierda
		b - Cerrar pinza izquierda
*/



#include "Main.h"

float rotBaseY = -50.0, rotBaseZ = 45.0, rotCodo = -45.0, abrirCerrarPinza=-45.0, rotMuneca=0;

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	//gluLookAt(0.0, 10.0, -15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0, -15);
	glPushMatrix();
		glPushMatrix();
			glScalef(2.0, 0.5, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			glutSolidCube(0.5); //base
		glPopMatrix();
		glTranslatef(0.0, 0.375, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere(0.25, 100, 100); //esfera base
		glRotatef(rotBaseY, 0.0, 1.0, 0.0);
		glRotatef(rotBaseZ, 0.0, 0.0, 1.0);
		glTranslatef(1.75, 0.0, 0.0);
		glPushMatrix();
			glScalef(3.0, 0.25, 0.25);
			glColor3f(1.0, 0.0, 0.0);
			glutSolidCube(1.0); // brazo
		glPopMatrix();
		glTranslatef(1.75, 0.0, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere(0.25, 100, 100); //codo
		glRotatef(rotCodo, 0.0, 0.0, 1.0);
		glTranslatef(1.75, 0.0, 0.0);
		glPushMatrix();
			glScalef(3.0, 0.25, 0.25);
			glColor3f(1.0, 0.0, 0.0);
			glutSolidCube(1.0); // antebrazo
		glPopMatrix();
		glTranslatef(1.75, 0.0, 0.0);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere(0.25, 100, 100); //muñeca
		glRotatef(rotMuneca, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(45.0, 0.0, 1.0, 0.0);
			glTranslatef(0.6, 0.0, 0.0);
			glPushMatrix();
				glScalef(0.75, 0.25, 0.25);
				glColor3f(1.0, 0.0, 0.0);
				glutSolidCube(1.0);
			glPopMatrix();
			glTranslatef(0.6, 0.0, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glutSolidSphere(0.25, 100, 100);
			glRotatef(abrirCerrarPinza, 0.0, 1.0, 0.0);
			glTranslatef(1.0, 0.0, 0.0);
			glPushMatrix();
				glScalef(1.5, 0.25, 0.25);
				glColor3f(1.0, 0.0, 0.0);
				glutSolidCube(1.0);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glRotatef(-45.0, 0.0, 1.0, 0.0);
			glTranslatef(0.6, 0.0, 0.0);
			glPushMatrix();
				glScalef(0.75, 0.25, 0.25);
				glColor3f(1.0, 0.0, 0.0);
				glutSolidCube(1.0);
			glPopMatrix();
			glTranslatef(0.6, 0.0, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glutSolidSphere(0.25, 100, 100);
			glRotatef(-abrirCerrarPinza, 0.0, 1.0, 0.0);
			glTranslatef(1.0, 0.0, 0.0);
			glPushMatrix();
				glScalef(1.5, 0.25, 0.25);
				glColor3f(1.0, 0.0, 0.0);
				glutSolidCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
		case 'a':
		case 'A':
			rotBaseZ++;
			break;

		case 's':
		case 'S':
			rotBaseZ--;
			break;

		case 'd':
		case 'D':
			rotBaseY++;
			break;

		case 'f':
		case 'F':
			rotBaseY--;
			break;

		case 'q':
		case 'Q':
			rotCodo--;
			break;

		case 'w':
		case 'W':
			rotCodo++;
			break;

		case 'v':
		case 'V':
			abrirCerrarPinza++;
			break;

		case 'b':
		case 'B':
			abrirCerrarPinza--;
			break;

		case 'n':
		case 'N':
			rotMuneca++;
			break;

		case 'm':
		case 'M':
			rotMuneca--;
			break;
		
		case 27:
			exit(0);
			break;
	}

	glutPostRedisplay();
}

void reshape(int w, int h) {

	if (!h)
		return;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (GLfloat)w / (GLfloat)h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1500, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Computacion Grafica");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	
	return 0;
}