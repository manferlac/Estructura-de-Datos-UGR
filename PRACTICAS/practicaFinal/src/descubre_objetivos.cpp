#include "Quadtree.h"
#include "ciudades.h"
#include "imagen.h"
#include "pintaformas.h"
#include <fstream>
#include <iostream>
using namespace std;

void Mensaje(){
  printf("Los parametro son:");
  printf("0.-El ejecutable programa");
  printf("1.-El archivo con los datos de las ciudades");
  printf("2.-El archivo con el codigo objetivos");
  printf("3.-La imagen del mapa");
  printf("4.-Nombre de la imagen objetivo de salida");
  return;
}
// void dibujar(Quadtree &Q, Imagen &I, int xini,int yini, int xfin, int yfin, color c, unsigned int g)
// {
//   if(Q.getRaiz()->etiqueta.first)
//   {
//     //Pinto horizontal de este cuadrante
//     PintaLinea(I,xfin/2,yini,xfin/2,yfin,c,g);
//     //vertical
//     PintaLinea(I,xini,yfin/2,xfin,yfin/2,c,g);
//     for(int i=0;i<4;i++)
//     {
//       switch(i)
//       {
//         case 0:
//             //IZQ ARRIBA
//           dibujar(Q,I,xini,yini,xfin/2,yfin/2,c,g);break;
//         case 1:
//         //DRCH ARRIBA
//          dibujar(Q,I,xfin/2,yini,xfin,yfin/2,c,g);break;
//         case 2:
//           //IZQ ABAJO
//           dibujar(Q,I,xini,yfin,xfin/2,yfin,c,g);break;
//         case 3:
//           //DRCH ABAJO
//           dibujar(Q,I,xfin/2,yfin/2,xfin,yfin,c,g);
//       }
//     }
//   }
// }

int main(int argc, char * argv[]){

    if (argc!=5){
       Mensaje();
       return 0;
    }
    ifstream f1 (argv[1]); //Archivo ciudades
    if (!f1){
       cerr<<"No puedo abrir el fichero "<<argv[1]<<endl;
       return 0;
    }
   
   ifstream f2 (argv[2]); //Archivo codigo objetivos
    if (!f2){
       cerr<<"No puedo abrir el fichero "<<argv[1]<<endl;
       return 0;
    }

   Ciudades misciudades;
   f1>>misciudades;

   pair<bool,char> p;
   Quadtree Q(p);
   f2>>Q;

   Imagen I;
   I.LeerImagen(argv[3]);
    cout << "Numero de filas imagen: " << I.num_filas() << endl;
    cout << "Numero de columnas imagen: " << I.num_cols() << endl;
 
    /*
    * @param f1: fila de inicio de la linea
    * @param c1: columna de inicio de la linea
    * @param f2: fila de fin de la linea
    * @param c2: columna fin de la linea
    * */
   
  

  //GUARDAMOS EN DISCO ESTA IMAGEN
  I.EscribirImagen(argv[4]);
  
  
  //cout << Q << endl;
  //cout << misciudades << endl;

}