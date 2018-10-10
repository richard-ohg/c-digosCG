//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Agregar Nombre						******//
//*************											******//
//************************************************************//
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;
float LuzX = 0.0f;
float LuzY = 0.0f;
float LuzZ = -4.0f;
float LuzX2 = 0.0f;
float LuzY2 = 0.0f;
float LuzZ2 = -4.0f;

float LightAngle = 80.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;
static int spin2 = 0;


GLfloat LightAmbient[]= { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values

GLfloat LightDiffuse[]= { 1.0f, 0.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 0.0, 1.0, 1.0 };				// Specular Light Values

GLfloat LightDiffuse2[] = { 0.0f, 1.0f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular2[] = { 0.0, 1.0, 0.0, 1.0 };				// Specular Light Values

GLfloat LightPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[]= { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[]= { 0.0f, 0.0f, -1.0f, 1.0 };			// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse_verde[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main 
GLfloat mat_diffuse_azul[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_diffuse_rojo[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse_blanco[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_diffuse_morado[] = { 0.4, 0.2, 0.6, 1.0 };
GLfloat mat_diffuse_rosa[] = { 0.8, 0.2, 0.4, 1.0 };				// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light

	glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse2);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpecular2);				// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One
	glEnable(GL_LIGHT2);
	//glEnable(GL_LIGHT0);

}

void prisma (void)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},		//Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, 0.5},		//Coordenadas Vértice 2 V2
				{-0.5 ,-0.5, -0.5},		//Coordenadas Vértice 3 V3
				{0.5 ,-0.5, -0.5},		//Coordenadas Vértice 4 V4
				{0.5 ,0.5, 0.5},		//Coordenadas Vértice 5 V5
				{0.5 ,0.5, -0.5},		//Coordenadas Vértice 6 V6
				{-0.5 ,0.5, -0.5},		//Coordenadas Vértice 7 V7
				{-0.5 ,0.5, 0.5},		//Coordenadas Vértice 8 V8
				};
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.5,0.0,0.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_rojo);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_azul);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_verde);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_blanco);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_morado);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_rosa);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	glPushMatrix ();

		glTranslatef (0.0, 0.0, -5.0);

		if (!light)
		{
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT2);
		}
		else
		{
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1); //de 0 a 7
			glEnable(GL_LIGHT2);
		}
		glPushMatrix();
			glTranslatef(LuzX, LuzY, LuzZ);
			glTranslatef (0.0, 0.0, 1.5);
			glRotatef (spin, 1.0, 0.0, 0.0);
			glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);				// Posicionar la fuente de luz
			glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection);			// vector de direccion de la fuente de luz si es que no es luz direccional
			glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, LightAngle);
			glColor3f(1.0f, 1.0f, 0.0f);
			glutWireSphere(0.07, 10.0f, 10.0f);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(LuzX2, LuzY2, LuzZ2);
			glTranslatef (0.0, 0.0, 1.5);
			glRotatef (spin2, 1.0, 0.0, 0.0);
			glLightfv(GL_LIGHT2, GL_POSITION, LightPosition);				
			glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, LightDirection);			
			glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, LightAngle);
			glColor3f(0.0f, 1.0f, 1.0f);
			glutWireSphere(0.07, 10.0f, 10.0f);
		glPopMatrix();

		glPushMatrix();
				glTranslatef (transX, transY, transZ);
				glRotatef(angleX, 1.0f, 0.0f, 0.0f);
				glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
				glRotatef(angleY, 0.0f, 1.0f, 0.0f);
				//glColor3f(1.0, 0.0, 0.0);		
				glPushMatrix();
					prisma();		
				glPopMatrix();
				glPushMatrix();
					glTranslatef(1, 0, 0);
					glRotatef(90, 1.0f, 0.0f, 0.0f);
					prisma();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(2, 0, 0);
					glRotatef(180, 1.0f, 0.0f, 0.0f);
					prisma();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(.5, 1, 0);
					glRotatef(270, 1.0f, 0.0f, 0.0f);
					prisma();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(1.5, 1, 0);
					glRotatef(90, 0.0f, 1.0f, 0.0f);
					prisma();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(1, 2, 0);
					glRotatef(270, 0.0f, 1.0f, 0.0f);
					prisma();
				glPopMatrix();

		glPopMatrix();

	glPopMatrix ();
	glutSwapBuffers ( );

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
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix						
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			transZ +=0.5f;
			break;
		case 's':
		case 'S':
			transZ -=0.5f;
			break;
		case 'a':
		case 'A':
			transX -=0.5f;
			break;
		case 'd':
		case 'D':
			transX +=0.5f;
			break;

		//Agregar aquí teclas para movimiento de luz
		case 'i':		//Movimientos de Luz
		case 'I':
			spin = (spin - 20) % 360;
			break;
		case 'k':
		case 'K':
			spin = (spin + 20) % 360;
			break;

		case 'n':		//Movimientos de Luz 2
		case 'N':
			spin2 = (spin2 - 20) % 360;
			break;
		case 'm':
		case 'M':
			spin2 = (spin2 + 20) % 360;
			break;;



		case 'l':   //Activamos/desactivamos luz
		case 'L':
			light=!light;
			break;

		case 'p':   //Activamos/desactivamos luz
		case 'P':
			positional=!positional;
			break;
			//luz 1
		case 'z':
			LuzX += 0.5f;
			break;
		case 'Z':
			LuzX -= 0.5f;
			break;
		case 'x':
			LuzY += 0.5f;
			break;
		case 'X':
			LuzY -= 0.5f;
			break;
		case 'c':
			LuzZ += 0.5f;
			break;
		case 'C':
			LuzZ -= 0.5f;
			break;
		case 'r':
			LuzX2 += 0.5f;
			break;
		case 'R':
			LuzX2 -= 0.5f;
			break;
		case 't':
			LuzY2 += 0.5f;
			break;
		case 'T':
			LuzY2 -= 0.5f;
			break;
		case 'y':
			LuzZ2 += 0.5f;
			break;
		case 'Y':
			LuzZ2 -= 0.5f;
			break;
		case 'b':
			LightAngle += 2.0f;
			printf("Angulo = %f\n", LightAngle);
			break;
		case 'v':
			LightAngle -= 2.0f;
			printf("Angulo = %f\n", LightAngle);
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY -= 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY += 2.0f;
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 7"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}

