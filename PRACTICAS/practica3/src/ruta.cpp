#include <iostream>
#include "ruta.h"

using namespace std;

 Ruta::Ruta(){
     this->codigo = "";
 }

Ruta::Ruta(string c, list<Posicion> d){
    this->codigo = c;
    list<Posicion>::iterator at = datos.begin();
    for(list<Posicion>::iterator it = d.begin(); it != d.end(); ++it){
        *at = *it;
    }
}

Ruta::Ruta(const Ruta& copia){
     if(&copia != this){

     this->codigo = copia.codigo;
     this->datos = copia.datos;
     }
}

string Ruta::GetCode()const{
    return codigo;
}

void Ruta::Insertar(Posicion p){
    datos.push_back(p);
}

int Ruta::size() const{
    return datos.size();
}

void Ruta::setCodigo(const string cod){
    this->codigo = cod;
}

void Ruta::Borrar(){
    this->codigo = "";
    this->datos.clear();
}

// const Posicion& Ruta::operator[](int i) const{
//     list<Posicion>::const_iterator it = datos.begin();

//     return (*it);
// }



ostream& operator<<(ostream &os, const Ruta &ruta){
    //os << ruta.size();
     for(list<Posicion>::const_iterator it = ruta.datos.begin(); it != ruta.datos.end(); ++it){
         os << *it;
     }
    return os;
}

istream& operator>>(istream &is, Ruta &ruta){
    string codigo;
    getline(is,codigo,';');
    ruta.setCodigo(codigo);
    Posicion p;
    ruta.datos.clear();
    while(is.peek() != '\n' && is>>p){
        ruta.Insertar(p);
    }

    string resto;
    getline(is,resto);
    
    return is;
}
