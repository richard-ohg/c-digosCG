//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Hernández González Ricardo Omar     	******//
//*************											******//
//************************************************************//
#include "Main.h"
#include "Vector.h"


float transZ = -30.0f;
float transX = 0.0f;
float giroDron = 0.0f;
float AnguloX = 0.0f;
float AnguloY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float giroHelices = 0.0f;
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

//Función para dibujar una media esfera
void dibujaDomoCielo(float radio, int paralelos, int meridianos, int modoRender)
{
	float ang1, ang2;
	float a[3], b[3], c[3], d[3];
	float delta1, delta2;

	delta1 = 180.0f / paralelos;
	delta2 = 360.0f / meridianos;

	//Semiesfera superior (y positivos)
	for (int i = 0; i < paralelos / 2; i++)
	{
		for (int j = 0; j <= meridianos; j++)
		{
			ang1 = i*delta1;
			ang2 = j*delta2;
			a[0] = radio*(float)cos(ang1*PI / 180.0f)*(float)cos(ang2*PI / 180.0f);
			a[1] = radio*(float)sin(ang1*PI / 180.0f);
			a[2] = radio*(float)cos(ang1*PI / 180.0f)*(float)sin(ang2*PI / 180.0f);

			ang1 = (i + 1)*delta1;
			ang2 = j*delta2;
			b[0] = radio*(float)cos(ang1*PI / 180.0f)*(float)cos(ang2*PI / 180.0f);
			b[1] = radio*(float)sin(ang1*PI / 180.0f);
			b[2] = radio*(float)cos(ang1*PI / 180.0f)*(float)sin(ang2*PI / 180.0f);
			ang1 = (i + 1)*delta1;
			ang2 = (j + 1)*delta2;
			c[0] = radio*(float)cos(ang1*PI / 180.0f)*(float)cos(ang2*PI / 180.0f);
			c[1] = radio*(float)sin(ang1*PI / 180.0f);
			c[2] = radio*(float)cos(ang1*PI / 180.0f)*(float)sin(ang2*PI / 180.0f);
			ang1 = i*delta1;
			ang2 = (j + 1)*delta2;
			d[0] = radio*(float)cos(ang1*PI / 180.0f)*(float)cos(ang2*PI / 180.0f);
			d[1] = radio*(float)sin(ang1*PI / 180.0f);
			d[2] = radio*(float)cos(ang1*PI / 180.0f)*(float)sin(ang2*PI / 180.0f);

			//glColor3f(1.0f, 1.0f, 1.0f);

			if (modoRender == 1) glBegin(GL_QUADS);// sólido
			else if (modoRender == 2) glBegin(GL_LINE_LOOP);// alambrado
			glVertex3f(a[0], a[1], a[2]);
			glVertex3f(d[0], d[1], d[2]);
			glVertex3f(c[0], c[1], c[2]);
			glVertex3f(b[0], b[1], b[2]);
			glEnd();

		}
	}
}

//Función para dibujar un cilindro
void dibujaCilindro(float radio, int lados, float altura, int modoRender)
{
	float ang;
	float a[3], b[3], c[3], d[3];
	float delta;
	
	CVector normalVert[4];	//se agrego esta linea
	
	
	delta = 360.0f / lados;
	for (int i = 1; i <= lados; i++) 
	{
	
		ang = i*delta;
		a[0] = radio*(float)cos(ang*PI / 180.0f);
		a[1] = 0.0f;
		a[2] = radio*(float)sin(ang*PI / 180.0f);

		b[0] = a[0];
		b[1] = altura;
		b[2] = a[2];

		ang = (i + 1)*delta;
		c[0] = radio*(float)cos(ang*PI / 180.0f);
		c[1] = altura;
		c[2] = radio*(float)sin(ang*PI / 180.0f);

		d[0] = c[0];
		d[1] = 0.0;
		d[2] = c[2];


	//Cálculo de las normales
		normalVert[0] = CVector(a[0], a[1], a[2]) - CVector(0.0f, 0.0f, 0.0f);
		normalVert[1] = CVector(b[0], b[1], b[2]) - CVector(0.0f, altura, 0.0f);
		normalVert[2] = CVector(c[0], c[1], c[2]) - CVector(0.0f, altura, 0.0f);
		normalVert[3] = CVector(d[0], d[1], d[2]) - CVector(0.0f, 0.0f, 0.0f);

		if (modoRender == 1) glBegin(GL_QUADS);// sólido
		else if (modoRender == 2) glBegin(GL_LINE_LOOP);// alambrado
		glNormal3f(normalVert[0].x, normalVert[0].y, normalVert[0].z);
		glVertex3f(a[0], a[1], a[2]);
		glNormal3f(normalVert[1].x, normalVert[1].y, normalVert[1].z);
		glVertex3f(b[0], b[1], b[2]);
		glNormal3f(normalVert[2].x, normalVert[2].y, normalVert[2].z);
		glVertex3f(c[0], c[1], c[2]);
		glNormal3f(normalVert[3].x, normalVert[3].y, normalVert[3].z);
		glVertex3f(d[0], d[1], d[2]);
		glEnd();

		glBegin(GL_TRIANGLES);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(b[0], b[1], b[2]);
		glVertex3f(0, altura, 0);
		glVertex3f(c[0], c[1], c[2]);
		glEnd();

		glBegin(GL_TRIANGLES);
		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(a[0], a[1], a[2]);
		glVertex3f(d[0], d[1], d[2]);
		glVertex3f(0, 0, 0);
		glEnd();


		//*********
	}
	glColor3f(1.0,1.0,1.0);
}

//Función para dibujar un cilindro de pura línea
void dibujaCilindro2(float radio, int lados, float altura, int modoRender)
{
	float ang;
	float a[3], b[3], c[3], d[3];
	float delta;
	
	CVector normalVert[4];	//se agrego esta linea
	
	delta = 360.0f / lados;
	for (int i = 1; i <= lados; i++) 
	{
	
		ang = i*delta;
		a[0] = radio*(float)cos(ang*PI / 180.0f);
		a[1] = 0.0f;
		a[2] = radio*(float)sin(ang*PI / 180.0f);

		b[0] = a[0];
		b[1] = altura;
		b[2] = a[2];

		ang = (i + 1)*delta;
		c[0] = radio*(float)cos(ang*PI / 180.0f);
		c[1] = altura;
		c[2] = radio*(float)sin(ang*PI / 180.0f);

		d[0] = c[0];
		d[1] = 0.0;
		d[2] = c[2];

	//Cálculo de las normales
		normalVert[0] = CVector(a[0], a[1], a[2]) - CVector(0.0f, 0.0f, 0.0f);
		normalVert[1] = CVector(b[0], b[1], b[2]) - CVector(0.0f, altura, 0.0f);
		normalVert[2] = CVector(c[0], c[1], c[2]) - CVector(0.0f, altura, 0.0f);
		normalVert[3] = CVector(d[0], d[1], d[2]) - CVector(0.0f, 0.0f, 0.0f);

		if (modoRender == 1) glBegin(GL_QUADS);// sólido
		else if (modoRender == 2) glBegin(GL_LINE_LOOP);// alambrado
		glNormal3f(normalVert[0].x, normalVert[0].y, normalVert[0].z);
		glVertex3f(a[0], a[1], a[2]);
		glNormal3f(normalVert[1].x, normalVert[1].y, normalVert[1].z);
		glVertex3f(b[0], b[1], b[2]);
		glNormal3f(normalVert[2].x, normalVert[2].y, normalVert[2].z);
		glVertex3f(c[0], c[1], c[2]);
		glNormal3f(normalVert[3].x, normalVert[3].y, normalVert[3].z);
		glVertex3f(d[0], d[1], d[2]);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(b[0], b[1], b[2]);
		glVertex3f(0, altura, 0);
		glVertex3f(c[0], c[1], c[2]);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(a[0], a[1], a[2]);
		glVertex3f(d[0], d[1], d[2]);
		glVertex3f(0, 0, 0);
		glEnd();


		//*********
	}
	glColor3f(1.0,1.0,1.0);
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
	
	glPushMatrix();
		glTranslatef(0.0f, -5.0f, transZ);
		glRotatef(giroX, 1, 0, 0); //giro en mano completa
		glRotatef(giroY, 0, 1, 0); //giro en mano completa
		glRotatef(giroZ, 0, 0, 1); //giro en mano completa

		glPushMatrix();
		glTranslatef(0,12,0);
		glRotatef(giroDron,0,0,1);
		glTranslatef(0,-12,0);
			glPushMatrix(); //base 1

				glPushMatrix(); //cilindro para hélice 1
					glTranslatef(0,2,2);

					glPushMatrix();
						glTranslatef(0,0,2);

						glPushMatrix(); //hélice 1
							glTranslatef(0,0,.5);
							glRotatef(90, 1, 0, 0);
							glRotatef(giroHelices,0,1,0);
							glScalef(.1,6,.7);
							glColor3f(0.0745, 0.3686, 0.6313);
							dibujaCilindro(5,20,0.1,1);
						glPopMatrix();

						glRotatef(90, 1, 0, 0);
						dibujaDomoCielo(0.5,10,10,1);
					glPopMatrix();

					glRotatef(90, 1, 0, 0);
					glColor3f(0.7, 0.0, 0.0);
					dibujaCilindro(0.5,20,2,1); //para las hélices

				glPopMatrix(); //sale cilindro hélice 1
				//glColor3f(1.0, 0.0, 1.0);
				glTranslatef(0,2,3);
				glRotatef(90, 1, 0, 0);
				dibujaCilindro2(6,8,1,2);

			glPopMatrix(); //sale base 1

			glPushMatrix(); //base 2

				glPushMatrix(); //cilindro para hélice 2
					glTranslatef(0,22,2);

					glPushMatrix();
						glTranslatef(0,0,2);

						glPushMatrix(); //hélice 2
							glTranslatef(0,0,.5);
							glRotatef(90, 1, 0, 0);
							glRotatef(giroHelices,0,1,0);
							glScalef(.1,6,.7);
							glColor3f(0.0745, 0.3686, 0.6313);
							dibujaCilindro(5,20,0.1,1);
						glPopMatrix();

						glRotatef(90, 1, 0, 0);
						dibujaDomoCielo(0.5,10,10,1);

					glPopMatrix();
					glRotatef(90, 1, 0, 0);
					glColor3f(0.7, 0.0, 0.0);
					dibujaCilindro(0.5,20,2,1); //para las hélices

				glPopMatrix(); //sale hélice 2

				//glColor3f(1.0, 0.0, 1.0);
				glTranslatef(0,22,2);
				glRotatef(90, 1, 0, 0);
				dibujaCilindro2(6,8,1,2);

			glPopMatrix(); //sale base 2

			glColor3f(0.9098, 0.2352, 0.1176);
			dibujaCilindro(2,20,24,1); //cilindro del dron vertical
			glTranslatef(-12,12,0); //para cilindro horizontal

			glPushMatrix();

				glPushMatrix(); //cilindro para hélice 3
					glTranslatef(2,0,2);

					glPushMatrix();
						glTranslatef(0,0,2);

						glPushMatrix(); //hélice 3
							glTranslatef(0,0,.5);
							glRotatef(90, 1, 0, 0);
							glRotatef(giroHelices,0,1,0);
							glScalef(.1,6,.7);
							glColor3f(0.0745, 0.3686, 0.6313);
							dibujaCilindro(5,20,0.1,1);
						glPopMatrix();

						glRotatef(90, 1, 0, 0);
						dibujaDomoCielo(0.5,10,10,1);

					glPopMatrix();
					glRotatef(90, 1, 0, 0);
					glColor3f(0.7, 0.0, 0.0);
					dibujaCilindro(0.5,20,2,1); //para las hélices

				glPopMatrix(); //sale hélice 3
				//glColor3f(1.0, 0.0, 1.0);
				glTranslatef(2,0,2);
				glRotatef(90, 1, 0, 0);
				dibujaCilindro2(6,8,1,2);

			glPopMatrix();

			glPushMatrix();

				glPushMatrix(); //cilindro para hélice 4
					glTranslatef(22,0,2);

					glPushMatrix();
						glTranslatef(0,0,2);

						glPushMatrix(); //hélice 4
							glTranslatef(0,0,.5);
							glRotatef(90, 1, 0, 0);
							glRotatef(giroHelices,0,1,0);
							glScalef(.1,6,.7);
							glColor3f(0.0745, 0.3686, 0.6313);
							dibujaCilindro(5,20,0.1,1);
						glPopMatrix();

						glRotatef(90, 1, 0, 0);
						dibujaDomoCielo(0.5,10,10,1);
					glPopMatrix();
					glRotatef(90, 1, 0, 0);
					glColor3f(0.7, 0.0, 0.0);
					dibujaCilindro(0.5,20,2,1); //para las hélices

				glPopMatrix(); //sale hélice 4
				//glColor3f(1.0, 0.0, 1.0);
				glTranslatef(22,0,2);
				glRotatef(90, 1, 0, 0);
				dibujaCilindro2(6,8,1,2); //dibuja base

			glPopMatrix();
			glRotatef(270, 0, 0, 1);
			glColor3f(0.9098, 0.2352, 0.1176);
			dibujaCilindro(2,20,24,1); //cilindro del dron horizontal

		glPopMatrix();
		glTranslatef(0,12,0);
		glColor3f(0.5333, 0.0509, 0.0509);
		dibujaDomoCielo(4,10,10,1);
		glRotatef(180,1,0,0);
		glColor3f(0.5333, 0.0509, 0.0509);
		dibujaDomoCielo(4,10,10,1);

	glPopMatrix();

glPopMatrix();

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
		case 'x':
		case 'X':
			giroHelices += 10.0f;
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
		case 'c':
		case 'C':
			giroDron += 10.0f;
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
  glutCreateWindow    ("Dron"); // Nombre de la Ventana
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



