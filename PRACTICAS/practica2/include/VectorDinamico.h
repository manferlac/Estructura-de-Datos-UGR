/**
  * @file vectordinamico.h
  * @brief Fichero cabecera del TDA VectorDinamico
  * 
  */
#ifndef VECTORDINAMICO_h
#define VECTORDINAMICO_h


/**
  * @brief TDA VectorDinamico
  * 
  * La clase @c VectorDinamico representa una estructura de datos con @e templates,
  * esto permite montar sobre ella otro TDA y evitar redundancia de código.
  * Esta estructura permite acceder a la posiciones en un tiempo reducido,
  * sacrificando eficiencia a la hora de insertar. Permite redimensionar el
  * vector a medida que se añaden o eliminan datos. Consta de un vector de
  * datos y dos enteros que indican el número de posiciones reservadas y utilizadas.
  *
  * @author Emilio Jose Ochando Pantigas
  * @author Manuel Fernandez Lachica
  * @date Octubre 2018
  */
 
template <class T>
class VectorDinamico{

 private:
  
  int utilizados;  /**< posiciones utilizadas */
  int reservados;  /**< posiciones reservadas */
  T *datos;  /**< datos */
    
  void resize(int nuevoTamano);
  void Copiar(const VectorDinamico<T> &v);
  void Liberar();
  void anadir(T dato);

 public:

  VectorDinamico(); //CONSTRUCTOR VACIO

  VectorDinamico(int n); //CONSTRUCTOR, RESERVA n ELEMENTOS

  VectorDinamico(const VectorDinamico<T> &original); //CONSTRUCTOR DE COPIA

  ~VectorDinamico(); //DESTRUCTOR

  VectorDinamico& operator=(const VectorDinamico &original); //OPERADOR DE ASIGNACION

  int size() const; //DEVUELVE LA VARIABLE n

  T& operator[](int i); //DEVUELVE LA REFERENCIA AL DATO DE LA POSICION I
 
  const T& operator[](int i) const; //DEVUELVE EL DATO

  void Insertar(const T &dato, int pos); //INSERTA UN ELEMENTO EN LA POSICION pos

  void Borrar(int pos); //ELIMINA EL ELEMENTO DE LA POSICION i

  //bool operator ==(const VectorDinamico &otro);

  //bool operator !=(const VectorDinamico &otro);

  //bool operator>(const VectorDinamico &otro);

  //bool operator<(const VectorDinamico &otro);

};

#include "VectorDinamico.cpp"

#endif


  
  