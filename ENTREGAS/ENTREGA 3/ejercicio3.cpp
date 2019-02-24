/**
 * Ejercicio 3 - Manuel Fernández La-Chica
 */

#include <iostream>
#include <list>

using namespace std;

void eliminaPares(list<int> &lista){
    list<int>::iterator it = lista.begin();

    for( ; it!=lista.end(); it++){
        if((*it)%2==0){
            lista.erase(it);
        }
    }
}

int main(){
    list<int> lista;
    cout << "Lista con pares: " << endl;

    for(int i=1; i<=100; i++){
        lista.push_back(i);
        cout << i << " ";
    }
    cout << endl;
    eliminaPares(lista);
    
    list<int>::iterator it = lista.begin();

    cout << endl << "Lista con SOLO impares:" << endl;

    for( ; it!=lista.end(); it++){
        cout << (*it) << " ";
    }
}