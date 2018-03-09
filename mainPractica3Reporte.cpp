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
	//glTranslatef(0.0f, 0.0f, -10.0f);


	//Poner aqui codigo a dibujar
	//Aquí va el código de los ejercicios
	 
	

	/*------------------------CUBO-------------------------------*/
	/*
	//verde - cara frontal
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	//azul - cara del fondo
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glEnd();

	//cyan - cara arriba
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(0.0, 1.0, -1.0);
	glEnd();

	//rojo - cara del lado derecho
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, 0.0);
	glEnd();

	//blanco - cara de abajo
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -1.0);
	glVertex3f(1.0, 0.0, -1.0);
	glEnd();

	//amarillo - cara del lado izquierdo
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 1.0, -1.0);
	glEnd();
	*/
	


	/*------------------------ OJOS BOB ESPONJA -------------------------------*/
	
	//----- Fondo cyan -----
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(4.0, 5.0, 0.0);
	glVertex3f(30.0, 5.0, 0.0);
	glVertex3f(30.0, 15.0, 0.0);
	glVertex3f(4.0, 15.0, 0.0);
	glEnd();

	//----- Cara amarilla -----
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(5.0, 5.0, 0.0);
	glVertex3f(29.0, 5.0, 0.0);
	glVertex3f(29.0, 15.0, 0.0);
	glVertex3f(5.0, 15.0, 0.0);
	glEnd();

	//----- Gafas negras -----
	//Rectangulo horizontal grande
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(4.75, 12.0, 0.0);
	glVertex3f(29.25, 12.0, 0.0);
	glVertex3f(29.25, 13.0, 0.0);
	glVertex3f(4.75, 13.0, 0.0);
	glEnd();
	//--- Lente izquierdo ---
	//Rectangulo diagonal izquierdo
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(5.75, 5.5, 0.0);
	glVertex3f(6.25, 5.5, 0.0);
	glVertex3f(5.0, 12.0, 0.0);
	glVertex3f(4.75, 12.0, 0.0);
	glEnd();
	//Rectangulo diagonal derecho
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(15.75, 5.5, 0.0);
	glVertex3f(16.25, 5.5, 0.0);
	glVertex3f(17.25, 12.0, 0.0);
	glVertex3f(16.75, 12.0, 0.0);
	glEnd();
	//Trapecio horizontal izquierdo
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(6.25, 5.5, 0.0);
	glVertex3f(15.75, 5.5, 0.0);
	glVertex3f(16.0, 6.5, 0.0);
	glVertex3f(6.0, 6.5, 0.0);
	glEnd();
	//--- Lente derecho ---
	//Rectangulo diagonal izquierdo
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(17.75, 5.5, 0.0);
	glVertex3f(18.25, 5.5, 0.0);
	glVertex3f(17.25, 12.0, 0.0);
	glVertex3f(16.75, 12.0, 0.0);
	glEnd();
	//Rectangulo diagonal derecho
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(27.75, 5.5, 0.0);
	glVertex3f(28.25, 5.5, 0.0);
	glVertex3f(29.25, 12.0, 0.0);
	glVertex3f(29.0, 12.0, 0.0);
	glEnd();
	//Trapecio horizontal derecho
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(18.25, 5.5, 0.0);
	glVertex3f(27.75, 5.5, 0.0);
	glVertex3f(28.0, 6.5, 0.0);
	glVertex3f(18.0, 6.5, 0.0);
	glEnd();

	//----- Relleno de ojos blancos -----
	//Ojo izquierdo
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(6.0, 6.5, 0.0);
	glVertex3f(16.0, 6.5, 0.0);
	glVertex3f(16.75, 12.0, 0.0);
	glVertex3f(5.0, 12.0, 0.0);
	glEnd();
	//Ojo derecho
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(18.0, 6.5, 0.0);
	glVertex3f(28.0, 6.5, 0.0);
	glVertex3f(29.0, 12.0, 0.0);
	glVertex3f(17.25, 12.0, 0.0);
	glEnd();

	//----- Cejas negras -----
	//Ceja izquierda
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(4.5, 11.5, 0.0);
	glVertex3f(16.5, 11.5, 0.0);
	glVertex3f(16.5, 13.5, 0.0);
	glVertex3f(4.5, 13.5, 0.0);
	glEnd();
	//Ceja derecha
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(17.5, 11.5, 0.0);
	glVertex3f(29.5, 11.5, 0.0);
	glVertex3f(29.5, 13.5, 0.0);
	glVertex3f(17.5, 13.5, 0.0);
	glEnd();

	//----- Ojos externos azules -----
	//Ojo izquierdo
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(12.0, 7.0, 0.0);
	glVertex3f(15.0, 7.0, 0.0);
	glVertex3f(15.0, 10.0, 0.0);
	glVertex3f(12.0, 10.0, 0.0);
	glEnd();
	//Ojo derecho
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(19.0, 7.0, 0.0);
	glVertex3f(22.0, 7.0, 0.0);
	glVertex3f(22.0, 10.0, 0.0);
	glVertex3f(19.0, 10.0, 0.0);
	glEnd();

	//----- Ojos internos negros -----
	//Ojo izquierdo
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(12.5, 7.5, 0.0);
	glVertex3f(14.5, 7.5, 0.0);
	glVertex3f(14.5, 9.5, 0.0);
	glVertex3f(12.5, 9.5, 0.0);
	glEnd();
	//Ojo derecho
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(19.5, 7.5, 0.0);
	glVertex3f(21.5, 7.5, 0.0);
	glVertex3f(21.5, 9.5, 0.0);
	glVertex3f(19.5, 9.5, 0.0);
	glEnd();
	
	
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
	glOrtho(0,34,0,30,0,20);
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
  glutInitWindowPosition (100, 100);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

