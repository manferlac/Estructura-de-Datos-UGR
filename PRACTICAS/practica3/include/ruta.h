/**
  * @file ruta.h
  * @brief Fichero cabecera del TDA RUTA
  *
  */

#ifndef _RUTA_H_
#define _RUTA_H_

#include "posicion.h"
#include <string>
#include <list>
#include <iostream>


using namespace std;

class Ruta{
    private:
        list<Posicion> datos; /**< lista de datos de posiciones de la ruta*/
        string codigo; /**< codigo de la ruta*/

    public:
        class const_iterator;
        class iterator{
            private:
                list<Posicion>::iterator it;
            public:
                iterator(){}
                bool operator==(const iterator &i) const{
                    return i.it==it;
                }
                bool operator!=(const iterator &i) const{
                    return i.it!=it;
                }
                Posicion & operator*(){
                    return *it;
                }
                iterator & operator++(){
                    ++it;
                    return *this;
                }
                iterator & operator--(){
                    --it;
                    return *this;
                }

                friend class Ruta;
                friend class const_iterator;
        };//fin iterator

        class const_iterator{
            private:
                list<Posicion>::const_iterator it;
            public:
                const_iterator(){}
                const_iterator(const iterator &i):it(i.it){}
                bool operator==(const const_iterator &i)const{
                    return i.it == it;
                }
                bool operator!=(const const_iterator &i)const{
                    return i.it != it;
                }
                const Posicion & operator*() const{
                    return *it;
                }
                const_iterator & operator++(){
                    ++it;
                    return *this;
                }
                const_iterator & operator--(){
                    --it;
                    return *this;
                }
                friend class Ruta;
        };//fin const_iterator

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
        * @brief Constructor por defecto.
        */
        Ruta();

        /**
         * @brief Constructor de la clase
         * @param c nombre del codigo de la ruta
         * @param d lista de posiciones
         */
        Ruta(string c, list<Posicion> d);

        /**
        * @brief Constructor de copia.
        * @param copia: Ruta a ser copiada
        */
        Ruta(const Ruta& copia);

        /**
         * @brief GetCode, devuelve el codigo
         * @return Devuelve el codigo de la ruta
         */
        string GetCode()const;

        /**
        * @brief Inserta posiciones en la lista
        * @param p: Posicion a insertar en la lista
        */
        void Insertar(Posicion p);

        /**
        * @brief Devuelve el tamaño de la lista datos
        * @return int: Tamaño de la lista
        */
        int size()const;

        /**
        * @brief Operador []
        * @param @i: posicion a devolver
        * @return Posicion: Posicion con la posicion i
        */
        const Posicion& operator[](int i) const;

        /**
        * @brief set de codigo
        * @param @cod: Codigo que se introduce
        */
        void setCodigo(const string cod);

        /**
        * @brief Borra una ruta
        */
        void Borrar();

        /**
        * @brief Sobrecarga del operador <<
        * @param os: Flujo de salida
        * @param Ruta @ruta: Ruta que se quieren escribir
        */
        friend ostream& operator<<(ostream &os, const Ruta &ruta);

        /**
        * @brief Sobrecarga del operador >>
        * @param is: Flujo de entrada
        * @param Ruta @ruta: Ruta que se quieren leer
        */
        friend istream& operator>>(istream &is, Ruta &ruta);
};

#endif
