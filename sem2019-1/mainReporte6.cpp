//Semestre 2019 - 1//************************************************************//
//************************************************************//
//************** Nombre de Alumno (s): *********************************//
//*************		Hernández González Ricardo Omar				******//
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
int rotLlantas = 0;
int rotManubrio = 0;
int rotAsiento = 0;
int rotPedal = 0;

CFiguras figuras;

void InitGL ( void )     // Inicializamos parametros
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0,0,transZ);
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
	glRotatef(rotZ, 0, 0, 1);

	glPushMatrix(); //llanta izquierda
	glTranslatef(-3, -2, 0);
		glPushMatrix(); //palo llanta izquierda
			glRotatef(-30, 0, 0, 1);
			glPushMatrix(); //palo medio
				glTranslatef(0,3,0);
				glRotatef(-60, 0, 0, 1);
				glColor3f(1, 0, 0);
				figuras.cilindro(.2, 3, 20, 20);
			glPopMatrix();
			glColor3f(1, 0, 0);
			figuras.cilindro(.2, 3, 20, 20);
		glPopMatrix(); //sale palo llanta izquierda
		glPushMatrix(); //palo llanta izquierda - pedal
			glRotatef(-90, 0, 0, 1);
			glPushMatrix(); //palo pedal - asiento
				glTranslatef(0,3,0);
				glPushMatrix(); //circulo pedal
					glTranslatef(0, 0, .3);
					glPushMatrix(); //palo pedal
						glTranslatef(0, 0, .05);
						glRotatef(rotPedal, 0, 0, 1);
						glPushMatrix(); //pedal
							glTranslatef(0.5, 0, .15);
							glRotatef(90, 0, 0, 1);
							glColor3f(.9176, .8274, .0705);
							figuras.prisma(.2, .5, .5, 0);
						glPopMatrix(); //sale pedal
						glRotatef(-90, 0, 0, 1);
						glColor3f(0, 1, 1);
						figuras.cilindro(.1, .5, 20, 20);
					glPopMatrix(); //sale palo pedal
					glRotatef(90, 1, 0, 0);
					glColor3f(.2745, .2705, .2745);
					figuras.torus(.2, .4, 20, 20);
				glPopMatrix(); //sale circulo pedal
				glRotatef(120, 0, 0, 1);
				glPushMatrix(); //asiento
					glTranslatef(0,4,0);
					glRotatef(-30, 0, 0, 1);
					glRotatef(rotAsiento, 0, 1, 0);
					glColor3f(.6274, .2627, .1843);
					figuras.prisma(.2, .5, 2, 0);
				glPopMatrix(); //sale asiento
				glColor3f(1, 0, 0);
				figuras.cilindro(.2, 4, 20, 20);
			glPopMatrix(); //sale palo pedal - asiento
			glPushMatrix(); //palo pedal - palo llanta derecha
				glTranslatef(0,3,0);
				glPushMatrix(); //llanta derecha
					glTranslatef(0,3,0);
					glPushMatrix(); //palo llanta derecha
						glRotatef(120, 0, 0, 1);
						glPushMatrix(); //manubrio palo largo
							glTranslatef(0,5,0);
							glRotatef(-30, 0, 0, 1);
							glRotatef(rotManubrio, 0, 1, 0);
							glPushMatrix(); //manubrio palo derecho
								glTranslatef(-.25,0,1.75);
								glColor3f(.1960, .1490, .9372);
								figuras.prisma(.2, 1, .5, 0);
							glPopMatrix(); //sale manubrio palo derecho
							glPushMatrix(); //manubrio palo izquierdo
								glTranslatef(-.25,0,-1.75);
								glColor3f(.1960, .1490, .9372);
								figuras.prisma(.2, 1, .5, 0);
							glPopMatrix(); //sale manubrio palo izquierdo
							glColor3f(.1960, .1490, .9372);
							figuras.prisma(.2, .5, 3, 0);	
						glPopMatrix(); //sale manubrio
						glColor3f(1, 0, 0);
						figuras.cilindro(.2, 5, 20, 20);
					glPopMatrix(); //sale palo llanta derecha
					glRotatef(90, 1, 0, 0);
					glRotatef(rotLlantas, 0, 1, 0);
					glColor3f(.2745, .2705, .2745);
					figuras.torus(.5, 1, 20, 20);	
				glPopMatrix(); //sale llanta derecha
				glRotatef(60, 0, 0, 1);
				glColor3f(1, 0, 0);
				figuras.cilindro(.2, 3, 20, 20);
			glPopMatrix(); //sale palo pedal - palo llanta derecha
			glColor3f(1, 0, 0);
			figuras.cilindro(.2, 3, 20, 20);
		glPopMatrix(); //sale palo llanta izquierda - pedal
	glRotatef(90, 1, 0, 0);
	glRotatef(rotLlantas, 0, 1, 0);
	glColor3f(.2745, .2705, .2745);
	figuras.torus(.5, 1, 20, 20);
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
		case 'i':
		case 'I':
			rotLlantas += 10;
			break;
		case 'o':
		case 'O':
			rotManubrio += 10;
			break;
		case 'p':
		case 'P':
			rotAsiento += 10;
			break;
		case 'l':
		case 'L':
			rotPedal += 10;
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
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
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



