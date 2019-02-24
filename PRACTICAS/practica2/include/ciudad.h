/**
  * @file ciudad.h
  * @brief Fichero
  *
  */

#ifndef _CIUDAD_H_
#define _CIUDAD_H_

#include <iostream>
#include "posicion.h"

using namespace std;

class Ciudad{
    private:
        string nombre;
        string pais;
        Posicion posicion;
        int poblacion;
    public:

    /**
     * @brief Constructor por defecto de la clase. Crea la ciudad vacía
     */
    Ciudad();

    /**
     * @brief Constructor de la clase
     * @param nombre nombre de la ciudad a construir
     * @param pais nombre del pais donde se encuentra la ciudad a construir
     * @param posicion indica la posicion donde se encuentra la ciudad
     * @param poblacion numero de poblacion de la ciudad
     * @return Crea la ciudad
     */
    Ciudad(string nombre, string pais, Posicion posicion, int poblacion);  
    
    /**
     * @brief Constructor de copias de la clase
     * @param c.nombre nombre del pais donde se encuentra la ciudad a construir
     * @param c.pais nombre del pais donde se encuentra la ciudad a construir
     * @param c.posicion indica la posicion donde se encuentra la ciudad
     * @param c.poblacion numero de poblacion de la ciudad
     */
    Ciudad(const Ciudad& c); 

    /**
     * @brief Nombre
     * @return Devuelve el nombre de la ciudad
     */ 
    string getNombre() const;

    /**
     * @brief Pais
     * @return Devuelve el pais donde se encuentra la ciudad
     */ 
    string getPais() const;

    /**
     * @brief Posicion
     * @return Devuelve un objeto de la clase Posicion donde se encuentra la ciudad
     */ 
    Posicion getPosicion() const;

    /**
     * @brief Poblacion
     * @return Devuelve la poblacion total de la ciudad
     */ 
    int getPoblacion() const;

    bool operator ==(const Ciudad &otra) const;
    /**
    * @brief Sobrecarga del operador <<
    * @param flujo Flujo de salida
    * @param fecha @c Ciudad que se quiere escribir
    */
    friend ostream& operator<<(ostream &os, const Ciudad &ciudad);

    /**
    * @brief Sobrecarga del operador >>
    * @param flujo Flujo de entrada
    * @param fecha @c Ciudad que se quiere leer
    */
    friend istream& operator>>(istream &is, Ciudad &ciudad);
};



#endif