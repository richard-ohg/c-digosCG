#include <GL/gl.h>     // The GL Header File
#include <stdio.h>

#include <math.h>

class CFiguras
{
public:
		void prisma (float altura, float largo, float profundidad, GLuint text);
		void skybox (float altura, float largo, float profundidad, GLuint text);
		void torus(float radioM, float radiom, int meridianos, int paralelos, GLuint text);
		void prisma_text( GLuint text, GLuint text2);
		void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
		void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
		void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
};
