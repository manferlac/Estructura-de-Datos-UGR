#include <iostream>
#include <cassert>


using namespace std;

//*************************** METODOS PRIVADOS *****************************//
//---------- RESIZE ----------//
template <class T>
void VectorDinamico<T>::resize(int nuevoTamano){
    
    T* aux = new T[nuevoTamano];
    int minimo = (this->utilizados<nuevoTamano)?this->utilizados:nuevoTamano;
    for(int i = 0; i<minimo; i++)
        aux[i] = this->datos[i];
    this->reservados = nuevoTamano;
    this->utilizados = minimo;
    delete[] this->datos;
    this->datos = aux;
}
//----------------------------//

//---------- COPIAR ----------//
template <class T>
void VectorDinamico<T>::Copiar (const VectorDinamico<T> &v){
    reservados = v.reservados;
    utilizados=v.utilizados;
    datos = new T [reservados];
    for (int i=0; i<utilizados; i++)
        datos[i] = v.datos[i];
}
//----------------------------//

//---------- LIBERAR ----------//
template <class T>
void VectorDinamico<T>::Liberar(){
    delete [] datos;
}
//----------------------------//

//---------- ANADIR ----------//
template <class T>
void VectorDinamico<T>::anadir(T dato) {
    if (this->datos == 0){
        this->reservados=1;
        this->datos= new T[this->reservados];
        this->datos[0]= dato;
        this->utilizados=1;
    }else{
        if(this->utilizados == this->reservados) resize(this->reservados*2);
        
        this->datos[this->utilizados]=dato;
        this->utilizados++;
    }
}
//----------------------------//

//**************************************************************************//

//*************************** METODOS PÚBLICOS *****************************//

//---------- CONSTRUCTOR VACIO ----------//
template <class T>
VectorDinamico<T>::VectorDinamico(){ 
  this->datos = 0;
  this->utilizados = 0;
  this->reservados = 0;
}
//---------------------------------------//

//---------- CONSTRUCTOR CON TAMAÑO RESERVADO n ----------//
template <class T>
VectorDinamico<T>::VectorDinamico(int n)
{
    if(n>0)
        this->datos = new T[n];
    this->reservados = n;
    this->utilizados = 0;
}
//--------------------------------------------------------//

//---------- CONSTRUCTOR DE COPIA ----------//
template <class T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico &original)
{
    this->reservados = original.reservados;
    if(this->reservados>0){
        this->datos = new T[this->reservados];
        this->utilizados = original.utilizados;

        for(int i=0; i<this->utilizados; i++)
            this->datos[i] = original.datos[i];
    }else{
        this->datos = 0;
        this->utilizados = 0;
        this->reservados = 0;
    }
}
//------------------------------------------//

//---------- DESTRUCTOR ----------//
template <class T>
VectorDinamico<T>::~VectorDinamico()
{
    if (this->datos != 0) 
        delete [] this->datos;
    this->datos = 0;
    this->utilizados = 0;
    this->reservados = 0;
}
//--------------------------------//

//---------- OPERADOR DE ASIGNACIÓN ----------//
template <class T>
VectorDinamico<T>& VectorDinamico<T>::operator= (const VectorDinamico<T> &original)
{
  if(this!= &original) {
    if(this->datos!=0) 
        delete[] this->datos;

    this->reservados= original.reservados;
    this->utilizados = original.utilizados;

    if(original.datos!=0) 
        this->datos= new T[this->reservados];

    for (int i=0; i<this->utilizados; ++i)
      this->datos[i]= original.datos[i];
  }
  return *this;
}
//--------------------------------//

//---------- size() ----------//
template <class T>
int VectorDinamico<T>::size() const{
  return this->utilizados;
}
//----------------------------//

//---------- OPERADOR [] ----------//
template <class T>
T& VectorDinamico<T>::operator[] (int i) {
    return datos[i];
}
//--------------------------------//

//---------- OPERADOR [] const ----------//
template <class T>
const T& VectorDinamico<T>::operator[] (int i) const {
    return datos[i];
}
//---------------------------------------//


//---------- INSERTAR ----------//
template <class T>
void VectorDinamico<T>::Insertar(const T &dato, int pos){
    if(this->datos == 0){
        anadir(dato);
    }else{
        if(pos>=0 && pos<=this->reservados){
            if(pos>=this->utilizados){
                anadir(dato);
            }else{
                if(this->utilizados == this->reservados){
                    resize(this->reservados*2);
                }

                for(int i = this->utilizados; i>=pos; i--){
                    this->datos[i] = this->datos[i-1];
                }

                this->datos[pos] = dato;
                this->utilizados++;
            }
        }
    }
}
//------------------------------//

//---------- BORRAR ----------//
template <class T>
void VectorDinamico<T>::Borrar(int pos){
    for(int i = pos; i<this->utilizados-1; i++)
        this->datos[i] = this->datos[i+1];
    this->utilizados--;
    if(this->utilizados == 0)
        delete[] this->datos;
}
//----------------------------//

//**************************************************************************//









