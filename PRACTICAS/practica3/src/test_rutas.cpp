#include "rutas.h"
#include <fstream>

void ImprimeRuta(const Ruta &R){
   Ruta::const_iterator it;
   cout << R.GetCode() << ";";
   
   for (it=R.begin();it!=R.end();++it)
      cout << *it << ";";
}    

void ImprimirRutas_Inverso(const Rutas &R){
    Rutas::const_iterator it=R.end(); --it;
    while (it!=R.begin()){
       ImprimeRuta(*it);
       cout << endl;
       --it;
    }
    ImprimeRuta(*it);
    cout << endl;
   
}   

void Mensaje(){
  cout << "Los parametros son:" << endl;
  cout << "1.- Fichero con la informacion de las rutas" << endl;
  return;  
}  


int main(int argc, char *argv[]){
  
  if (argc!=2){
    Mensaje();
    return 0;
  }
  
  ifstream frutas(argv[1]);
  if (!frutas){
     cerr << " No puedo abrir el fichero "<<argv[1]<<endl;
     return 0;
  }
  // _______________________________________________________________
  
  
  //Seccion 1: Comprobar declaracion, lectura y diferentes formas
  // de impresion de las rutas. A través de la lectura (operator >>) se debe comprobar
  // que funciona bien el proceso de Insertar 
  Rutas misrutas;
  
  frutas >> misrutas; 
  cout << "Numero de rutas " << misrutas.size();
  cin.get();
  
  cout << "Rutas leidas ..." << endl;

  cout << misrutas;
  cout << "Pulsa una tecla para continuar...."<<endl;
  cin.get();  

  
  
  //_______________________________________________________________
  
  //Sección 2: Consulta de una ruta
  
  
   Ruta r;
  
   r= misrutas.getRuta("R7");
  
   //imprimos la ruta 
   cout << "Ruta con codigo R7..." << endl;
   cout << r << endl;
  

  //_______________________________________________________________
  
  //Sección 3: Borrar una ruta
  
   misrutas.erase(r); //borramos la ruta consultada anteriormente
  
   //imprimos las rutas restantes
   cout << "Despues de borrar las rutas son..." << endl;
   cout << misrutas << endl;
   cout << "Pulsa una tecla para continuar..." << endl;
   cin.get();


  //_______________________________________________________________
  
  //Sección 4: Iteradores


   cout << "Usamos iteradores para ver las rutas...." << endl;
   cout << "Sentido Normal ..." << endl;
   Rutas::iterator it;
   for (it=misrutas.begin(); it!=misrutas.end();++it)
      cout << *it << endl;
  
   cout<<endl<<"Y el sentido inverso (pulsa una tecla..."<<endl;
   cin.get();
   ImprimirRutas_Inverso(misrutas);

}