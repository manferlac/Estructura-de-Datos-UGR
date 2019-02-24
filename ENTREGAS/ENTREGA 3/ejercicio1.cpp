/**
 * Ejercicio 1 - Manuel Fernández La-Chica
 */

#include <list>
#include <iostream>
#include <string>

using namespace std;

void Invertir(const list<int> &lsource, list<int> &ldestino){
    ldestino.clear();
    list<int>::const_iterator it = lsource.begin();
    for(;it != lsource.end(); it++){
        ldestino.push_back(*it);
    }

    ldestino.reverse();
}

int main(){
    list<int> lsource;
    list<int> ldestino;

    cout << "lsource contiene: " << endl;

    for(int i=0; i<=10; i++){
        lsource.push_back(i);
        cout << i << " ";
    }

    cout << endl;

    Invertir(lsource, ldestino);

    cout << "ldestino contiene: " << endl;
    list<int>::iterator it = ldestino.begin();

    for(; it!= ldestino.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

