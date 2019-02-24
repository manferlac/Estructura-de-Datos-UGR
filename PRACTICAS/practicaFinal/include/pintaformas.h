#ifndef __FORMAS__H
#define __FORMAS__H
#include "imagen.h"
#include <cmath>

typedef Pixel color;
/**@brief Pinta cuadrado en la imagen 
 * @param I: imagen de entrada
 * @param f: fila del centro del cuadrado
 * @param c: columna del centro del cuadrado
 * @param lado: lado del cuadrado
 * @param col: color con el que se rellena el circulo

 * */

void PintaCuadrado(Imagen &I,int f,int c,int lado,color col);

/**@brief Pinta cuadrado en la imagen 
 * @param I: imagen de entrada
 * @param f: fila del centro del cuadrado
 * @param c: columna del centro del cuadrado
 * @param lado1: lado en altura
 * @param lado2: lado en ancho
 * @param col: color con el que se rellena el circulo

 * */
void PintaRectangulo(Imagen &I,int f,int c,int lado1,int lado2,color col);

/**@brief Pinta un circulo en la imagen 
 * @param I: imagen de entrada
 * @param f: fila del centro del circulo
 * @param c: columna del centro del circulo
 * @param col: color con el que se rellena el circulo

 * */

void PintaCirculo(Imagen &I,int f,int c,int radio,color col);



/**@brief Pinta un circulo en la imagen 
 * @param I: imagen de entrada
 * @param f1: fila de inicio de la linea
 * @param c1: columna de inicio de la linea
 * @param f2: fila de fin de la linea
 * @param c2: columna fin de la linea
 * @param c: color con el que se rellena el circulo
 * @param w: ancho de la linea
 * */

bool PintaLinea(Imagen &I,int f1,int c1,int f2,int c2,color c,unsigned int w);



#endif