//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float transY= 0.0f;
float AnguloX = 0.0f;
float AnguloY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float LuzX = 0.0f;
float LuzY = 0.0f;
float LuzZ = -4.0f;
float LuzX2 = 0.0f;
float LuzY2 = 0.0f;
float LuzZ2 = -4.0f;
float AnguloLuz = 80.0f;
bool light = false;//Activar y desactivar luces 
bool posicional = false;

GLfloat Position[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Posicion de la luz el cuarto parámetro puede ser 1 o 0, si es 0 se considera luz direccional, si es 1 es luz puntual o spotlight
GLfloat VistaLuz[]= { 0.0f, 0.0f, -1.0f, 1.0f };			// vector de direccion del cono
GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values negro
GLfloat LightDiffuse[] = { 1.0f, 0.0f, 1.0f, 1.0f };				// Diffuse Light Values blanco
GLfloat LightSpecular[] = { 1.0, 0.0, 1.0, 1.0 };				// Specular Light Values blanco
GLfloat LightDiffuse2[] = { 0.0f, 1.0f, 0.0f, 1.0f };				// Diffuse Light Values blanco
GLfloat LightSpecular2[] = { 0.0, 1.0, 0.0, 1.0 };				// Specular Light Values blanco



GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse_verde[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main 
GLfloat mat_diffuse_azul[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_diffuse_rojo[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse_blanco[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_diffuse_morado[] = { 0.4, 0.2, 0.6, 1.0 };
GLfloat mat_diffuse_rosa[] = { 0.8, 0.2, 0.4, 1.0 };
GLfloat mat_specular_azul[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest



void luces(void)
{
	if (!light)
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		printf("apagada");
	}
	else
	{
		glEnable(GL_LIGHTING); //habilitamos las luces
		glEnable(GL_LIGHT1); //de 0 a 7
		glEnable(GL_LIGHT2);
		printf("prendida");
	}
						 //Configuracion luz
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Asignar componente ambiental de la luz
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Asignar componente difusa de la luz
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Asignar componente especular de la luz

	glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient);				// Asignar componente ambiental de la luz
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse2);				// Asignar componente difusa de la luz
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpecular2);				// Asignar componente especular de la luz
	
	glPushMatrix();
	glTranslatef(LuzX, LuzY, LuzZ);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);				// Posicionar la fuente de luz
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, VistaLuz);			// vector de direccion de la fuente de luz si es que no es luz direccional
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, AnguloLuz);
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -0.5f);
	glutWireSphere(0.07, 10.0f, 10.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(LuzX2, LuzY2, LuzZ2);
	glLightfv(GL_LIGHT2, GL_POSITION, Position);				// Posicionar la fuente de luz
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, VistaLuz);			// vector de direccion de la fuente de luz si es que no es luz direccional
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, AnguloLuz);
	glColor3f(0.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, -0.5f);
	glutWireSphere(0.07, 10.0f, 10.0f);
	glPopMatrix();
}

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
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
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_azul);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glColor3f(1.0, 0.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_rojo);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
		glColor3f(0.0, 0.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_azul);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
		glColor3f(0.0, 1.0, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_verde);
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
		glColor3f(1.0, 1.0, 1.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_blanco);
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
		glColor3f(0.4, 0.2, 0.6);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_morado);
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
		glColor3f(0.8, 0.2, 0.4);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_rosa);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	luces();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	
	glPopMatrix();
	//Inicio pirámide
	glPushMatrix(); // 
	glTranslatef(transX, transY, transZ); //
	prisma();           //

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0f, 0.0f, 0.0f);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix();

	glPushMatrix(); //
	glTranslatef(2.0f, 0.0f, 0.0f);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix(); // 

	glPushMatrix(); //
	glTranslatef(.5f, 1.0f, 0.0f);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // 

	glPushMatrix(); //
	glTranslatef(1.5f, 1.0f, 0.0f);
	glRotatef(270, 0, 1, 0);
	prisma();
	glPopMatrix(); // 
	
	glPushMatrix(); //

	glTranslatef(1.0f, 2.0f, 0.0f);
	glRotatef(90, 0, 0, 1);
	prisma();
	glPopMatrix(); // 

	glPopMatrix();

	
	glutSwapBuffers ( );
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
		case 'e':
		case 'E':
			transY += 0.2f;
			break;
		case'q':
		case'Q':
			transY -= 0.2f;
			break;
			//luz 1
		case 'j':
			LuzX += 0.5f;
			break;
		case 'J':
			LuzX -= 0.5f;
			break;
		case 'k':
			LuzY += 0.5f;
			break;
		case 'K':
			LuzY -= 0.5f;
			break;
		case 'l':
			LuzZ += 0.5f;
			break;
		case 'L':
			LuzZ -= 0.5f;
			break;
		case 't':
			LuzX2 += 0.5f;
			break;
		case 'T':
			LuzX2 -= 0.5f;
			break;
		case 'y':
			LuzY2 += 0.5f;
			break;
		case 'Y':
			LuzY2 -= 0.5f;
			break;

		case 'u':
			LuzZ2 += 0.5f;
			break;
		case 'U':
			LuzZ2 -= 0.5f;
			break;
		case 'p':
		case 'P':
			light = !light;
			break;

		case 'n':
			AnguloLuz += 1.0f;
			break;
		case 'N':
			AnguloLuz -= 1.0f;
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
  glutCreateWindow    ("Practica 7"); // Nombre de la Ventana
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



