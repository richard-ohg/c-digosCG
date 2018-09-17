//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	 Hernández González Ricardo Omar	    ******//
//*************										    ******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;
int rotX = 0;
int rotY = 0;
int rotZ = 0;

void InitGL ( void )     // Inicializamos parametros
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void tetraedro(void)
{
	GLfloat vertice [4][3] = {
				{-0.5 , -0.5, -0.5},    //Coordenadas Vértice 0 V0
				{0.5 , -0.5, -0.5},    //Coordenadas Vértice 1 V1
				{0.0 , 0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.0 , 0.0, 0.5},    //Coordenadas Vértice 3 V3
				};	

	glBegin(GL_POLYGON);  
		glColor3f(0.0,1.0,1.0);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(0.0,0.0,1.0);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(1.0,0.0,0.0);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[3]);
		glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(0.0,1.0,0.0);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[3]);
		glVertex3fv(vertice[2]);
	glEnd();
}

void octaedro(void)
{
	GLfloat vertice [6][3] = {
				{-0.5 , -0.5, -0.5},    //Coordenadas Vértice 0 V0
				{0.5 , -0.5, -0.5},    //Coordenadas Vértice 1 V1
				{0.5 , 0.5, -0.5},    //Coordenadas Vértice 2 V2
				{-0.5 , 0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.0 , 0.0, .5},    //Coordenadas Vértice 4 V4
				{0.0 , 0.0, -1.5},    //Coordenadas Vértice 5 V5
				};	

	glBegin(GL_POLYGON);   // base 
		glColor3f(1.0,1.0,1.0);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Parte de arriba
		glColor3f(1.0,0.0,0.0);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(0.0,1.0,0.0);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(0.0,0.0,1.0);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[3]);
		glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(0.0,1.0,1.0);
		glVertex3fv(vertice[3]);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);  //Parte de abajo
		glColor3f(1.0,1.0,0.0);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(1.0,0.0,1.0);
		glVertex3fv(vertice[1]);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(0.5,0.5,0.5);
		glVertex3fv(vertice[2]);
		glVertex3fv(vertice[3]);
		glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);  
		glColor3f(0.1,0.3,0.5);
		glVertex3fv(vertice[3]);
		glVertex3fv(vertice[0]);
		glVertex3fv(vertice[5]);
	glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, transZ);

	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
	glRotatef(rotZ, 0, 0, 1);

	glPushMatrix(); // Dibujamos tetraedro
	//glTranslatef(-2.0f, 0.0f, 0); 
	glScalef(3, 3, 3);
	tetraedro();
	glPopMatrix(); 
	
	glPushMatrix(); 
	glTranslatef(2.0f, 0.0f, 0); 
	glScalef(3, 3, 3);
	//octaedro();
	glPopMatrix(); 



	glutSwapBuffers ( );
	//glFlush();
	// Swap The Buffers
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

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'x':
		case 'X':
			rotX+=10;
			break;
		case 'c':
		case 'C':
			rotY+=10;
			break;
		case 'v':
		case 'V':
			rotZ+=10;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



