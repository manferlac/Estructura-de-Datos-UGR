
#include "posicion.h"


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

float Posicion::GetLon() const{
    return this->longitud;
}

float Posicion::GetLat() const{
    return this->latitud;
}

void Posicion::setLongitud(const float longitud){
    this->longitud = longitud;
}

void Posicion::setLatitud(const float latitud){
    this->latitud = latitud;
}

bool Posicion::operator==(const Posicion &otra) const{
    bool igual = false;
    if(this->latitud == otra.latitud && this->longitud == otra.longitud){
        igual = true;
    }

    return igual;
}

//Salida de datos
ostream& operator<<(ostream &os, const Posicion &pos){
    os << pos.latitud << ";" << pos.longitud << ";";
    return os;
}

//Entrada de datos
istream& operator>>(istream &is, Posicion &pos){
    is >> pos.latitud;
    is.ignore();
    is >> pos.longitud;
    is.ignore();

    return is;
}