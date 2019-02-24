//ciudades.cpp

#include "ciudades.h"
#include <iostream>

using namespace std;

int Ciudades::size() const{
    return vectorCiudades.size();
}

bool Ciudades::Esta(const Ciudad c, int &pos) const{
    bool esta = false;
    int tamano = vectorCiudades.size();
    for(int i = 0; i<tamano;i++){
        if(vectorCiudades[i] == c){
            esta = true;
            pos = i;
        }
    }

    return esta;
}

void Ciudades::Insertar(Ciudad c){
    //int posicion;
    int pos;
    if(Esta(c,pos) == false)
        vectorCiudades.Insertar(c,pos);
        //posicion = x;
    
    //int pos = Esta(x);
    //if(vectorCiudades[pos] == x)
        //return;
    //else
        
}

void Ciudades::Borrar(int x){
    //int pos;
    //bool esta = Esta();
    //int pos = Esta(x);
    //if(vectorCiudades[pos] == x)
        vectorCiudades.Borrar(x);
    //else
        //return;
}

Ciudad Ciudades::GetCiudad_Ciudad(int i){
    return vectorCiudades[i];
}

const Ciudad& Ciudades::operator[](int i) const{
    return vectorCiudades[i];
}

ostream& operator<<(ostream &flujo, const Ciudades &ciudades){
    Ciudad c;
    for(int i=0;i<ciudades.size();i++){
        flujo << " Ciudad en posicion "<<i;
    }
    return flujo;
}

istream& operator>>(istream &flujo, Ciudades &ciudades){
    Ciudad c;
    while(flujo>>c){
        ciudades.Insertar(c);
    }
    return flujo;
}



