//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Hernández González Ricardo Omar			******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#if (_MSC_VER >=1900)
#pragma comment (lib,"legacy_stdio_definitions.lib")
#endif

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

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito


//Animación del coche
float movKit = 0.0;
float giroLlanta= 0.0;
float giroAuto = 0.0;
bool g_fanimacion = false;
bool g_fanimacion2 = false;
bool sube = false;
bool recto = false;
bool baja = false;

//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroMonito = 0;
float movBrazoDerZ = 0.0;
float movBrazoIzqZ = 0.0;
float movBrazoDerX = 0.0;
float movBrazoIzqX = 0.0;
float movCintura = 0.0;

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
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	float movBrazoDerZ;
	float movBrazoDerIncZ;
	float movBrazoIzqZ;
	float movBrazoIzqIncZ;
	float movBrazoDerX;
	float movBrazoDerIncX;
	float movBrazoIzqX;
	float movBrazoIzqIncX;
	float movCintura;
	float movCinturaInc;


}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];


void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, text2.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(movBrazoDerZ, 0.0, 0.0, 1.0);
	glRotatef(movBrazoDerX, 0.0, 1.0, 0.0);
	//glRotatef(-61, 0.0, 0.0, 1.0);
	//glRotatef(-45, 0, 1, 0);
	glTranslatef(1.25, 0, 0);
	fig7.prisma(0.7, 2.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(movBrazoIzqZ, 0.0, 0.0, 1.0);
	glRotatef(movBrazoIzqX, 0.0, 1.0, 0.0);
	//glRotatef(61, 0.0, 0.0, 1.0);
	//glRotatef(45, 0, 1, 0);
	//glRotatef(25, 0, 0, 1);
	//glRotatef(25, 1, 0, 0);
	glTranslatef(-1.25, 0, 0);
	fig7.prisma(0.7, 2.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	glRotatef(movCintura, 0.0, 0.0, 1.0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}


			
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

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();



	objCamera.Position_Camera(10,2.5f,13, 10,2.5f,10, 0, 1, 0);
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
	/*
	KeyFrame[0].posX = 0;
	KeyFrame[0].posY = 2.5;
	KeyFrame[0].posZ = -3.5;
	KeyFrame[0].rotRodIzq = 0;
	KeyFrame[0].giroMonito = 0;
	KeyFrame[0].movBrazoDerZ = 0;

	KeyFrame[1].posX = 20;
	KeyFrame[1].posY = 2.5;
	KeyFrame[1].posZ = -3.5;
	KeyFrame[1].rotRodIzq = 60;
	KeyFrame[1].giroMonito = -90.0;
	KeyFrame[1].movBrazoDerZ = 40;

	KeyFrame[2].posX = 20;
	KeyFrame[2].posY = 2.5;
	KeyFrame[2].posZ = 4.0;
	KeyFrame[2].rotRodIzq = -20.0;
	KeyFrame[2].giroMonito = 0;
	KeyFrame[2].movBrazoDerZ = 0;

	KeyFrame[3].posX = 20;
	KeyFrame[3].posY = 2.5;
	KeyFrame[3].posZ = 4.0;
	KeyFrame[3].rotRodIzq = 40.0;
	KeyFrame[3].giroMonito = 45;
	KeyFrame[3].movBrazoDerZ = 90;

	KeyFrame[4].posX = 20;
	KeyFrame[4].posY = 2.5;
	KeyFrame[4].posZ = 4.0;
	KeyFrame[4].rotRodIzq = -40.0;
	KeyFrame[4].giroMonito = -45;
	KeyFrame[4].movBrazoDerZ = -90;

	KeyFrame[0].posY = 2.5;
	KeyFrame[0].movBrazoDerZ = 0;
	KeyFrame[0].movBrazoDerZ = 0;
	KeyFrame[0].movBrazoDerZ = 0;
	KeyFrame[0].movBrazoDerZ = 0;
	KeyFrame[0].movBrazoDerZ = 0;
	KeyFrame[0].movBrazoDerZ = 0;
	//NEW//////////////////NEW//////////////////NEW//////////////////
	*/



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
	
	glPushMatrix();

		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glColor3f(1, 1, 1);
		//glScalef(0.5, 0.5, 0.5);
		//monito();
		//glCallList(ciudad_display_list);
		glTranslatef(posX, posY, posZ);
		glRotatef(giroMonito, 0, 1, 0);
		monito();
		glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();
		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			//Para que el comando glColor funcione con iluminacion
			glPushMatrix(); //Camino1
				glTranslatef(0,0.0,0.0);
				glScalef(97,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma_text(text4.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Camino2
				glTranslatef(-23.5,0.0,0.0);
				glScalef(87,0.1,7);
				glDisable(GL_LIGHTING);
				fig3.prisma_text(text4.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Pasto
				glTranslatef(0.0,0.0,-4.0);
				glScalef(87,0.1,1);
				glDisable(GL_LIGHTING);
				fig4.prisma_text(text5.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Pasto
				glTranslatef(0.0,0.0,4.0);
				glScalef(87,0.1,1);
				glDisable(GL_LIGHTING);
				fig4.prisma_text(text5.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Casa01
				glTranslatef(0.0,3.0,7.0);
				glRotatef(90,1,0,0);
				glRotatef(180,0,0,1);
				glScalef(6,5.0,6);
				glDisable(GL_LIGHTING);
				fig5.prisma_text(text6.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Casa01
				glTranslatef(0.0,3.0,-7.0);
				glRotatef(90,1,0,0);
				glScalef(6,5.0,6);
				glDisable(GL_LIGHTING);
				fig5.prisma_text(text6.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glColor3f(1.0,1.0,1.0);

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
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoDerIncZ = (KeyFrame[playIndex + 1].movBrazoDerZ - KeyFrame[playIndex].movBrazoDerZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoIzqIncZ = (KeyFrame[playIndex + 1].movBrazoIzqZ - KeyFrame[playIndex].movBrazoIzqZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoDerIncX = (KeyFrame[playIndex + 1].movBrazoDerX - KeyFrame[playIndex].movBrazoDerX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoIzqIncX = (KeyFrame[playIndex + 1].movBrazoIzqX - KeyFrame[playIndex].movBrazoIzqX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movCinturaInc = (KeyFrame[playIndex + 1].movCintura - KeyFrame[playIndex].movCintura) / i_max_steps;		//100 frames

				printf("Inc x: %f", KeyFrame[playIndex].incX);
			}
		}
		else
		{	//Draw information
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			movBrazoDerZ += KeyFrame[playIndex].movBrazoDerIncZ;
			movBrazoIzqZ += KeyFrame[playIndex].movBrazoIzqIncZ;
			movBrazoDerX += KeyFrame[playIndex].movBrazoDerIncX;
			movBrazoIzqX += KeyFrame[playIndex].movBrazoIzqIncX;
			movCintura += KeyFrame[playIndex].movCinturaInc;
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
				KeyFrame[FrameIndex].posY = posY;
				KeyFrame[FrameIndex].posZ = posZ;

				KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
				KeyFrame[FrameIndex].giroMonito = giroMonito;
				KeyFrame[FrameIndex].movBrazoDerZ = movBrazoDerZ;
				KeyFrame[FrameIndex].movBrazoDerX = movBrazoDerX;
				KeyFrame[FrameIndex].movBrazoIzqZ = movBrazoIzqZ;
				KeyFrame[FrameIndex].movBrazoIzqX = movBrazoIzqX;
				KeyFrame[FrameIndex].movCintura = movCintura;
				printf("KeyFrame[%i].movBrazoDerZ = %f \n", FrameIndex, movBrazoDerZ);
				printf("KeyFrame[%i].movBrazoDerX = %f \n", FrameIndex, movBrazoDerX);
				printf("KeyFrame[%i].movBrazoIzqZ = %f \n", FrameIndex, movBrazoIzqZ);
				printf("KeyFrame[%i].movBrazoIzqX = %f \n", FrameIndex, movBrazoIzqX);
				printf("KeyFrame[%i].movCintura = %f \n", FrameIndex, movCintura);
				printf("KeyFrame[%i].posX = %f \n", FrameIndex, posX);
				printf("KeyFrame[%i].posY = %f \n", FrameIndex, posY);
				printf("KeyFrame[%i].posZ = %f \n", FrameIndex, posZ);

				FrameIndex++;
			}

			break;

		case 'l':
		case 'L':
			if (play == false && (FrameIndex>1))
			{

				posX = KeyFrame[0].posX;
				posY = KeyFrame[0].posY;
				posZ = KeyFrame[0].posZ;
				rotRodIzq = KeyFrame[0].rotRodIzq;
				giroMonito = KeyFrame[0].giroMonito;
				movBrazoDerZ = KeyFrame[0].movBrazoDerZ;
				movBrazoDerZ = KeyFrame[0].movBrazoDerX;
				movBrazoDerZ = KeyFrame[0].movBrazoIzqZ;
				movBrazoDerZ = KeyFrame[0].movBrazoIzqX;
				movCintura = KeyFrame[0].movCintura;

				//First Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//100 frames
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;		//100 frames
				KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoDerIncZ = (KeyFrame[playIndex + 1].movBrazoDerZ - KeyFrame[playIndex].movBrazoDerZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoDerIncX = (KeyFrame[playIndex + 1].movBrazoDerX - KeyFrame[playIndex].movBrazoDerX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoIzqIncZ = (KeyFrame[playIndex + 1].movBrazoIzqZ - KeyFrame[playIndex].movBrazoIzqZ) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movBrazoIzqIncX = (KeyFrame[playIndex + 1].movBrazoIzqX - KeyFrame[playIndex].movBrazoIzqX) / i_max_steps;		//100 frames
				KeyFrame[playIndex].movCinturaInc = (KeyFrame[playIndex + 1].movCintura - KeyFrame[playIndex].movCintura) / i_max_steps;		//100 frames

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
			posZ++;
			//printf("%f \n", posZ);
			break;
		case 'Y':
			posZ--;
			//printf("%f \n", posZ);
			break;

		case 'g':
			posX++;
			//printf("%f \n", posX);
			break;
		case 'G':
			posX--;
			//printf("%f \n", posX);
			break;

		case 'c':
		case 'C':
			movBrazoDerZ++;
			printf("movBrazoDerZ: %f \n", movBrazoDerZ);
			break;
		case 'v':
		case 'V':
			movBrazoDerZ--;
			printf("movBrazoDerZ: %f \n", movBrazoDerZ);
			break;

		case 'z':
		case 'Z':
			movBrazoIzqZ++;
			printf("movBrazoIzqZ: %f \n", movBrazoIzqZ);
			break;
		case 'x':
		case 'X':
			movBrazoIzqZ--;
			printf("movBrazoIzqZ: %f \n", movBrazoIzqZ);
			break;
		case 'o':
		case 'O':
			movBrazoDerX++;
			printf("movBrazoDerX: %f \n", movBrazoDerX);
			break;
		case 'p':
		case 'P':
			movBrazoDerX--;
			printf("movBrazoDerX: %f \n", movBrazoDerX);
			break;
		case 'u':
		case 'U':
			movBrazoIzqX++;
			printf("movBrazoIzqX: %f \n", movBrazoIzqX);
			break;
		case 'i':
		case 'I':
			movBrazoIzqX--;
			printf("movBrazoIzqX: %f \n", movBrazoIzqX);
			break;
		case 'n':
		case 'N':
			movCintura++;
			printf("movCintura: %f \n", movCintura);
			break;
		case 'm':
		case 'M':
			movCintura--;
			printf("movCintura: %f \n", movCintura);
			break;

		case 'b':
			giroMonito++;
			//printf("%f \n", giroMonito);
			break;

		case 'B':
			giroMonito--;
			//printf("%f \n", giroMonito);
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
  glutCreateWindow    ("Practica 10"); // Nombre de la Ventana
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
