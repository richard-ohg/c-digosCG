//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Hernández González Ricardo Omar			******//
//*************	Ferrusca Ortiz Jorge Luis				******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

#if (_MSC_VER >=1900)
#pragma comment (lib,"legacy_stdio_definitions.lib")
#endif

#define PI (3.14159265358979323846)

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

void* font=GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture text1; // skybox
CTexture text2; // ventana
CTexture text3;	// paredes	
CTexture text4;	// puerta
CTexture text5;	//fantasma
CTexture text6;	

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito
CFiguras fig8; // cuartos


//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroPuerta = 0;
float giroVentana = 0;

float movfantX = 0;
float movfantY = 0;
bool animac = false;
bool animac2 = false;
bool animac3 = false;
bool animac4 = false;
bool animac5 = false;

float grados = 0;

#define MAX_FRAMES 20
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float giroPuerta;
	float giroPuertaInc;
	float giroVentana;
	float giroVentanaInc;

	

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 11;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, timebase = 0;
char s[30];


			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("ventana.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("piso.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("puerta.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("fantasma.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();



	objCamera.Position_Camera(10,2.5f,30, 10,2.5f,10, 0, 1, 0);
/*
	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
	KeyFrame[i].posX =0;
	KeyFrame[i].posY =0;
	KeyFrame[i].posZ =0;
	KeyFrame[i].incX =0;
	KeyFrame[i].incY =0;
	KeyFrame[i].incZ =0;
	KeyFrame[i].rotRodIzq =0;
	KeyFrame[i].rotInc =0;
	KeyFrame[i].giroMonito =0;
	KeyFrame[i].giroMonitoInc =0;
	KeyFrame[i].movBrazoDerZ =0;
	KeyFrame[i].movBrazoDerIncZ  = 0;
	KeyFrame[i].movBrazoIzqZ = 0;
	KeyFrame[i].movBrazoIzqIncZ = 0;
	KeyFrame[i].movCintura = 0;
	KeyFrame[i].movCinturaInc = 0;
	

	}
	*/

	KeyFrame[0].giroVentana = 0.000000; 
	KeyFrame[0].giroPuerta = 0.000000;

	KeyFrame[1].giroVentana = 78.000000;	
	KeyFrame[1].giroPuerta = 0.000000;

	KeyFrame[2].giroVentana = 78.000000; 
	KeyFrame[2].giroPuerta = -74.000000;

	KeyFrame[3].giroVentana = 78.000000; 
	KeyFrame[3].giroPuerta = 74.000000;

	KeyFrame[4].giroVentana = 78.000000; 
	KeyFrame[4].giroPuerta = 0.000000;

	KeyFrame[5].giroVentana = 78.000000; 
	KeyFrame[5].giroPuerta = -59.000000;

	KeyFrame[6].giroVentana = 78.000000; 
	KeyFrame[6].giroPuerta = 0.000000;

	KeyFrame[7].giroVentana = 4.000000; 
	KeyFrame[7].giroPuerta = 0.000000; 

	KeyFrame[8].giroVentana = -75.000000; 
	KeyFrame[8].giroPuerta = 0.000000; 

	KeyFrame[9].giroVentana = 53.000000; 
	KeyFrame[9].giroPuerta = 0.000000;

	KeyFrame[10].giroVentana = 0.000000; 
	KeyFrame[10].giroPuerta = 0.000000;

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	srand(time(NULL));

	glPushMatrix();

		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0,5,9.5);
				glPushMatrix();
					glTranslatef(0,0,-9.5);
					glTranslatef(movfantX,movfantY,0);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					int num=rand()%100;
					if (num < 51)
					{
						fig8.prisma(5, 5, 0, text5.GLindex); //fantasma
					}
					glDisable(GL_ALPHA_TEST);
					glDisable(GL_BLEND);
				glPopMatrix();
				glPushMatrix();
					glTranslatef(21,0,0);
					fig8.prisma(20,20,1,text3.GLindex); //pared frente - 2do cuarto 
					glTranslatef(0,0,-19);
					fig8.prisma(20,20,1,text3.GLindex); //pared fondo - 2do cuarto
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0,0,-19);
					fig8.prisma(20,20,1,text3.GLindex); //pared fondo - 1er cuarto
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-5,0,0);
					fig8.prisma(20,10,1,text3.GLindex); //pared frente - 1er cuarto - izq
				glPopMatrix();
				glPushMatrix();
					glTranslatef(5,-5,0);
					fig8.prisma(10,10,1,text3.GLindex); //pared frente - 1er cuarto - abajo ventana
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0,4,0);
					glRotatef(giroVentana,0,1,0);
					glPushMatrix();
						glTranslatef(4,0,0);
						//glColor3f(0,1,1);
						//glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
						glEnable(GL_ALPHA_TEST);
						glAlphaFunc(GL_GREATER,0.1);
						glEnable(GL_BLEND);
						glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
						fig8.prisma(8,8,0,text2.GLindex); //pared frente - 1er cuarto - ventana
						glDisable(GL_ALPHA_TEST);
						glDisable(GL_BLEND);
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(5,9,0);
					//glColor3f(1,0,0);
					fig8.prisma(2,10,1,text3.GLindex); //pared frente - 1er cuarto - arriba ventana
				glPopMatrix();
				glPushMatrix();
					glTranslatef(9,4,0);
					//glColor3f(0,1,0);
					fig8.prisma(8,2,1,text3.GLindex); //pared frente - 1er cuarto - derecha ventana
				glPopMatrix();

				//fig8.prisma(20,20,1,0); //pared frente - 1er cuarto
			glPopMatrix();

			glPushMatrix();
				glTranslatef(10.5,5,0);
				glRotatef(90,0,1,0);
				glPushMatrix();
					glTranslatef(0,0,-21);
					//glColor3f(0,0,1);
					fig8.prisma(20,20,1,text3.GLindex);	// Pared derecha			
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0,0,21);
					//glColor3f(0,0,1);
					fig8.prisma(20,20,1,text3.GLindex); // Pared izquierda
				glPopMatrix();
				//glColor3f(0,0,1);
				glPushMatrix();
					glTranslatef(6.5,0,0);
					fig8.prisma(20,7,1,text3.GLindex); // Pared enmedio - derecho
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-6.5,0,0);
					fig8.prisma(20,7,1,text3.GLindex); // Pared enmedio - izquierdo
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0,5,0);
					fig8.prisma(10,6,1,text3.GLindex); // Pared enmedio - arriba
				glPopMatrix();
				glPushMatrix();
					glTranslatef(3,-5,0);
					glRotatef(giroPuerta,0,1,0);
					glPushMatrix();
						glTranslatef(-3,0,0);
						//glColor3f(1,1,0);
						glDisable(GL_LIGHTING);
						fig8.prisma(10,6,1,text4.GLindex); // Pared enmedio - puerta
					glPopMatrix();
				glPopMatrix();
				//fig8.prisma(20,20,1,0); // Pared enmedio
				
			glPopMatrix();
			
		glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
		glColor3f(1.0,0.0,0.0);
		pintaTexto(-12,12.0,-14.0,(void *)font,"Practica 11");
		pintaTexto(-12,10.5,-14,(void *)font,"Key Frame");
		glColor3f(1.0,1.0,1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	

	glutSwapBuffers ( );

}

void animacion()
{

	if(animac) {
		movfantX += 0.01;
		grados++;
		movfantY = 4*(sin((grados*PI)/180));
		if (movfantX > 8) {
			animac = false;
			animac2 = true;
		}
	}
	if (animac2) {
		movfantX -= 0.01;
		grados++;
		movfantY = 4*(sin((grados*PI)/180));
		if (movfantX < -8) {
			animac2 = false;
			animac = true;
		}
	}
	
	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroVentanaInc = (KeyFrame[playIndex + 1].giroVentana - KeyFrame[playIndex].giroVentana) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroPuertaInc = (KeyFrame[playIndex + 1].giroPuerta - KeyFrame[playIndex].giroPuerta) / i_max_steps;		//100 frames
				
				printf("Inc x: %f", KeyFrame[playIndex].incX);
			}
		}
		else
		{	//Draw information
			posX += KeyFrame[playIndex].incX;
			giroVentana += KeyFrame[playIndex].giroVentanaInc;
			giroPuerta += KeyFrame[playIndex].giroPuertaInc;
			
			i_curr_steps++;
		}

	}

	frame++;
	/*time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}*/

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'k':		//
		case 'K':
			if (FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n", FrameIndex);

				KeyFrame[FrameIndex].posX = posX;
				KeyFrame[FrameIndex].giroVentana = giroVentana;
				KeyFrame[FrameIndex].giroPuerta = giroPuerta;

				printf("KeyFrame[%i].giroVentana = %f \n", FrameIndex, giroVentana);
				printf("KeyFrame[%i].giroPuerta = %f \n", FrameIndex, giroPuerta);
				

				FrameIndex++;
			}

			break;

		case 'l':
		case 'L':
			if (play == false && (FrameIndex>1))
			{

				posX = KeyFrame[0].posX;

				//First Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroVentanaInc = (KeyFrame[playIndex + 1].giroVentana - KeyFrame[playIndex].giroVentana) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroPuertaInc = (KeyFrame[playIndex + 1].giroPuerta - KeyFrame[playIndex].giroPuerta) / i_max_steps;		//100 frames
				
				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;

		case 'y':
			movfantX++;
			//printf("%f \n", posZ);
			break;
		case 'u':
			movfantX--;
			//printf("%f \n", posZ);
			break;

		case 'i':
			movfantY++;
			//printf("%f \n", posX);
			break;
		case 'o':
			movfantY--;
			//printf("%f \n", posX);
			break;
		case 'p':
			animac^=true;
			//printf("%f \n", posX);
			break;
		case 'v':
		case 'V':
			giroVentana++;
			printf("giroVentana: %f \n", giroVentana);
			break;
		case 'b':
		case 'B':
			giroVentana--;
			printf("giroVentana: %f \n", giroVentana);
			break;
		case 'n':
		case 'N':
			giroPuerta++;
			printf("giroPuerta: %f \n", giroPuerta);
			break;
		case 'm':
		case 'M':
			giroPuerta--;
			printf("giroPuerta: %f \n", giroPuerta);
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
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
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
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc(animacion);
  glutMainLoop        ( );          // 

  return 0;
}
