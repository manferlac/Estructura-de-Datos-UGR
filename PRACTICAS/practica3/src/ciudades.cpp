//ciudades.cpp

#include "ciudades.h"
#include <iostream>

using namespace std;

int Ciudades::size() const{
    return datos.size();
}

const Ciudad& Ciudades::operator[](int i) const{
    return this->datos[i];
}

bool Ciudades::Esta(const Ciudad c, int &pos) const{
    bool esta = false;
    return esta;
}

void Ciudades::Insertar(Ciudad c){
    datos.push_back(c);

}

Ciudad Ciudades::GetCiudad_Ciudad(int i){
    return this->datos[i];
}

Ciudades Ciudades::GetCiudad_Ciudad_PorNombre(string name1){
    Ciudades ciu;

    for(int i = 0; i < datos.size(); i++){
        if(datos[i].getNombre() == name1){
            ciu.Insertar(datos[i]);
        }
    }

    return ciu;

}

Ciudad Ciudades::getCiudadPosicion(Posicion pos){
    Ciudad c;
    for(int i = 0; i<datos.size();i++){
        if(datos[i].getPosicion() == pos){
            c = datos[i];
        }
    }

    return c;
}

Ciudades Ciudades::GetAllCiudadesPais(string name_pais){
    Ciudades ciu;

    for(int i = 0; i < datos.size(); i++){
        if(datos[i].getPais() == name_pais){
            ciu.Insertar(datos[i]);
        }
    }

    return ciu;
}

void Ciudades::BorrarCiudad(Ciudad c){
    vector<Ciudad>::iterator it = datos.begin();

    for(int i = 0; i < datos.size(); i++){
        if((*it).getPais() == c.getPais()){
            datos.erase(it);
        }
        it++;
    }
}

ostream& operator<<(ostream &os, const Ciudades &ciudades){

    for(int i=0;i<ciudades.size();i++){
        os << ciudades.datos[i] << endl;
    }
    return os;
}

istream& operator>>(istream &is, Ciudades &ciudades){
    Ciudad c;
    string linea;
    getline(is,linea);

    while(is>>c){
       ciudades.Insertar(c);

    }
    return is;
}
