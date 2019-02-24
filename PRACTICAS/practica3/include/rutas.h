/**
  * @file rutas.h
  * @brief Fichero cabecera del TDA RUTAS
  *
  */

#ifndef _RUTAS_H_
#define _RUTAS_H_

#include "ruta.h"
#include <string>
#include <map>

using namespace std;

class Rutas{
    private:
        map<string,Ruta> datos; /**< mapa de datos*/
    public:
        class const_iterator;
        class iterator{
            private:
                map<string,Ruta>::iterator it;
            public:
                iterator(){}
                bool operator==(const iterator &i) const{
                    return i.it==it;
                }
                bool operator!=(const iterator &i) const{
                    return i.it!=it;
                }
                Ruta & operator*(){
                    return it->second;
                }
                iterator & operator++(){
                    ++it;
                    return *this;
                }
                iterator & operator--(){
                    --it;
                    return *this;
                }

                friend class Rutas;
                friend class const_iterator;
        };//fin iterator

        class const_iterator{
            private:
                map<string,Ruta>::const_iterator it;
            public:
                const_iterator(){}
                const_iterator(const iterator &i):it(i.it){}
                bool operator==(const const_iterator &i)const{
                    return i.it == it;
                }
                bool operator!=(const const_iterator &i)const{
                    return i.it != it;
                }
                const Ruta & operator*() const{

                    return it->second;
                }
                const_iterator & operator++(){
                    ++it;
                    return *this;
                }
                const_iterator & operator--(){
                    --it;
                    return *this;
                }
                friend class Rutas;
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

        int size()const;

        Ruta getRuta(string codigo)const;

        void erase(Ruta r);

        void Insertar(string codigo, Ruta r);

        /**
        * @brief Sobrecarga del operador <<
        * @param os: Flujo de salida
        * @param Rutas @r: Rutas que se quieren escribir
        */
        friend ostream& operator<<(ostream &os, const Rutas &r);

        /**
        * @brief Sobrecarga del operador >>
        * @param is: Flujo de entrada
        * @param Rutas @r: Rutas que se quieren leer
        */
        friend istream& operator>>(istream &is, Rutas &r);
};

#endif
