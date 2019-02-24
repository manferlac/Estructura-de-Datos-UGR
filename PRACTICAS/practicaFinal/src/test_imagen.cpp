#include "imagen.h"
#include <fstream>
#include "pintaformas.h"

/**
 * @brief Fichero de test del tipo Imagen
 * Usa Pintaformas para dibujar formas básicas en una imagen
 */

int main(int argc, char * argv[]){
  if (argc!=2){
      cout<<"Los parametros son: ";
     cout<<"1.-Dime el nombre del fichero con la imagen"<<endl;
  }

  Imagen I;

  //LEEMOS LA IMAGEN DE DISCO
  I.LeerImagen(argv[1]);

  //PINTAMOS EL RECUADRO ROJO
  color c={255,0,0}; //rojo
  PintaCuadrado(I,128,128,128,c);

  //LINEA HORIZONTAL
  color azul={0,0,255};
  PintaLinea(I,256,0,256,1023,azul,2);

  //LINEA VERTICAL
  color amarillo={255,255,0};
  PintaLinea(I,0,512,511,512,amarillo,2);

  //GUARDAMOS EN DISCO ESTA IMAGEN
  I.EscribirImagen("prueba.ppm");


}
