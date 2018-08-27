/* Este programa dibuja una "Tetera", este objeto esta definido
 * en GLUT, se crea una fuente de luz, y un material */

//Incluimos las librerias
//#include <GL/glut.h>
//#include <stdlib.h>
#include "Main.h"

void init(void)
{
	 glClearDepth(1.0f);					// Activamos el valor de inicio del buffer de profundidad
	 glEnable(GL_DEPTH_TEST);				// Hacemos la prueba de profundidad
	 glDepthFunc(GL_LEQUAL);				// Tipo de prueba de profundidad a hacer
	 return;
}

void reshape(int w, int h)
{
	 if (!h)
		return;

	 glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
	 // Activamos la matriz de proyeccion.
	 glMatrixMode(GL_PROJECTION);
	 // "limpiamos" esta con la matriz identidad.
	 glLoadIdentity();
	 // Usamos proyeccion ortogonal
	  //glOrtho(-200, 200, -200, 200, -200, 200);
	 gluPerspective(30.0f, (GLfloat)800/(GLfloat)600, 0.03, 1000.0);
	 // Activamos la matriz de modelado/visionado. 
	 glMatrixMode(GL_MODELVIEW);
	 // "Limpiamos" la matriz
	 glLoadIdentity();
	 return;
}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{ 
	 // "Limpiamos" el frame buffer con el color de "Clear", en este 
	 // caso negro. 
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glMatrixMode( GL_MODELVIEW_MATRIX );
	 glLoadIdentity();
 
	 glTranslatef(0.0,0.0,-20.0);

	 // Letra R
	 glBegin(GL_QUADS);
	 glColor3f(0.0, 1.0, 0.0);
		 //Rectangulo vertical izquierda
		 glVertex3f(-6.4f, -1.0f, 0.0f);
		 glVertex3f(-5.8f, -1.0f, 0.0f);
		 glVertex3f(-5.8f, 1.0f, 0.0f);
		 glVertex3f(-6.4f, 1.0f, 0.0f);
		 //Rectangulo horizontal arriba
		 glVertex3f(-5.8f, 0.6f, 0.0f);
		 glVertex3f(-3.8f, 0.6f, 0.0f);
		 glVertex3f(-3.8f, 1.0f, 0.0f);
		 glVertex3f(-5.8f, 1.0f, 0.0f);
		 //Rectangulo horizontal abajo
		 glVertex3f(-5.8f, -0.2f, 0.0f);
		 glVertex3f(-3.8f, -0.2f, 0.0f);
		 glVertex3f(-3.8f, 0.2f, 0.0f);
		 glVertex3f(-5.8f, 0.2f, 0.0f);
		 //Rectangulo vertical derecha chico
		 glVertex3f(-3.8f, 0.2f, 0.0f);
		 glVertex3f(-3.8f, 0.6f, 0.0f);
		 glVertex3f(-4.3f, 0.6f, 0.0f);
		 glVertex3f(-4.3f, 0.2f, 0.0f);
		 //Rectangulo diagonal 
		 glVertex3f(-5.8f, -0.2f, 0.0f);
		 glVertex3f(-5.0f, -0.2f, 0.0f);
		 glVertex3f(-3.8f, -1.0f, 0.0f);
		 glVertex3f(-4.6f, -1.0f, 0.0f);
	 glEnd();

	 // Letra O
	 glBegin(GL_QUADS); 
	 glColor3f(0.0, 1.0, 1.0);
		//Rectangulo horizontal abajo
		glVertex3f(-3.0f, -1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(-1.0f, -0.5f, 0.0f);
		glVertex3f(-3.0f, -0.5f, 0.0f);
		//Rectangulo horizontal arriba
		glVertex3f(-3.0f, 0.5f, 0.0f);
		glVertex3f(-1.0f, 0.5f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-3.0f, 1.0f, 0.0f);
		//Rectangulo vertical izquierda
		glVertex3f(-3.0f, -0.5f, 0.0f);
		glVertex3f(-2.4f, -0.5f, 0.0f);
		glVertex3f(-2.4f, 0.5f, 0.0f);
		glVertex3f(-3.0f, 0.5f, 0.0f);
		//Rectangulo vertical derecha
		glVertex3f(-1.6f, -0.5f, 0.0f);
		glVertex3f(-1.0f, -0.5f, 0.0f);
		glVertex3f(-1.0f, 0.5f, 0.0f);
		glVertex3f(-1.6f, 0.5f, 0.0f);
	 glEnd();

	 // Letra H
	 glBegin(GL_QUADS); 
	 glColor3f(1.0, 0.0, 0.0);
		 //Rectangulo vertical izquierda
		 glVertex3f(-0.2f, -1.0f, 0.0f);
		 glVertex3f(0.4f, -1.0f, 0.0f);
		 glVertex3f(0.4f, 1.0f, 0.0f);
		 glVertex3f(-0.2f, 1.0f, 0.0f);
		 //Rectangulo vertical derecha
		 glVertex3f(1.2f, -1.0f, 0.0f);
		 glVertex3f(1.8f, -1.0f, 0.0f);
		 glVertex3f(1.8f, 1.0f, 0.0f);
		 glVertex3f(1.2f, 1.0f, 0.0f);
		 //Rectangulo horizontal
		 glVertex3f(0.4f, -0.2f, 0.0f);
		 glVertex3f(1.2f, -0.2f, 0.0f);
		 glVertex3f(1.2f, 0.2f, 0.0f);
		 glVertex3f(0.4f, 0.2f, 0.0f);
	 glEnd();

	 // Letra G
	 glBegin(GL_QUADS);
	 glColor3f(0.0, 0.0, 1.0);
		 //Rectangulo horizontal abajo
		 glVertex3f(2.6f, -1.0f, 0.0f);
		 glVertex3f(4.6f, -1.0f, 0.0f);
		 glVertex3f(4.6f, -0.5f, 0.0f);
		 glVertex3f(2.6f, -0.5f, 0.0f);
		 //Rectangulo horizontal arriba
		 glVertex3f(2.6f, 0.5f, 0.0f);
		 glVertex3f(4.6f, 0.5f, 0.0f);
		 glVertex3f(4.6f, 1.0f, 0.0f);
		 glVertex3f(2.6f, 1.0f, 0.0f);
		 //Rectangulo vertical izquierda
		 glVertex3f(2.6f, -0.5f, 0.0f);
		 glVertex3f(3.2f, -0.5f, 0.0f);
		 glVertex3f(3.2f, 0.5f, 0.0f);
		 glVertex3f(2.6f, 0.5f, 0.0f);
		 //Rectangulo vertical derecha chica
		 glVertex3f(4.0f, -0.5f, 0.0f);
		 glVertex3f(4.6f, -0.5f, 0.0f);
		 glVertex3f(4.6f, 0.1f, 0.0f);
		 glVertex3f(4.0f, 0.1f, 0.0f);
		 //Rectangulo horizontal central chico
		 glVertex3f(4.0f, 0.1f, 0.0f);
		 glVertex3f(3.6f, 0.1f, 0.0f);
		 glVertex3f(3.6f, -0.2f, 0.0f);
		 glVertex3f(4.0f, -0.2f, 0.0f);
	 glEnd();

	 //glFlush();
	 glutSwapBuffers ( );
	 return;
} 

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
	  return;
}    

// Main del programa.
int main(int argc, char **argv)
{ 
	 // Inicializo OpenGL
	 glutInit(&argc, argv);
	 
	 // Activamos buffer simple y colores del tipo RGB  
	 //glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH);
	 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);

	 // Definimos una ventana de medidas 300 x 300 como ventana 
	 // de visualizacion en pixels
	 glutInitWindowSize (600, 600);
	 
	 // Posicionamos la ventana en la esquina superior izquierda de 
	 // la pantalla.
	 glutInitWindowPosition (100, 100);

	 // Creamos literalmente la ventana y le adjudicamos el nombre que se
	 // observara en su barra de titulo.
	 glutCreateWindow ("Practica 2");

	 // Inicializamos el sistema 
	 init();

	 glutDisplayFunc(display); 
	 glutReshapeFunc(reshape);
	 glutKeyboardFunc(keyboard);
	 glutMainLoop();
	 
	 // ANSI C requiere que main retorne un valor entero.
	 return 0;
}



