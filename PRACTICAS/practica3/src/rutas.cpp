#include <iostream>
#include "rutas.h"

int Rutas::size()const{
    return datos.size();
}

void Rutas::Insertar(string codigo, Ruta r){
    pair<string,Ruta> route(codigo,r);
    datos.insert(route);
}

Ruta Rutas::getRuta(string codigo)const{
    map<string,Ruta>::const_iterator it;
    it = datos.find(codigo);
    return it->second;
}

void Rutas::erase(Ruta r){
    map<string,Ruta>::const_iterator it;
    it = datos.find(r.GetCode());
    r.Borrar();
    datos.erase(it);
}

ostream& operator<<(ostream &os, const Rutas &r){
    os << "<Key,Ruta>" << endl;

    map<string,Ruta>::const_iterator pos;
    for (pos = r.datos.begin(); pos != r.datos.end(); ++pos) {
        cout << "<" << pos->first << "," << pos->second << ">";
    }
    
    return os;
}

istream& operator>>(istream &is, Rutas &r){
    Ruta rut;

    while(is>>rut){
        r.Insertar(rut.GetCode(),rut);
    }
    return is;
}

