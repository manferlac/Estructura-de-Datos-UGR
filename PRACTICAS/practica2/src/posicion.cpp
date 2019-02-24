#include <iostream>
#include "posicion.h"


using namespace std;

Posicion::Posicion(){
    longitud = 0.0;
    latitud = 0.0;
}

Posicion::Posicion(float longitud, float latitud){
    this->longitud = longitud;
    this->latitud = latitud;
}

Posicion::Posicion(const Posicion& p){
    if(&p != this){

    this->longitud = p.longitud;
    this->latitud = p.latitud;
    }
}

float Posicion::getLongitud() const{
    return this->longitud;
}

float Posicion::getLatitud() const{
    return this->latitud;
}

void Posicion::setLongitud(const float longitud){
    this->longitud = longitud;
}

void Posicion::setLatitud(const float latitud){
    this->latitud = latitud;
}

ostream& operator<<(ostream &os, const Posicion &pos){
    return os;
}

istream& operator>>(istream &is, Posicion &pos){
    return is;
}