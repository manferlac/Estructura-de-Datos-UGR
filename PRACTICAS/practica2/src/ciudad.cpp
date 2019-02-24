#include <iostream>
#include "ciudad.h"

using namespace std;

Ciudad::Ciudad(){
    this->nombre = "";
    this->pais = "";
    this->poblacion = 0;
}

Ciudad::Ciudad(string nombre, string pais, Posicion posicion, int poblacion){
    this->nombre = nombre;
    this->pais = pais;
    this->posicion = posicion;
    this->poblacion = poblacion;
}

Ciudad::Ciudad(const Ciudad& c){
    if(&c != this){

    this->nombre = c.nombre;
    this->pais = c.pais;
    this->posicion = c.posicion;
    this->poblacion = c.poblacion;
    }
}

string Ciudad::getNombre() const{
    return nombre;
}

string Ciudad::getPais() const{
    return pais;
}

Posicion Ciudad::getPosicion() const{
    return posicion;
}

int Ciudad::getPoblacion() const{
    return poblacion;
}

bool Ciudad::operator ==(const Ciudad &otra) const{
    bool igual = false;
    if(this->nombre == otra.nombre && this->pais == otra.pais){
        igual = true;
    }
    return igual;
}

ostream& operator<<(ostream &os, const Ciudad &ciudad){
    return os;
}

istream& operator>>(istream &is, Ciudad &ciudad){

    return is;
}
