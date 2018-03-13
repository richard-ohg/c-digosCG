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


void InitGL ( void )     // Inicializamos parametros
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

	//glPolygonMode(GL_FRONT, GL_FILL);
	//glPolygonMode(GL_BACK, GL_LINE);

		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			//glNormal3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			//glNormal3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			//glNormal3f(0.0,0.0,-1.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			//glNormal3f(-1.0,0.0,0.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			//glNormal3f(0.0,-1.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			//glNormal3f(0.0,1.0,0.0);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Rotación mano
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(90, 0, 0, 1);
	glRotatef(180, 1, 0, 0);

	//Equivalente a la otra rotación
	/*glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 0, 1);*/

	//Prueba de ejes
	/*glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(100,0,0);
	glVertex3f(0,0,0);
	glVertex3f(0,100,0);
	glVertex3f(0,0,0);
	glVertex3f(0,0,100);
	glEnd();*/

	//------------------- Palma -------------------------
	glPushMatrix(); // stack palma
	glTranslatef(-2.0f, 0.0f, transZ); // Traslación para la palma
	glScalef(2, 4, 2);
	prisma();           // Dibujar palm
	glPopMatrix(); // Sale del stack de la palma

	//------------------- Dedo medio --------------------
	glPushMatrix();
	glTranslatef(-0.2, 0.1, 0.1);
	glRotatef(-10, 0, 0, 1);
	glPushMatrix(); //Falange
	glTranslatef(-0.25f, 0.2f, transZ);
	glScalef(1.5, 0.75, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange

	glPushMatrix(); //Falangina
	glTranslatef(1.25f, 0.2f, transZ);
	glScalef(1.5, 0.6, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangina

	glPushMatrix(); //Falangeta
	glTranslatef(2.5f, 0.2f, transZ);
	glScalef(1.0, 0.5, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangeta
	glPopMatrix();

	//------------------- Dedo anular --------------------
	glPushMatrix();
	glTranslatef(4.1, 0.0, -5.7);
	glRotatef(90, 0, 1, 0);
	glPushMatrix(); //Falange
	glTranslatef(-0.25f, -0.7f, transZ);
	glScalef(1.5, 0.75, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0.0, -11.0);
	glRotatef(180, 0, 1, 0);
	glPushMatrix(); //Falangina
	glTranslatef(1.1f, -0.7f, transZ);
	glScalef(1.2, 0.6, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangina

	glPushMatrix(); //Falangeta
	glTranslatef(2.15f, -0.7f, transZ);
	glScalef(0.9, 0.5, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangeta
	glPopMatrix();


	//------------------- Dedo meñique --------------------
	glPushMatrix();
	glTranslatef(3.7, 0.0, -5.5);
	glRotatef(90, 0, 1, 0);
	glPushMatrix(); //Falange
	glTranslatef(-0.25f, -1.6f, transZ);
	glScalef(1.5, 0.75, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, 0.0, -10.4);
	glRotatef(180, 0, 1, 0);
	glPushMatrix(); //Falangina
	glTranslatef(0.9f, -1.6f, transZ);
	glScalef(0.8, 0.6, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangina

	glPushMatrix(); //Falangeta
	glTranslatef(1.5f, -1.6f, transZ);
	glScalef(0.6, 0.5, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangeta
	glPopMatrix();

	//------------------- Dedo indice --------------------
	glPushMatrix();
	glTranslatef(-0.1,0.3,0.1);
	glRotatef(10,0,0,1);
	glPushMatrix(); //Falange
	glTranslatef(-0.25f, 1.1f, transZ);
	glScalef(1.5, 0.75, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange

	glPushMatrix(); //Falangina
	glTranslatef(1.2f, 1.1f, transZ);
	glScalef(1.4, 0.6, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangina

	glPushMatrix(); //Falangeta
	glTranslatef(2.35f, 1.1f, transZ);
	glScalef(0.9, 0.5, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangeta
	glPopMatrix();

	//------------------- Dedo gordo ----------------------
	glPushMatrix();
	glTranslatef(0.0, 4.0, -10.4);
	glRotatef(180, 1, 0, 0);
	glPushMatrix(); //Falange
	glTranslatef(-2.0f, 2.5f, transZ);
	glScalef(1.0, 1.0, 2.0);
	glRotatef(270, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange

	glPushMatrix(); //Falangina
	glTranslatef(-2.0f, 3.25f, transZ);
	glScalef(0.5, 0.5, 2.0);
	glRotatef(270, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falangina
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
		case 'a':
		case 'A':
			
			break;
		case 'd':
		case 'D':
	
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



