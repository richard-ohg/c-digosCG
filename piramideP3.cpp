//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview
	//glTranslatef(0.0f, 0.0f, -20.0f);


	//Poner aqui codigo a dibujar
	//Aquí va el código de los ejercicios
	 
	/*----------------------------------EJERCICIO 1 -------------------------------------*/
	//a: rojo centro en: 11,14
	//b verde: Centro en 20,21
	//c azul centro en 3,3
	//d blanco centro en 22,7
	//e amarillo centro en 28,15
	
	/* ejercicio 1
	//B
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(18.0, 19.0, 0.0);
	glVertex3f(22.0, 19.0, 0.0);
	glVertex3f(22.0, 23.0, 0.0);
	glVertex3f(18.0, 23.0, 0.0);
	glEnd();

	//A
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(9.0, 12.0, 0.0);
	glVertex3f(13.0, 12.0, 0.0);
	glVertex3f(13.0, 16.0, 0.0);
	glVertex3f(9.0, 16.0, 0.0);
	glEnd();

	//C
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(5.0, 1.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);
	glVertex3f(1.0, 5.0, 0.0);
	glEnd();

	//D
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(20.0, 5.0, 0.0);
	glVertex3f(24.0, 5.0, 0.0);
	glVertex3f(24.0, 9.0, 0.0);
	glVertex3f(20.0, 9.0, 0.0);
	glEnd();

	//E
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(26.0, 13.0, 0.0);
	glVertex3f(30.0, 13.0, 0.0);
	glVertex3f(30.0, 17.0, 0.0);
	glVertex3f(26.0, 17.0, 0.0);
	glEnd();
	*/

	///* ejercicio 2
	//azul
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(5.0, 1.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);
	glVertex3f(1.0, 5.0, 0.0);
	glEnd();

	//blanco
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(5.0, 1.0, -2.0);
	glVertex3f(9.0, 1.0, -2.0);
	glVertex3f(9.0, 5.0, -2.0);
	glVertex3f(5.0, 5.0, -2.0);
	glEnd();

	//rosa
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(9.0, 1.0, -4.0);
	glVertex3f(13.0, 1.0, -4.0);
	glVertex3f(13.0, 5.0, -4.0);
	glVertex3f(9.0, 5.0, -4.0);
	glEnd();

	//rojo
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(3.0, 5.0, -6.0);
	glVertex3f(7.0, 5.0, -6.0);
	glVertex3f(7.0, 9.0, -6.0);
	glVertex3f(3.0, 9.0, -6.0);
	glEnd();

	//amarillo
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(7.0, 5.0, -8.0);
	glVertex3f(11.0, 5.0, -8.0);
	glVertex3f(11.0, 9.0, -8.0);
	glVertex3f(7.0, 9.0, -8.0);
	glEnd();

	//verde
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(5.0, 9.0, -10.0);
	glVertex3f(9.0, 9.0, -10.0);
	glVertex3f(9.0, 13.0, -10.0);
	glVertex3f(5.0, 13.0, -10.0);
	glEnd();
	//*/

	
	
	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-10,24,-9,21,0,20);
	//glFrustum(-0.1f, 0.1f, -0.1f, 0.1f, 0.1f, 50.0f);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
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
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

