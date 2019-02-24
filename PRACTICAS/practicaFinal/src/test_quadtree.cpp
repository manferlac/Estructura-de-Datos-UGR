#include "Quadtree.h"
#include <fstream>
#include <iostream>
using namespace std;

void PreordenRec(const Quadtree &Q){
   Quadtree::const_iterator it;
   for (it=Q.begin(); it!=Q.end();++it)
      cout<<(*it).first<<(*it).second;
   cout<<endl;
}

void Mensaje(){
  printf("Los parametro son:");
  printf("1.-El nombre del fichero con el quadtre");
  return;
}

int main(int argc, char * argv[]){

    if (argc!=2){
       Mensaje();
       return 0;
    }
    ifstream f (argv[1]);
    if (!f){
       cerr<<"No puedo abrir el fichero "<<argv[1]<<endl;
       return 0;
    }
    //************************************************************************
    //SECTION 1: Comprobacion de la declaracion de un Quadtree, lectura y escritura
    pair<bool,char> p;
    Quadtree Q(p);
    f>>Q;
    cout<<"\n"<<Q<<endl;

    Quadtree otro(pair<bool,char>(true,'0'));


    cout<<"El quadtree otro tiene " <<otro<<endl;
    cout << "\nPulse una tecla para continuar...." << endl;
    cin.get();
    //************************************************************************
    //SECTION 2: Operaciones de insercion y borrado.

     pair<bool,char> value[4];
    //
     value[0]=pair<bool,char>(true,'0');
     value[1].first =false; value[1].second='1';
     value[2].first =true; value[2].second='0';
     value[3].first =false; value[3].second='1';
    //
     otro.InsertarHijos(otro.getRaiz(),value);
    //
     cout<<"Tras la Insercion :"<<otro<<endl;
    //
    //
     Quadtree aux_qud(otro);
     cout<<"El numero de nodos que tiene el quadtree es :" <<aux_qud.size()<<endl;
    //
     cout<<"Borrando ...."<<endl;
     aux_qud.BorrarHijos(aux_qud.getRaiz());
     cout<<"Tras borrar el numero de nodos es "<<aux_qud.size()<<endl;;
     cout<<"Pulse una tecla para continuar...."<<endl;
     cin.get();

    //************************************************************************
    //SECTION 3: Comparacion de dos quadtree
     aux_qud=otro;
    //
     if (otro==Q)
        cout<<"Los quadtrees son iguales "<<endl;
     else
        cout<<"Los quadtrees son diferentes"<<endl;
    //
    //
     if (otro!=aux_qud)
        cout<<"Los quadtrees son diferentes"<<endl;
     else
        cout<<"Los quadtrees son iguales "<<endl;

   //************************************************************************
   //SECTION 4: Comprobación de lo iteradores

     Quadtree::iterator it;
     for (it=otro.begin(); it!=otro.end();++it)
       cout<<(*it).first<<(*it).second;
     cout<<endl;
    //
    // //iterador constante
     PreordenRec(Q);


}
