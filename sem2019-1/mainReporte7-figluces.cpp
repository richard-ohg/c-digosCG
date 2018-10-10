//Semestre 2019 - 1//************************************************************//
//************************************************************//
//************** Nombre de Alumno (s): *********************************//
//*************						Obligatorio que venga su nombre					******//
//*************											******//
//************************************************************//
#include "Main.h"
#include "figuras.h"

float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;
int rotX = 0;
int rotY = 0;
int rotZ = 0;

float LuzX = 0.0f;
float LuzY = 0.0f;
float LuzZ = -4.0f;
float AnguloLuz = 80.0f;
bool light = false;//Activar y desactivar luces 

CFiguras figuras;

GLfloat Position[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Posicion de la luz el cuarto parámetro puede ser 1 o 0, si es 0 se considera luz direccional, si es 1 es luz puntual o spotlight
GLfloat VistaLuz[]= { 0.0f, 0.0f, -1.0f, 1.0f };			// vector de direccion del cono
GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values negro
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values blanco
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values blanco

GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular color
GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse_llantas[] = { .2745, .2705, .2745, 1.0 };					// Object Color main 
GLfloat mat_diffuse_palos[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse_asiento[] = { .6274, .2627, .1843, 1.0 };
GLfloat mat_diffuse_palopedal[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat mat_diffuse_manubrio[] = {.1960, .1490, .9372, 1.0 };				// Specular color
GLfloat mat_diffuse_pedal[] = {.9176, .8274, .0705, 1.0 };				// Specular color

void InitGL ( void )     // Inicializamos parametros
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void luces(void)
{
	if (!light)
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT1);
		printf("apagada");
	}
	else
	{
		glEnable(GL_LIGHTING); //habilitamos las luces
		glEnable(GL_LIGHT1); //de 0 a 7
		printf("prendida");
	}
						 //Configuracion luz
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Asignar componente ambiental de la luz
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Asignar componente difusa de la luz
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Asignar componente especular de la luz
	
	glPushMatrix();
	glTranslatef(LuzX, LuzY, LuzZ);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);				// Posicionar la fuente de luz
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, VistaLuz);			// vector de direccion de la fuente de luz si es que no es luz direccional
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, AnguloLuz);
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -1.5f);
	glutWireSphere(0.07, 10.0f, 10.0f);
	glPopMatrix();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	luces();

	glTranslatef(0,0,transZ);

	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
	glRotatef(rotZ, 0, 0, 1);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix(); //llanta izquierda
	glTranslatef(-3, -2, 0);
	glRotatef(90, 1, 0, 0);
	//glColor3f(.2745, .2705, .2745);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_llantas);
	figuras.torus(.5, 1, 20, 20);
	glPopMatrix();

	glPushMatrix(); //llanta derecha
	glTranslatef(3, -2, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(.2745, .2705, .2745);
	figuras.torus(.5, 1, 20, 20);
	glPopMatrix();

	glPushMatrix(); //palo llanta izquierda
	glTranslatef(-3, -2, 0);
	glRotatef(-30, 0, 0, 1);
	//glColor3f(1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_palos);
	figuras.cilindro(.2, 3, 20, 20);
	glPopMatrix();

	glPushMatrix(); //palo llanta derecha
	glTranslatef(3, -2, 0);
	glRotatef(30, 0, 0, 1);
	//glColor3f(1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_palos);
	figuras.cilindro(.2, 5, 20, 20);
	glPopMatrix();

	glPushMatrix(); //palo medio 
	//glTranslatef(3, -2, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(.5, -1.5, 0);
	//glColor3f(1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_palos);
	figuras.cilindro(.2, 3, 20, 20);
	glPopMatrix();

	glPushMatrix(); //palo medio derecho
	glTranslatef(0, -2, 0);
	glRotatef(30, 0, 0, 1);
	//glColor3f(1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_palos);
	figuras.cilindro(.2, 4, 20, 20);
	glPopMatrix();

	glPushMatrix(); //palo medio izquierdo
	glTranslatef(0, -2, 0);
	glRotatef(-30, 0, 0, 1);
	//glColor3f(1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_palos);
	figuras.cilindro(.2, 3, 20, 20);
	glPopMatrix();

	glPushMatrix(); //palo de llanta izquierda a pedal
	glTranslatef(-3, -2, 0);
	glRotatef(-90, 0, 0, 1);
	//glColor3f(1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_palos);
	figuras.cilindro(.2, 3, 20, 20);
	glPopMatrix();

	glPushMatrix(); //asiento
	glTranslatef(-2, 1.5, 0);
	//glColor3f(.6274, .2627, .1843);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_asiento);
	figuras.prisma(.2, .5, 2, 0);
	glPopMatrix();

	glPushMatrix(); //circulo pedal
	glTranslatef(0, -2, .3);
	glRotatef(90, 1, 0, 0);
	//glColor3f(.2745, .2705, .2745);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_llantas);
	figuras.torus(.2, .4, 20, 20);
	glPopMatrix();

	glPushMatrix(); //palo pedal
	glTranslatef(0, -2, .35);
	glRotatef(180, 0, 0, 1);
	//glColor3f(0, 1, 1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_palopedal);
	figuras.cilindro(.1, .5, 20, 20);
	glPopMatrix();
	
	glPushMatrix(); //pedal
	glTranslatef(0, -2.5, .5);
	//glColor3f(.9176, .8274, .0705);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_pedal);
	figuras.prisma(.2, .5, .5, 0);
	glPopMatrix();

	glPushMatrix(); //manubrio palo largo
	glTranslatef(0.5, 2.4, 0);
	//glColor3f(.1960, .1490, .9372);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_manubrio);
	glNormal3f( 1.0f, 0.0f, 0.0f);
	figuras.prisma(.2, .5, 3, 0);
	glPopMatrix();

	glPushMatrix(); //manubrio palo derecho
	glTranslatef(-.2, 2.4, 1.25);
	//glColor3f(.1960, .1490, .9372);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_manubrio);
	//glNormal3f( 1.0f, 0.0f, 0.0f);
	figuras.prisma(.2, 1, .5, 0);
	glPopMatrix();

	glPushMatrix(); //manubrio palo izquierdo
	glTranslatef(-.2, 2.4, -1.25);
	//glColor3f(.1960, .1490, .9372);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_manubrio);
	//glNormal3f( 1.0f, 0.0f, 0.0f);
	figuras.prisma(.2, 1, .5, 0);
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
			rotX += 10;
			break;
		case 'c':
		case 'C':
			rotY += 10;
			break;
		case 'v':
		case 'V':
			rotZ += 10;
			break;
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
		case 'p':
		case 'P':
			light = !light;
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



