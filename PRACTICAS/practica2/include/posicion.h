/**
  * @file posicion.h
  * @brief Fichero cabecera del TDA Posicion
  * 
  */
#include "VectorDinamico.h"
#ifndef _POSICION_H_
#define _POSICION_H_

using namespace std;

/**
  * @brief TDA Posicion
  * 
  * La clase @c Posicion...
  *
  * @author Manuel Fernández La-Chica
  * @author Emilio Ochando
  * @date Octubre 2018
  */

class Posicion{
    private:
        float longitud; /**< DIRECCIÓN: ESTE-OESTE */ 
        float latitud; /**< DIRECCIÓN: NORTE-SUR */
    
    public:

    /**
     * @brief Constructor por defecto de la clase. Crea la posicion vacia
     */
    Posicion();

    /**
     * @brief Constructor de la clase
     * @param longitud DIRECCIÓN: ESTE-OESTE
     * @param latitud DIRECCIÓN: NORTE-SUR
     * @return Crea la Posicion
     */
    Posicion(float longitud, float latitud);  
    
    /**
     * @brief Constructor de copias de la clase
     * @param p.longitud DIRECCIÓN: ESTE-OESTE
     * @param p.latitud DIRECCIÓN: NORTE-SUR
     */
    Posicion(const Posicion& p); 

    /**
     * @brief Longitud
     * @return Devuelve la longitud de la posicion
     */ 
    float getLongitud() const;

    /**
     * @brief Latitud
     * @return Devuelve la latitud de la posicion
     */ 
    float getLatitud() const;

    /**
    * @brief Funcion setLongitud
    *      @b DEFINICION:
    *      Asigna un nuevo valor a longitud
    * @param longitud: valor float con el que vamos a asignar longitud
    * 
    **/
    void setLongitud(const float longitud);

    /**
    * @brief Funcion setLatitud
    *      @b DEFINICION:
    *      Asigna un nuevo valor a latitud
    * @param latitud: valor float con el que vamos a asignar latitud
    * 
    **/
    void setLatitud(const float latitud);

    /**
    * @brief Sobrecarga del operador <<
    * @param flujo Flujo de salida
    * @param fecha @c Posicion que se quiere escribir
    */
    friend ostream& operator<<(ostream &os, const Posicion &pos);

    /**
    * @brief Sobrecarga del operador >>
    * @param flujo Flujo de entrada
    * @param fecha @c Posicion que se quiere leer
    */
    friend istream& operator>>(istream &is, Posicion &pos);

};



#endif