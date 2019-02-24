/**
 * Ejercicio 4 - Manuel Fernández La-Chica
 */

#include <iostream>
#include <vector>

using namespace std;

enum key_pila : char {Pila1, Pila2};

class DoblePila{
  private:
    static const int TAM = 30;
    vector<char> pilaDoble(TAM);
    vector<char>::iterator p1 = pilaDoble.begin();
    vector<char>::iterator p2 = pilaDoble.end();
    int tamP1 = 0, tamP2 = 0;

  public:
    char Tope(key_pila kp){
      if(kp == Pila1){
        return (*p1);
      }else{
        return (*p2);
      }
    }

    void Poner(key_pila kp, char c){
      if(pilaDoble.size() == TAM){
        int newTam = pilaDoble.size()*2;
        pilaDoble.resize(newTam);
      }else{
        if(kp == Pila1){
          pilaDoble.insert(p1, c);
          p1++;
          tamP1++;
        }else{
          pilaDoble.insert(p2,c);
          p2--;
          tamP2++;
        }
      }
    }

    void Quitar(key_pila kp){
      if(kp == Pila1){
        pilaDoble.erase(p1);
      }else{
        pilaDoble.erase(p2);
      }
    }

    bool vacia(key_pila kp){
      bool estaVacia = false;
      if(kp==Pila1){
        if (tamP1!=0) {
          estaVacia = true;
        }
      }else{
        if (tamP2!=0) {
          estaVacia = true;
        }
      }
      return estaVacia;
    }

    void MostrarPilaDoble(){
      vector<char>::iterator it = pilaDoble.begin();
      for ( ; it!=pilaDoble.end(); ++it) {
        cout << (*it) << " ";
      }
    }
};
