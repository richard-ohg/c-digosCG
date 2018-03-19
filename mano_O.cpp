//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Hernández González Ricardo Omar     	******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float AnguloX = 0.0f;
float AnguloY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float giroNudillo1 = 0.0f;
float giroArt11 = 0.0f;
float giroArt21 = 0.0f;
float giroNudillo2 = 0.0f;
float giroArt12 = 0.0f;
float giroArt22 = 0.0f;
float giroNudillo3 = 0.0f;
float giroArt13 = 0.0f;
float giroArt23 = 0.0f;
float giroNudillo4 = 0.0f;
float giroArt14 = 0.0f;
float giroArt24 = 0.0f;
float giroNudillo5 = 0.0f;
float giroArt15 = 0.0f;
float giroX = 0.0f;
float giroY = 0.0f;
float giroZ = 0.0f;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	/*glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);*/


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
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

		glBegin(GL_POLYGON);	//Front
			//glNormal3f( 0.0f, 0.0f, 1.0f);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
		glColor3f(0.0, 0.0, 1.0);
			//glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
		glColor3f(0.0, 1.0, 0.0);
								//glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
		glColor3f(1.0, 1.0, 1.0);
							  //glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
		glColor3f(0.4, 0.2, 0.6);
							  //glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
		glColor3f(0.8, 0.2, 0.4);
							  //glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// ------------------- Comienza dibujo ---------------------
	// Palma
	glPushMatrix(); // stack palma
	glTranslatef(-2.0f, 0.0f, transZ); // Traslación para la palma
	glRotatef(giroX, 1, 0, 0); //giro en mano completa
	glRotatef(giroY, 0, 1, 0); //giro en mano completa
	glRotatef(giroZ, 0, 0, 1); //giro en mano completa
	glRotatef(90, 0, 1, 0);
	glRotatef(90, 0, 0, 1);

	
	glPushMatrix();// Nudillo 1
		glTranslatef(1.5f, 1.5f, 0.0f);
		glRotatef(giroNudillo1, 0, 1, 0);

		glPushMatrix(); //Falange 1
			glTranslatef(1.05f, 0.0f, 0.0f);

			glPushMatrix(); //Articulacion 1 dedo 1
				glTranslatef(1.0f, 0.0f, 0.0f);
				glRotatef(giroArt11, 0, 1, 0);

				glPushMatrix();//falangina 1
					glTranslatef(1.0f, 0.0f, 0.0f);

					glPushMatrix(); //Articulacion 2 dedo 1
						glTranslatef(1.0f, 0.0f, 0.0f);
						glRotatef(giroArt21, 0, 1, 0);

						glPushMatrix();//falangeta 1
							glTranslatef(1.0f, 0.0f, 0.0f);
							glScalef(2.0, 0.5, 2.0);
							glRotatef(90, 1, 0, 0);
							prisma();
						glPopMatrix();

					glPopMatrix();
					glScalef(2.0, .75, 2.0);
					glRotatef(90, 1, 0, 0);
					prisma();
				glPopMatrix();

			glPopMatrix();

			glScalef(2.0, 1.0, 2.0);
			glRotatef(90, 1, 0, 0);
			prisma();
		glPopMatrix();

	glPopMatrix(); // Sale del stack de la falange 1

	//-----------------------------------------------------------------

	glPushMatrix();// Nudillo 2
		glTranslatef(1.5f, 0.5f, 0.0f);
		glRotatef(giroNudillo2, 0, 1, 0);

		glPushMatrix(); //Falange 2
			glTranslatef(1.05f, 0.0f, 0.0f);

			glPushMatrix(); //Articulacion 1 dedo 2
				glTranslatef(1.0f, 0.0f, 0.0f);
				glRotatef(giroArt12, 0, 1, 0);

				glPushMatrix();//falangina 2
					glTranslatef(1.0f, 0.0f, 0.0f);

					glPushMatrix(); //Articulacion 2 dedo 2
						glTranslatef(1.0f, 0.0f, 0.0f);
						glRotatef(giroArt22, 0, 1, 0);

						glPushMatrix();//falangeta 2
							glTranslatef(1.0f, 0.0f, 0.0f);
							glScalef(2.0, 0.5, 2.0);
							glRotatef(180, 1, 0, 0);
							prisma();
						glPopMatrix();

					glPopMatrix();
					glScalef(2.0, .75, 2.0);
					glRotatef(180, 1, 0, 0);
					prisma();
				glPopMatrix();

			glPopMatrix();

			glScalef(2.0, 1.0, 2.0);
			glRotatef(180, 1, 0, 0);
			prisma();
		glPopMatrix();

	glPopMatrix(); // Sale del stack de la falange 2

	//-----------------------------------------------------------------

	glPushMatrix();// Nudillo 3
		glTranslatef(1.5f, -0.5f, 0.0f);
		glRotatef(giroNudillo3, 0, 1, 0);

		glPushMatrix(); //Falange 3
			glTranslatef(1.05f, 0.0f, 0.0f);

			glPushMatrix(); //Articulacion 1 dedo 3
				glTranslatef(1.0f, 0.0f, 0.0f);
				glRotatef(giroArt13, 0, 1, 0);

				glPushMatrix();//falangina 3
					glTranslatef(1.0f, 0.0f, 0.0f);

					glPushMatrix(); //Articulacion 2 dedo 3
						glTranslatef(1.0f, 0.0f, 0.0f);
						glRotatef(giroArt23, 0, 1, 0);

						glPushMatrix();//falangeta 3
						glTranslatef(1.0f, 0.0f, 0.0f);
						glScalef(2.0, 0.5, 2.0);
						glRotatef(270, 1, 0, 0);
						prisma();
						glPopMatrix();

					glPopMatrix();
					glScalef(2.0, .75, 2.0);
					glRotatef(270, 1, 0, 0);
					prisma();
				glPopMatrix();

			glPopMatrix();

			glScalef(2.0, 1.0, 2.0);
			glRotatef(270, 1, 0, 0);
			prisma();
		glPopMatrix();

	glPopMatrix(); // Sale del stack de la falange 3
	

	//-----------------------------------------------------------------

	glPushMatrix();// Nudillo 4
		glTranslatef(1.5f, -1.5f, 0.0f);
		glRotatef(giroNudillo4, 0, 1, 0);

		glPushMatrix(); //Falange 4
			glTranslatef(1.05f, 0.0f, 0.0f);

			glPushMatrix(); //Articulacion 1 dedo 4
				glTranslatef(1.0f, 0.0f, 0.0f);
				glRotatef(giroArt14, 0, 1, 0);

				glPushMatrix();//falangina 4
					glTranslatef(1.0f, 0.0f, 0.0f);

					glPushMatrix(); //Articulacion 2 dedo 4
						glTranslatef(1.0f, 0.0f, 0.0f);
						glRotatef(giroArt24, 0, 1, 0);

						glPushMatrix();//falangeta 4
							glTranslatef(1.0f, 0.0f, 0.0f);
							glScalef(2.0, 0.5, 2.0);
							glRotatef(90, 0, 1, 0);
							prisma();
						glPopMatrix();

					glPopMatrix();
					glScalef(2.0, .75, 2.0);
					glRotatef(90, 0, 1, 0);
					prisma();
				glPopMatrix();

			glPopMatrix();

			glScalef(2.0, 1.0, 2.0);
			glRotatef(90, 0, 1, 0);
			prisma();
		glPopMatrix();

	glPopMatrix(); // Sale del stack de la falange 4

	//---------------------------------------------------------------------------------

	glPushMatrix();// Nudillo 5
		glTranslatef(0.0f, 2.5f, 0.0f);
		glRotatef(270, 1, 0, 0);
		glRotatef(giroNudillo5, 0, 0, 1);

		glPushMatrix(); //Falange 5
			glTranslatef(0.0f, 1.0f, 0.0f);

			glPushMatrix(); //Articulacion 1 dedo 5
				glTranslatef(0.0f, 1.0f, 0.0f);
				glRotatef(giroArt15, 1, 0, 0);

				glPushMatrix();//falangina 5
					glTranslatef(0.0f, 1.0f, 0.0f);
					glScalef(0.75, 2.0, 2.0);
					glRotatef(270, 0, 1, 0);
					prisma();
				glPopMatrix();

			glPopMatrix();

			glScalef(1.0, 2.0, 2.0);
			glRotatef(270, 0, 1, 0);
			prisma();
		glPopMatrix();

	glPopMatrix(); // Sale del stack de la falange 5

	glScalef(3, 5, 1);
	prisma();  // Dibujar palma
	glPopMatrix(); // Sale del stack de la palma 

	//fin dibujo

	
	glutSwapBuffers ( ); // Swap The Buffers
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
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'z':
		case 'Z':
			giroNudillo1 += 10.0f;
			break;
		case 'x':
		case 'X':
			giroArt11 += 10.0f;
			break;
		case 'c':
		case 'C':
			giroArt21 += 10.0f;
			break;
		case 'v':
		case 'V':
			giroNudillo2 += 10.0f;
			break;
		case 'b':
		case 'B':
			giroArt12 += 10.0f;
			break;
		case 'n':
		case 'N':
			giroArt22 += 10.0f;
			break;
		case 't':
		case 'T':
			giroNudillo3 += 10.0f;
			break;
		case 'y':
		case 'Y':
			giroArt13 += 10.0f;
			break;
		case 'u':
		case 'U':
			giroArt23 += 10.0f;
			break;
		case 'i':
		case 'I':
			giroNudillo4 += 10.0f;
			break;
		case 'o':
		case 'O':
			giroArt14 += 10.0f;
			break;
		case 'p':
		case 'P':
			giroArt24 += 10.0f;
			break;
		case 'k':
		case 'K':
			giroNudillo5 -= 10.0f;
			break;
		case 'l':
		case 'L':
			giroArt15 += 10.0f;
			break;
		case 'g':
		case 'G':
			giroX += 10.0f;
			break;
		case 'h':
		case 'H':
			giroY += 10.0f;
			break;
		case 'j':
		case 'J':
			giroZ += 10.0f;
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
		AnguloX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		AnguloX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		AnguloY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		AnguloY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
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



