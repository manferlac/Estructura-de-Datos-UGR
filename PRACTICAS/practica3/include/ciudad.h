/**
  * @file ciudad.h
  * @brief Fichero cabecera del TDA Ciudad
*/ 

#ifndef _CIUDAD_H_
#define _CIUDAD_H_

#include <iostream>
#include "posicion.h"

using namespace std;

class Ciudad{
    private:
        string nombre; /**< nombre de la ciudad*/
        string pais; /**< nombre del pais al que pertenece la ciudad*/
        Posicion posicion; /**< objeto de la clase Posicion donde se encuentra la ciudad*/
        int poblacion; /**< cantidad de población de la ciudad*/
    public:

    /**
    * @brief Constructor por defecto.
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
    * @brief Constructor de copia. 
    * @param c: Ciudad de entrada a ser copiada
    */
    Ciudad(const Ciudad& c); 

    /**
     * @brief getNombre, devuelve el nombre
     * @return Devuelve el nombre de la ciudad
     */ 
    string getNombre() const;

    /**
     * @brief getPais, devuelve el pais
     * @return Devuelve el pais donde se encuentra la ciudad
     */ 
    string getPais() const;

    /**
     * @brief getPosicion, devuelve la posicion
     * @return Devuelve un objeto de la clase Posicion donde se encuentra la ciudad
     */ 
    Posicion getPosicion() const;

    /**
     * @brief getPoblacion, devuelve la poblacion
     * @return Devuelve la poblacion total de la ciudad
     */ 
    int GetPoblacion() const;

    /**
    * @brief Sobrecarga del operador ==
    * @param otra: Ciudad para comprobar la igualdad
    * @return bool: Verdadero si son iguales, false si son distintas
    */
    bool operator ==(const Ciudad &otra) const;
    
    /**
    * @brief Sobrecarga del operador <<
    * @param os: Flujo de salida
    * @param Ciudad @ciudad: Ciudad que se quiere escribir
    */
    friend ostream& operator<<(ostream &os, const Ciudad &ciudad);

    /**
    * @brief Sobrecarga del operador >>
    * @param is: Flujo de entrada
    * @param Ciudad @ciudad: Ciudad que se quiere leer
    */
    friend istream& operator>>(istream &is, Ciudad &ciudad);
};



#endif