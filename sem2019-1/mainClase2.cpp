/* Este programa dibuja una "Tetera", este objeto esta definido
 * en GLUT, se crea una fuente de luz, y un material */

//Incluimos las librerias
//#include <GL/glut.h>
//#include <stdlib.h>
#include "Main.h"

int rot = 0;

void init(void)
{
	 // Ubicamos la fuente de luz en el punto (1.0, 1.0, 1.0)
	 //GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	 // Activamos la fuente de luz
	 //glEnable(GL_LIGHTING);
	 //glEnable(GL_LIGHT0);

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
 
	 glTranslatef(-3.0,0.0,-20.0);
	 /*glBegin(GL_POLYGON);
	 glColor3f(1.0, 1.0, 0.0);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(3.0f, 2.0f, 0.0f);
		glVertex3f(2.0f, 4.0f, 0.0f);
		glVertex3f(0.0f, 4.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();*/


	 glBegin(GL_LINES);
	 glColor3f(1, 0, 1);
		glVertex3f(-4.0f, 0.0f, 0.0f);
		glVertex3f(-4.0f, 4.0f, 0.0f);

		glVertex3f(-4.0f, 4.0f, 0.0f);
		glVertex3f(-1.0f, 4.0f, 0.0f);

		glVertex3f(-1.0f, 4.0f, 0.0f);
		glVertex3f(-1.0f, 2.0f, 0.0f);

		glVertex3f(-1.0f, 2.0f, 0.0f);
		glVertex3f(-4.0f, 2.0f, 0.0f);

		glVertex3f(-4.0f, 2.0f, 0.0f);
		glVertex3f(-2.0f, 0.0f, 0.0f);

	 glEnd();
	 glBegin(GL_LINES);
	 glColor3f(1, 1, 0);
		 glVertex3f(0.0f, 0.0f, 0.0f);
		 glVertex3f(0.0f, 4.0f, 0.0f);

		 glVertex3f(0.0f, 4.0f, 0.0f);
		 glVertex3f(3.0f, 4.0f, 0.0f);

		 glVertex3f(3.0f, 4.0f, 0.0f);
		 glVertex3f(3.0f, 0.0f, 0.0f);

		 glVertex3f(3.0f, 0.0f, 0.0f);
		 glVertex3f(0.0f, 0.0f, 0.0f);

	 glEnd();

	 glBegin(GL_LINES);
	 glColor3f(1, 0, 0);
	 glVertex3f(4.0f, 0.0f, 0.0f);
	 glVertex3f(4.0f, 4.0f, 0.0f);

	 glVertex3f(4.0f, 2.0f, 0.0f);
	 glVertex3f(6.0f, 2.0f, 0.0f);

	 glVertex3f(6.0f, 0.0f, 0.0f);
	 glVertex3f(6.0f, 4.0f, 0.0f);

	 glEnd();

	 glBegin(GL_LINES);
	 glColor3f(0, 1, 1);
	 glVertex3f(7.0f, 0.0f, 0.0f);
	 glVertex3f(7.0f, 4.0f, 0.0f);

	 glVertex3f(7.0f, 4.0f, 0.0f);
	 glVertex3f(9.0f, 4.0f, 0.0f);

	 glVertex3f(7.0f, 0.0f, 0.0f);
	 glVertex3f(10.0f, 0.0f, 0.0f);

	 glVertex3f(10.0f, 0.0f, 0.0f);
	 glVertex3f(10.0f, 2.0f, 0.0f);

	 glVertex3f(10.0f, 2.0f, 0.0f);
	 glVertex3f(9.0f, 2.0f, 0.0f);
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

		case 'x':
			rot += 10;
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
	 glutCreateWindow ("Tetera");

	 // Inicializamos el sistema 
	 init();

	 glutDisplayFunc(display); 
	 glutReshapeFunc(reshape);
	 glutKeyboardFunc(keyboard);
	 glutMainLoop();
	 
	 // ANSI C requiere que main retorne un valor entero.
	 return 0;
}



