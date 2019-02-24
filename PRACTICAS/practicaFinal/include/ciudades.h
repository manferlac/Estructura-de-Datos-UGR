/**
  * @file ciudades.h
  * @brief Fichero cabecera del TDA Ciudades
*/

#ifndef _CIUDADES_H_
#define _CIUDADES_H_

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "vector"
#include "ciudad.h"

using namespace std;

class Ciudades{
    private:
        vector<Ciudad> datos; /**< nombre de la ciudad*/
        vector<int> indice_ciudad; /**< nombre de la ciudad*/
    public:
        class const_iterator;
        class iterator{
            private:
                vector<Ciudad>::iterator it; /**< iterator */
            public:

                /**
                * @brief Constructor por defecto
                */
                iterator(){}

                /**
                * @brief Operador == iterator
                * @param iterator @i: Iterador para comprobar si son iguales
                * @return bool: Verdadero si son iguales, falso si son distintas
                */
                bool operator==(const iterator &i) const{
                    return i.it==it;
                }

                /**
                * @brief Operador != iterator
                * @param iterator @i: Iterador para comprobar si son distintos
                * @return bool: Verdadero si son distintos, falso si no son distintos
                */
                bool operator!=(const iterator &i) const{
                    return i.it!=it;
                }

                /**
                * @brief Operador *
                * @return Ciudad: Devuelve la Ciudad donde está posicionado el iterador
                */
                Ciudad & operator*(){
                    return *it;
                }

                /**
                * @brief Operador ++
                * @return iterator: Devuelve el iterador con una posición avanzada
                */
                iterator & operator++(){
                    ++it;
                    return *this;
                }

                /**
                * @brief Operador --
                * @return iterator: Devuelve el iterador con una posición anterior
                */
                iterator & operator--(){
                    --it;
                    return *this;
                }

                friend class Ciudades;
                friend class const_iterator;
        };//fin iterator

        class const_iterator{
            private:
                vector<Ciudad>::const_iterator it; /**< iterator constante */
            public:

                /**
                * @brief Constructor por defecto
                */
                const_iterator(){}
                const_iterator(const iterator &i):it(i.it){}

                /**
                * @brief Operador == iterator
                * @param const_iterator @i: Iterador para comprobar si son iguales
                * @return bool: Verdadero si son iguales, falso si son distintas
                */
                bool operator==(const const_iterator &i)const{
                    return i.it == it;
                }

                /**
                * @brief Operador != iterator
                * @param const_iterator @i: Iterador para comprobar si son distintos
                * @return bool: Verdadero si son distintos, falso si no son distintos
                */
                bool operator!=(const const_iterator &i)const{
                    return i.it != it;
                }

                /**
                * @brief Operador *
                * @return Ciudad: Devuelve la Ciudad donde está posicionado el const_iterador
                */
                const Ciudad & operator*() const{
                    return *it;
                }

                /**
                * @brief Operador ++
                * @return const_iterator: Devuelve el iterador con una posición avanzada
                */
                const_iterator & operator++(){
                    ++it;
                    return *this;
                }

                /**
                * @brief Operador --
                * @return const_iterator: Devuelve el iterador con una posición anterior
                */
                const_iterator & operator--(){
                    --it;
                    return *this;
                }
                friend class Ciudades;
        };

        iterator begin(){
            iterator i;
            i.it = datos.begin();
            return i;
        }
        iterator end(){
            iterator i;
            i.it = datos.end();
            return i;
        }
        const_iterator begin() const{
            const_iterator i;
            i.it = datos.begin();
            return i;
        }
        const_iterator end() const{
            const_iterator i;
            i.it = datos.end();
            return i;
        }

        /**
        * @brief Devuelve la ciudad que ocupa una posicion pasada por parámetro
        * @param i: Posicion a buscar
        * @return Ciudad: Ciudad de la posición i
        */
        Ciudad GetCiudad_Ciudad(int i);

        /**
        * @brief Devuelve el tamaño del vector datos
        * @return int: Tamaño del vector
        */
        int size() const;

        bool Esta(Ciudad c, int &pos) const;

        /**
        * @brief Devuelve un conjunto Ciudades con el nombre de la ciudad pasado por parámetro
        * @param name1: Nombre de la ciudad a buscar
        * @return Ciudades: Ciudades con el nombre pasado por parámetro
        */
        Ciudades GetCiudad_Ciudad_PorNombre(string name1);

        /**
        * @brief Devuelve todas las ciudades de un pais pasado por parámetro
        * @param name_pais: Nombre del pais
        * @return Ciudades: Ciudades del pais pasado por parámetro
        */
        Ciudades GetAllCiudadesPais(string name_pais);

        /**
        * @brief Devuelve la ciudad con la posicion de latitud y longitud
        * @param pos: objeto Posicion
        * @return Ciudad: Ciudad con la pos correspondiente
        */
        Ciudad getCiudadPosicion(Posicion pos);

        /**
        * @brief Borra una ciudad que se pasa por parámetro
        * @param c: Ciudad a borrar
        */
        void BorrarCiudad(Ciudad c);

        /**
        * @brief Inserta una ciudad que se pasa por parámetro
        * @param c: Ciudad a insertar
        */
        void Insertar(Ciudad c);

        /**
        * @brief Operador []
        * @param @i: posicion a devolver
        * @return Ciudad: Ciudad con la posicion i
        */
        const Ciudad& operator[](int i) const;

        /**
        * @brief Sobrecarga del operador <<
        * @param os: Flujo de salida
        * @param Ciudades @ciudades: Ciudades que se quieren escribir
        */
        friend ostream& operator<<(ostream &os, const Ciudades &ciudades);

        /**
        * @brief Sobrecarga del operador >>
        * @param is: Flujo de entrada
        * @param Ciudades @ciudades: Ciudades que se quieren leer
        */
        friend istream& operator>>(istream &is, Ciudades &ciudades);
};

#endif
