//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Hernández González Ricardo Omar     	******//
//*************											******//
//************************************************************//
#include "Main.h"

#define MAX_FRAMES 5
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames

	float transZ;
	float transX;
	float giroX;
	float giroY;
	float giroZ;

	float giroNudillo1;
	float giroNudillo1Z;
	float giroArt11;
	float giroArt21;
	float giroNudillo2;
	float giroNudillo2Z;
	float giroArt12;
	float giroArt22;
	float giroNudillo3;
	float giroArt13;
	float giroArt23;
	float giroNudillo4;
	float giroArt14;
	float giroArt24;
	float giroNudillo5;
	float giroArt15;

	float IncZ;
	float IncX;
	float IncRotX;
	float IncRotY;
	float IncRotZ;

	float rotInc;
	float rotInc2;
	float rotInc3;
	float rotInc4;
	float rotInc5;
	float rotInc6;
	float rotInc7;
	float rotInc8;
	float rotInc9;
	float rotInc10;
	float rotInc11;
	float rotInc12;
	float rotInc13;
	float rotInc14;
	float rotInc15;
	float rotInc16;
	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame=0,timebase=0;
char s[30];


float transZ = -11.0f;
float transX = 0.0f;
float AnguloX = 0.0f;
float AnguloY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float giroNudillo1 = 0.0f;
float giroNudillo1Z = 0.0f;
float giroArt11 = 0.0f;
float giroArt21 = 0.0f;
float giroNudillo2 = 0.0f;
float giroNudillo2Z = 0.0f;
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

void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].transZ = transZ;
	KeyFrame[FrameIndex].transX = transX;
	KeyFrame[FrameIndex].giroX = giroX;
	KeyFrame[FrameIndex].giroY = giroY;
	KeyFrame[FrameIndex].giroZ = giroZ;

	KeyFrame[FrameIndex].giroNudillo1 = giroNudillo1;
	KeyFrame[FrameIndex].giroNudillo1Z = giroNudillo1Z;
	KeyFrame[FrameIndex].giroArt11 = giroArt11;
	KeyFrame[FrameIndex].giroArt21 = giroArt21;
	KeyFrame[FrameIndex].giroNudillo2 = giroNudillo2;
	KeyFrame[FrameIndex].giroNudillo2Z = giroNudillo2Z;
	KeyFrame[FrameIndex].giroArt12 = giroArt12;
	KeyFrame[FrameIndex].giroArt22 = giroArt22;
	KeyFrame[FrameIndex].giroNudillo3 = giroNudillo3;
	KeyFrame[FrameIndex].giroArt13 = giroArt13;
	KeyFrame[FrameIndex].giroArt23 = giroArt23;
	KeyFrame[FrameIndex].giroNudillo4 = giroNudillo4;
	KeyFrame[FrameIndex].giroArt14 = giroArt14;
	KeyFrame[FrameIndex].giroArt24 = giroArt24;
	KeyFrame[FrameIndex].giroNudillo5 = giroNudillo5;
	KeyFrame[FrameIndex].giroArt15 = giroArt15;
			
	FrameIndex++;
}

void resetElements( void )
{
	transZ = KeyFrame[0].transZ;
	transX = KeyFrame[0].transX;
	giroX = KeyFrame[0].giroX;
	giroY = KeyFrame[0].giroY;
	giroZ = KeyFrame[0].giroZ;

	giroNudillo1 = KeyFrame[0].giroNudillo1;
	giroNudillo1Z = KeyFrame[0].giroNudillo1Z;
	giroArt11 = KeyFrame[0].giroArt11;
	giroArt21 = KeyFrame[0].giroArt21;
	giroNudillo2 = KeyFrame[0].giroNudillo2;
	giroNudillo2Z = KeyFrame[0].giroNudillo2Z;
	giroArt12 = KeyFrame[0].giroArt12;
	giroArt22 = KeyFrame[0].giroArt22;
	giroNudillo3 = KeyFrame[0].giroNudillo3;
	giroArt13 = KeyFrame[0].giroArt13;
	giroArt23 = KeyFrame[0].giroArt23;
	giroNudillo4 = KeyFrame[0].giroNudillo4;
	giroArt14 = KeyFrame[0].giroArt14;
	giroArt24 = KeyFrame[0].giroArt24;
	giroNudillo5 = KeyFrame[0].giroNudillo5;
	giroArt15 = KeyFrame[0].giroArt15;

}

void interpolation ( void )
{
	KeyFrame[playIndex].IncZ = (KeyFrame[playIndex + 1].transZ - KeyFrame[playIndex].transZ) / i_max_steps;
	KeyFrame[playIndex].IncX = (KeyFrame[playIndex + 1].transX - KeyFrame[playIndex].transX) / i_max_steps;	
	KeyFrame[playIndex].IncRotX = (KeyFrame[playIndex + 1].giroX - KeyFrame[playIndex].giroX) / i_max_steps;
	KeyFrame[playIndex].IncRotY = (KeyFrame[playIndex + 1].giroY - KeyFrame[playIndex].giroY) / i_max_steps;
	KeyFrame[playIndex].IncRotZ = (KeyFrame[playIndex + 1].giroZ - KeyFrame[playIndex].giroZ) / i_max_steps;	

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].giroNudillo1 - KeyFrame[playIndex].giroNudillo1) / i_max_steps;	
	KeyFrame[playIndex].rotInc2 = (KeyFrame[playIndex + 1].giroArt11 - KeyFrame[playIndex].giroArt11) / i_max_steps;
	KeyFrame[playIndex].rotInc3 = (KeyFrame[playIndex + 1].giroArt21 - KeyFrame[playIndex].giroArt21) / i_max_steps;
	KeyFrame[playIndex].rotInc4 = (KeyFrame[playIndex + 1].giroNudillo2 - KeyFrame[playIndex].giroNudillo2) / i_max_steps;
	KeyFrame[playIndex].rotInc5 = (KeyFrame[playIndex + 1].giroArt12 - KeyFrame[playIndex].giroArt12) / i_max_steps;
	KeyFrame[playIndex].rotInc6 = (KeyFrame[playIndex + 1].giroArt22 - KeyFrame[playIndex].giroArt22) / i_max_steps;
	KeyFrame[playIndex].rotInc7 = (KeyFrame[playIndex + 1].giroNudillo3 - KeyFrame[playIndex].giroNudillo3) / i_max_steps;	
	KeyFrame[playIndex].rotInc8 = (KeyFrame[playIndex + 1].giroArt13 - KeyFrame[playIndex].giroArt13) / i_max_steps;
	KeyFrame[playIndex].rotInc9 = (KeyFrame[playIndex + 1].giroArt23 - KeyFrame[playIndex].giroArt23) / i_max_steps;
	KeyFrame[playIndex].rotInc10 = (KeyFrame[playIndex + 1].giroNudillo4 - KeyFrame[playIndex].giroNudillo4) / i_max_steps;
	KeyFrame[playIndex].rotInc11 = (KeyFrame[playIndex + 1].giroArt14 - KeyFrame[playIndex].giroArt14) / i_max_steps;
	KeyFrame[playIndex].rotInc12 = (KeyFrame[playIndex + 1].giroArt24 - KeyFrame[playIndex].giroArt24) / i_max_steps;
	KeyFrame[playIndex].rotInc13 = (KeyFrame[playIndex + 1].giroNudillo5 - KeyFrame[playIndex].giroNudillo5) / i_max_steps;
	KeyFrame[playIndex].rotInc14 = (KeyFrame[playIndex + 1].giroArt15 - KeyFrame[playIndex].giroArt15) / i_max_steps;
	KeyFrame[playIndex].rotInc15 = (KeyFrame[playIndex + 1].giroNudillo1Z - KeyFrame[playIndex].giroNudillo1Z) / i_max_steps;
	KeyFrame[playIndex].rotInc16 = (KeyFrame[playIndex + 1].giroNudillo2Z - KeyFrame[playIndex].giroNudillo2Z) / i_max_steps;

}

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

	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].transZ = 0;
		KeyFrame[i].transX = 0;
		KeyFrame[i].giroX = 0;
		KeyFrame[i].giroY = 0;
		KeyFrame[i].giroZ = 0;
		KeyFrame[i].IncZ = 0;
		KeyFrame[i].IncX = 0;
		KeyFrame[i].IncRotX = 0;
		KeyFrame[i].IncRotY = 0;
		KeyFrame[i].IncRotZ = 0;

		KeyFrame[i].giroNudillo1 = 0;
		KeyFrame[i].giroNudillo1Z = 0;
		KeyFrame[i].giroArt11 = 0;
		KeyFrame[i].giroArt21 = 0;
		KeyFrame[i].giroNudillo2 = 0;
		KeyFrame[i].giroNudillo2Z = 0;
		KeyFrame[i].giroArt12 = 0;
		KeyFrame[i].giroArt22 = 0;
		KeyFrame[i].giroNudillo3 = 0;
		KeyFrame[i].giroArt13 = 0;
		KeyFrame[i].giroArt23 = 0;
		KeyFrame[i].giroNudillo4 = 0;
		KeyFrame[i].giroArt14 = 0;
		KeyFrame[i].giroArt24 = 0;
		KeyFrame[i].giroNudillo5 = 0;
		KeyFrame[i].giroArt15 = 0;

		KeyFrame[i].rotInc = 0;
		KeyFrame[i].rotInc2 = 0;
		KeyFrame[i].rotInc3 = 0;
		KeyFrame[i].rotInc4 = 0;
		KeyFrame[i].rotInc5 = 0;
		KeyFrame[i].rotInc6 = 0;
		KeyFrame[i].rotInc7 = 0;
		KeyFrame[i].rotInc8 = 0;
		KeyFrame[i].rotInc9 = 0;
		KeyFrame[i].rotInc10 = 0;
		KeyFrame[i].rotInc11 = 0;
		KeyFrame[i].rotInc12 = 0;
		KeyFrame[i].rotInc13 = 0;
		KeyFrame[i].rotInc14 = 0;
		KeyFrame[i].rotInc15 = 0;
		KeyFrame[i].rotInc16 = 0;
	}

	
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
	glTranslatef(1 + transX, 0.0f, transZ); // Traslación para la palma
	glRotatef(giroX, 1, 0, 0); //giro en mano completa
	glRotatef(giroY, 0, 1, 0); //giro en mano completa
	glRotatef(giroZ, 0, 0, 1); //giro en mano completa

	glPushMatrix();// Nudillo 1
		glTranslatef(1.5f, 1.5f, 0.0f);
		glRotatef(giroNudillo1, 0, 1, 0);
		glRotatef(giroNudillo1Z, 0, 0, 1);

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
		glRotatef(giroNudillo2Z, 0, 0, 1);

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
		glRotatef(giroNudillo5, 1, 0, 0);

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

void animacion()
{

	//Movimiento del monito
	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			transZ += KeyFrame[playIndex].IncZ;
			transX += KeyFrame[playIndex].IncX;
			giroX += KeyFrame[playIndex].IncRotX;
			giroY += KeyFrame[playIndex].IncRotY;
			giroZ += KeyFrame[playIndex].IncRotZ;

			giroNudillo1 += KeyFrame[playIndex].rotInc;
			giroArt11 += KeyFrame[playIndex].rotInc2;
			giroArt21 += KeyFrame[playIndex].rotInc3;
			giroNudillo2 += KeyFrame[playIndex].rotInc4;
			giroArt12 += KeyFrame[playIndex].rotInc5;
			giroArt22 += KeyFrame[playIndex].rotInc6;
			giroNudillo3 += KeyFrame[playIndex].rotInc7;
			giroArt13 += KeyFrame[playIndex].rotInc8;
			giroArt23 += KeyFrame[playIndex].rotInc9;
			giroNudillo4 += KeyFrame[playIndex].rotInc10;
			giroArt14 += KeyFrame[playIndex].rotInc11;
			giroArt24 += KeyFrame[playIndex].rotInc12;
			giroNudillo5 += KeyFrame[playIndex].rotInc13;
			giroArt15 += KeyFrame[playIndex].rotInc14;
			giroNudillo1Z += KeyFrame[playIndex].rotInc15;
			giroNudillo2Z += KeyFrame[playIndex].rotInc16;


			i_curr_steps++;
		}
		
	}


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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
			transZ +=0.2f;
			break;
		case 'W':
			transZ -=0.2f;
			break;
		case 'q':
			transX +=0.2f;
			break;
		case 'Q':
			transX -=0.2f;
			break;
		case 'z':
			giroNudillo1 += 10.0f;
			break;
		case 'Z':
			giroNudillo1 -= 10.0f;
			break;
		case 'x':
			giroArt11 += 10.0f;
			break;
		case 'X':
			giroArt11 -= 10.0f;
			break;
		case 'c':
			giroArt21 += 10.0f;
			break;
		case 'C':
			giroArt21 -= 10.0f;
			break;
		case 'v':
			giroNudillo2 += 10.0f;
			break;
		case 'V':
			giroNudillo2 -= 10.0f;
			break;
		case 'b':
			giroArt12 += 10.0f;
			break;
		case 'B':
			giroArt12 -= 10.0f;
			break;
		case 'n':
			giroArt22 += 10.0f;
			break;
		case 'N':
			giroArt22 -= 10.0f;
			break;
		case 't':
			giroNudillo3 += 10.0f;
			break;
		case 'T':
			giroNudillo3 -= 10.0f;
			break;
		case 'y':
			giroArt13 += 10.0f;
			break;
		case 'Y':
			giroArt13 -= 10.0f;
			break;
		case 'u':
			giroArt23 += 10.0f;
			break;
		case 'U':
			giroArt23 -= 10.0f;
			break;
		case 'i':
			giroNudillo4 += 10.0f;
			break;
		case 'I':
			giroNudillo4 -= 10.0f;
			break;
		case 'o':
			giroArt14 += 10.0f;
			break;
		case 'O':
			giroArt14 -= 10.0f;
			break;
		case 'p':
			giroArt24 += 10.0f;
			break;
		case 'P':
			giroArt24 -= 10.0f;
			break;
		case 'h':
			giroNudillo5 -= 10.0f;
			break;
		case 'H':
			giroNudillo5 += 10.0f;
			break;
		case 'j':
			giroArt15 -= 10.0f;
			break;
		case 'J':
			giroArt15 += 10.0f;
			break;
		case 'a':
			giroX += 10.0f;
			break;
		case 'A':
			giroX -= 10.0f;
			break;
		case 's':
			giroY += 10.0f;
			break;
		case 'S':
			giroY -= 10.0f;
			break;
		case 'd':
			giroZ += 10.0f;
			break;
		case 'D':
			giroZ -= 10.0f;
			break;
		case 'e':
			giroNudillo1Z += 10.0f;
			break;
		case 'E':
			giroNudillo1Z -= 10.0f;
			break;
		case 'r':
			giroNudillo2Z += 10.0f;
			break;
		case 'R':
			giroNudillo2Z -= 10.0f;
			break;

		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'l':						
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
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


void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:	//Save KeyFrame
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;

		case 1:	//Play animation
			if(play==false && FrameIndex >1)
			{

				resetElements();
				//First Interpolation
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}
}

void menu( int id)
{
	
}

int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Reporte Practica 11"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}



