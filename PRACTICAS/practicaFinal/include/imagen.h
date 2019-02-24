/**
 * @file imagen.h
 */
#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

/** @brief TDA Imagen. Es una matriz de nxm filas, columnas de pixeles.
 * 
 * */
struct Pixel{
   unsigned char r,g,b;
};   

class Imagen{
  private:
    Pixel ** data;//< espacio para almacenar los pixeles de la imagen
    int nf,nc; //< numero de filas y columnas
    /** 
     * @brief Elimina la memoria asignada a la imagen
     */
    void Borrar();
    /**
     * @brief Copia una imagen en otra.
     */
    void Copiar(const Imagen &I);
  public:
    /**
     * @brief Constructor por defecto
     */
   Imagen();
    /**
     * @brief Constructor por parametros. Reserva espacio para una imagen con un determinado nuemro de filas 
     * y columnas. Todos los pixeles se inician a blanco.
     * @param f: numero de filas
     * @param c: numero de columnas
     * @note cada posicion de la imagen almacena un pixel.
     */
   Imagen(int f,int c);
   /**
     * @brief Constructor de copia
     * @param I: imagen a ser copiada
    */
   Imagen(const Imagen & I);
    /**
     * @brief Asignacion
     * @param I: imagen que se asigna
    */
   Imagen & operator=(const Imagen & I);
    /**
     * @brief Destructor
    */
   ~Imagen();
   
   //set y get
   /** @brief Permite acceder al pixel en la fila i columna j
    *  @param i: fila
    *  @param j: columna
    *  @return el pixel en la posicion i,j
    */
   Pixel & operator ()(int i,int j);
   
   const Pixel & operator ()(int i,int j)const;
   
   
   /**
    * @brief Escribe una imagen en un fichero
    * @param nombre: nombre de la imagen en disco
    */
   void EscribirImagen(const char * nombre);
   
   /**
    * @brief Lee una imagen de disco
    * @param nombre: nombre de la imagen en disco
    */
   void LeerImagen (const char *nombre);
   
   
   /**
    * @brief Devuelve el numero de filas de la imagen
    */
   
   int num_filas()const;
   
   /**
    * @brief Devuelve el numero de columnas de la imagen
    */
   
   int num_cols()const;

   /**
         * @brief Funcion isEmpty
         *      @b DEFINICION:
         *      Comprueba si la matriz tiene tamaño
         * @retval true si no hay datos de la imagen
         * @retval false si hay datos de la imagen
        **/
    bool isEmpty() const;
   
};   
   
#endif