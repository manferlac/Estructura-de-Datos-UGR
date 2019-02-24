//ciudades.h

#ifndef _CIUDADES_H_
#define _CIUDADES_H_

#include <iostream>
#include "VectorDinamico.h"
#include "ciudad.h"

using namespace std;

class Ciudades{
    private:
        VectorDinamico<Ciudad> vectorCiudades;
        VectorDinamico<int> indice;
    public:

        Ciudad GetCiudad_Ciudad(int i); //Devuelve la ciudad que ocupa la posición i en la ordenación solamente por ciudad.

        int size() const;

        bool Esta(Ciudad c, int &pos) const;

        //bool Esta_en_Indice(Ciudad c, int &pos) const;

        void Insertar(Ciudad c);

        void Borrar(int x);

        const Ciudad& operator[](int i) const;
    
        friend ostream& operator<<(ostream &flujo, const Ciudades &ciudades);

        friend istream& operator>>(istream &flujo, Ciudades &ciudades);
};

#endif