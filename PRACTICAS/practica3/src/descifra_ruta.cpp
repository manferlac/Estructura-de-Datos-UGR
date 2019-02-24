#include "rutas.h"
#include "ciudades.h"
#include <fstream>
#include <tgmath.h>
  
string obtenerDireccion(Ciudad c1, Ciudad c2){
  string direccion = "error";
  float lat1,lon1;
  lat1 = c2.getPosicion().GetLat()-c1.getPosicion().GetLat();
  lon1 = c2.getPosicion().GetLon()-c1.getPosicion().GetLon();
  float angulo = atan2(lat1,lon1);

  if(angulo>0){
    angulo=angulo*360/(2*M_PI);
  }else{
    angulo=(angulo+2*M_PI)*360/(2*M_PI);
  }

  if(angulo<115 && angulo>70){
    direccion = "N";
  }else if(angulo<70 && angulo>25){
    direccion = "NE";
  }else if(angulo<25 && angulo<338){
    direccion = "E";
  }else if(angulo<338 && angulo>295){
    direccion = "SE";
  }else if(angulo<295 && angulo>250){
    direccion = "S";
  }else if(angulo<250 && angulo>205){
    direccion = "SW";
  }else if(angulo<205 && angulo>160){
    direccion = "W";
  }else if(angulo<160 && angulo>115){
    direccion = "NW";
  }

  return direccion;
}

void ImprimirDireccion(string dir){
    cout << "________Direccion " << dir << endl; 
} 

void Mensaje(){
  cout << "Los parametros son:" << endl;
  cout << "1.- Fichero con la informacion de las ciudades" << endl;
  cout << "2.- Fichero con la informacion de las rutas" << endl;
  cout << "3.- Codigo de la ruta a descifrar" << endl;
  return;  
}  


int main(int argc, char *argv[]){
  
  if (argc!=4){
    Mensaje();
    return 0;
  }
  
  ifstream f(argv[1]);
  if (!f){
     cerr << " No puedo abrir el fichero " << argv[1] << endl;
     return 0;
  }

  ifstream frutas(argv[2]);
  if (!frutas){
     cerr << " No puedo abrir el fichero " << argv[2] << endl;
     return 0;
  }
  
  //Guardamos las ciudades
  Ciudades misciudades;
  f >> misciudades;
  
  //Guardamos las rutas
  Rutas misrutas;
  frutas >> misrutas;

  //Guardamos el codigo de la Ruta a descifrar
  string codigoRuta = argv[3];

  Ciudad ciu1, ciu2;
  string direccion;
  Ruta r = misrutas.getRuta(codigoRuta);
  
  Ciudades ee;
  Ruta::iterator it = r.begin();
  while(it != r.end()){
    ciu1 = misciudades.getCiudadPosicion(*it);
    ee.Insertar(ciu1);
    ++it;
  }

  for(int i = 0; i< ee.size()-1; i++){
    cout << ee[i] << endl;
    direccion = obtenerDireccion(ee[i], ee[i+1]);
    if(i<ee.size()-1){
      ImprimirDireccion(direccion);
    }
  }
}  