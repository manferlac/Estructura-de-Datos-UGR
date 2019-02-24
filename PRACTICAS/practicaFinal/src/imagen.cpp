#include "imagen.h"

void Imagen::EscribirImagen(const char * nombre){
      unsigned char * aux = new unsigned char [nf*nc*3];
    
      
      int total = nf*nc*3;
      for (int i=0;i<total;i+=3){
	    int posi = i /(nc*3);
	   int posj = (i%(nc*3))/3;
	    aux[i]=data[posi][posj].r;
	    aux[i+1]=data[posi][posj].g;
	    aux[i+2]=data[posi][posj].b;

	     
      }    
	
      if (!EscribirImagenPPM (nombre, aux,nf,nc)){
	  cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
      }	  
      delete[]aux;
     
  
}  
/*********************************/
void Imagen::LeerImagen(const char * nombre){
      int f,c;
      unsigned char * aux ;
      
      LeerTipoImagen(nombre, f, c);
       aux = new unsigned char [f*c*3];
       LeerImagenPPM (nombre, f,c,aux);
       Imagen I(f,c);
       int total = f*c*3;
      for (int i=0;i<total;i+=3){
	   int posi = i /(c*3);
	   int posj = (i%(c*3))/3;
	   I.data[posi][posj].r=aux[i];
	   I.data[posi][posj].g=aux[i+1];
	   I.data[posi][posj].b=aux[i+2];
	     
      }    
	  
      *this = I;   
      
      
}	
/*********************************/

void Imagen::Borrar(){
      if(!this->isEmpty()){
            for(int i=0; i<this->num_filas(); i++){
                  delete [] this->data[i];
            }
            delete [] this->data;

            this->nf = 0;
            this->nc = 0;
      }
}

void Imagen::Copiar(const Imagen & I){
      if(!I.isEmpty()){
            this->nf = I.num_filas();
            this->nc = I.num_cols();
            
            this->data = new Pixel*[nf];
            for(int i=0; i<I.num_filas(); i++){
                  this->data[i] = new Pixel[nc];
                  for(int j=0; j<I.num_cols(); j++){
                        this->data[i][j].r=I.data[i][j].r;
                        this->data[i][j].g=I.data[i][j].g;
                        this->data[i][j].b=I.data[i][j].b;
                  } 
            }
      }
}

Imagen::Imagen(){
      
      this->nf = 0;
      this->nc = 0;
}

Imagen::Imagen(int f, int c){
      //bien
      this->nf = f;
      this->nc = c;
      
      this->data = new Pixel*[nf];
      for(int i=0; i<num_filas(); i++){
            this->data[i] = new Pixel[nc];
            for(int j=0; j<num_cols(); j++){
                  this->data[i][j].r=(unsigned char)255;
                  this->data[i][j].g=(unsigned char)255;
                  this->data[i][j].b=(unsigned char)255;
            } 
      }
}

Imagen::Imagen(const Imagen & I){
      Copiar(I);
}

Imagen & Imagen::operator=(const Imagen & I){
      if(this!=&I){
            Borrar();
            Copiar(I);
      }

      return *this;
}

Imagen::~Imagen(){
      Borrar();
}

Pixel & Imagen::operator()(int i, int j){
      return this->data[i][j];
}

const Pixel & Imagen::operator()(int i, int j)const{
      return this->data[i][j];
}

int Imagen::num_filas()const{
      return nf;
}

int Imagen::num_cols()const{
      return nc;
}

bool Imagen::isEmpty() const{
    if(nf==0 || nc==0) return true; else return false;
}