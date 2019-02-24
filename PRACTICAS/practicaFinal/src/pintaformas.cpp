#include "pintaformas.h"


void PintaCuadrado(Imagen &I,int f,int c,int lado,color col){
  int filas=I.num_filas(); 
  int cols =I.num_cols();
 for (int i=f-lado; i<=f+lado && i<filas ;i++)
          for (int j=c-lado; j<=c+lado && j<cols;j++)
	    if (i>=0 && j>=0)
	           I(i,j)=col;
	  
   	  
}	  
          
void PintaRectangulo(Imagen &I,int f,int c,int lado1,int lado2,color col){
  int filas=I.num_filas(); 
  int cols =I.num_cols();
 for (int i=f-lado1; i<=f+lado1 && i<filas ;i++)
          for (int j=c-lado2; j<=c+lado2 && j<cols;j++)
	    if (i>=0 && j>=0)
	           I(i,j)=col;
	  
   	  
}
void PintaCirculo(Imagen &I,int f,int c,int radio,color col){
  int filas=I.num_filas(); 
  int cols =I.num_cols();
 for (int i=f-radio; i<=f+radio && i<filas ;i++)
          for (int j=c-radio; j<=c+radio && j<cols;j++)
	    if (i>=0 && j>=0)
	     if (hypot(i-f,j-c)<=radio)
	           I(i,j)=col;
	  
   	  
}	           
          
bool PintaLinea(Imagen &I,int f1,int c1,int f2,int c2,color c,unsigned int w){
    int filas=I.num_filas(); 
    int cols =I.num_cols();
    
    if (!(f1>=0 && f1<filas && c1>=0 && c1<cols &&
        f2>=0 && f2<filas && c2>=0 && c2<cols))
      return false;
    if (f1==f2 && c1==c2) return false;
    
    if (f1==f2){
       
       int minc,maxc;
       if (c1<c2){
	    minc=c1; maxc= c2;
       }
       else {
	    minc=c2; maxc= c1;
       }
       
       for (int j=minc;j<=maxc;j++)
	  PintaCuadrado(I,f1,j,w,c);
	  
    }
    else if (c1==c2){
       
       int minf,maxf;
       if (f1<f2){
	    minf=f1; maxf= f2;
       }
       else {
	    minf=f2; maxf= f1;
       }
     
       for (int j=minf;j<=maxf;j++)
	      PintaCuadrado(I,j,c1,w,c);
	  
    }
    
    
    else{
      if (abs(c1-c2)<abs(f1-f2)){
	  double pend= (double)(c1-c2)/(double)(f1-f2);
	  double desp= c1-f1*pend;
	  
	  int minf,maxf;
       if (f1<f2){
	    minf=f1; maxf= f2;
       }
       else {
	    minf=f2; maxf= f1;
       }
       
       for (int i=minf;i<=maxf;i++){
	     int j= (int)floor(pend*i+desp);
	     if (j>=0 && j<cols)
	      //I(i,j)=c;
	       PintaCuadrado(I,i,j,w,c);
       }
      }
      else{
	  double pend= (double)(f1-f2)/(double)(c1-c2);
	  double desp= f1-c1*pend;
	  
	  int minf,maxf;
       if (c1<c2){
	    minf=c1; maxf= c2;
       }
       else {
	    minf=c2; maxf= c1;
       }
       
       for (int i=minf;i<=maxf;i++){
	     int j= (int)floor(pend*i+desp);
	     if (j>=0 && j<cols)
	      //I(i,j)=c;
	       PintaCuadrado(I,j,i,w,c);
       }
      } 
    }
    return true;
}           