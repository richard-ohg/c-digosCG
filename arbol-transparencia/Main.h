
//	Archivo de cabecera para compilación en sistemas GNU/Linux y macOS
//	Para compilar con g++ en macOS:
//		g++ main.cpp -o main -framework Carbon -framework OpenGL -framework GLUT
//	Para compilar con g++ en GNU/Linux
//		g++ main.cpp -o main -lGL -lGLU -lglut

#ifndef _MAIN_H
#define _MAIN_H

#if __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#elif __linux__
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
#endif

#include <cmath>			//	Funciones matemáticas
#include <cstdio>			// 	Funciones de entrada/salida
#include <cstdlib>			// 	Biblioteca estándar
#include <cstring>			//	Manejo de cadenas
#include <ctime>			//	Tiempo del sistema, generación de números aleatorios

#endif 