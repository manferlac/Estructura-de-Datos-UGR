#include <iostream>
#include "Quadtree.h"

/* METODOS PRIVADOS */
void Quadtree::LeerQuadtree(istream & is,Nodo &n){

    char c, s;
    pair<bool,char> et;
        if(is.get(c)){
            switch(c){
                case '0':
                    is.get(s);
                    et.first = false;
                    et.second = s;
                    n->etiqueta = et;
                break;
                case '1':
                    et.first = true;
                    et.second = '0';

                    n->etiqueta = et;
                    pair<bool,char> vacio[4];
                    InsertarHijos(n, vacio);
                    
                    Nodo aux = n->izqda;
                    for(int i=3; i>=0; i--){
                        LeerQuadtree(is,aux);
                        aux=aux->drcha;
                    }
                break;
            }
        }
}

void Quadtree::EscribirQuadtree(ostream & out,Quadtree::Nodo n)const{
        
    if(n!=0){
        if(n->izqda!=0){
            out.put('1');
            Nodo aux = n->izqda;
            for(int i=0; i<4; i++){
                EscribirQuadtree(out, aux);
                aux = aux->drcha;
            }
        }else{
            out.put('0');
            out.put(n->etiqueta.second);
        }
    }
}

/* ---------------- */

/* METODOS PUBLICOS */

Quadtree::Quadtree(const pair<bool,char> &p){
    tree.AsignaRaiz(p);
}

void Quadtree::InsertarHijos(Nodo n, const pair<bool,char> *datos){
    for(int i =3; i>=0; i--){
        ArbolGeneral<pair<bool,char>> rama (datos[i]);
        tree.insertar_hijomasizquierda(n, rama);
    }
}

void Quadtree::BorrarHijos(Nodo n){
    ArbolGeneral<pair<bool,char>> eliminar;
    tree.podar_hijomasizquierda(n, eliminar);
}

Quadtree::Nodo & Quadtree::getRaiz(){
    return tree.raiz();
}

const Quadtree::Nodo & Quadtree::getRaiz()const{
    return tree.raiz();
}

Quadtree::Nodo Quadtree::getPadre(Nodo n)const{
    Nodo padre = tree.padre(n);
    return padre;
}

Quadtree::Nodo Quadtree::getHijo(Nodo n, int i)const{
    Nodo hijo = tree.hijomasizquierda(n);
    for(int j=0; j<i; j++){
        hijo = tree.hermanoderecha(hijo);
    }

    return hijo;
}

pair<bool,char> & Quadtree::getInfo(Nodo n){
    return tree.etiqueta(n);
}

void Quadtree::setInfo(Nodo n, pair<bool,char> p){
    tree.etiqueta(n) = p;
}

void Quadtree::clear(){
    tree.clear();
}

unsigned int Quadtree::size()const{
    return tree.size();
}

bool Quadtree::empty()const{
    return tree.empty();
}

bool Quadtree::operator==(const Quadtree & Q)const{
    return tree == Q.tree;
}

bool Quadtree::operator!=(const Quadtree & Q)const{
    return tree != Q.tree;
}

istream& operator>>(istream& in, Quadtree & Q){
    Q.LeerQuadtree(in, Q.getRaiz());
    return in;
}

ostream& operator<< (ostream& out, const Quadtree & Q){
    Q.EscribirQuadtree(out, Q.getRaiz());
    return out;
}