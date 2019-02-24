#ifndef _QUADTREE__
#define _QUADTREE__
#include "ArbolGeneral.h"
#include <cassert>
#include <vector>

/**
 * @file Quadtree.h
 */
using namespace std;
/** @brief TDA Quadtree .
 * \b Definicion:
 * Una instancia \e a del tipo de dato abstracto Quaadtree es un arbol vacío o en caso
 * contrario cada nodo tiene 0 o cuatro hijos. La información que almacena cada nodo del arbol
 * es un booleano indicado si tiene o no cuatro hijos y un valor de información de tipo char.
 * 
 *   <tt>\#include Quadtree.h</tt>
 *
 *  @author 
 *  @date
 * 
 * */

class Quadtree{
  /**
  * @page repQuadtree Rep del TDA Quadtree
  *
  * @section invQuadtree Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faQuadtree Función de abstracción
  *
  * Añadir la función de abstracción
  */
 
   
   
  public: 
   //redefinición de un objetio Nodo de ArbolGeneral  
   typedef ArbolGeneral<pair<bool,char> >::Nodo Nodo; 
   
  private:
      /**
      * @brief ArbolGeneral donde se almacena el Quatree
      *
      * Este miembro es un objeto de tipo ArbolGeneral que 
      * almacena pares booleano char
      */
     ArbolGeneral<pair<bool,char> > tree;
     
     /**
      * @brief Lee un Quadtree de un bufer de entrada
      * @param is: flujo de entrada
      * @param n: nodo en el arbol
      * El formato de la entrada es 
      *  Un caracter->0:el nodo no tendra hijos 1: el nodo si tendra hijos.
      *  Si no tiene hijos se lee un nuevo caracter 0 o 1 .En caso de que se divide
      * el caracter que se pone como etiqueta al nodo es 0.
      */
     
     void LeerQuadtree(istream & is,Nodo &n);
     
     /**
      * @brief Escribe un Quadtree de un bufer de salida
      * @param out: flujo de salida
      * @param n: nodo en el arbol
      * El formato de la salida es 
      *  Un caracter->0:el nodo no tendra hijos 1: el nodo si tendra hijos.
      *  Si no tiene hijos se lee un nuevo caracter 0 o 1 .En caso de que se divide
      * el caracter que se pone como etiqueta al nodo es 0.
      */
     
     void EscribirQuadtree(ostream & out,Quadtree::Nodo  n)const;
     
  public:
     
     
      /**
        @brief Inicializa el quatree como un arbol vacio
        
       **/ 
        Quadtree(){
			
		}
        
      /**
        @brief Inicializa el quatree como un nodo raiz y valores
        concretor.
        @param p: par con la informacion de la raiz
       **/ 
        Quadtree(const pair<bool,char> &p);
        
      
       /**
	 * @brief Inserta cuatro hijo a partir de un nodo
	 * @param n: Nodo al que se le inserta los cuatro hijos
	 * @param datos: 4 pares(bool,char) valores uno por cada hijo. Un valor true en el par
	 * indica que el i-th hijo tendrá cuatro hijos. El segundo elemento del par es la informacion
	  * 
	 * 
	 * */
	void InsertarHijos(Nodo n,const pair<bool,char> *datos);
	
       /**
	 * @brief Borra todos los descendientes de un nodo
	 * @param n: Nodo al que se le borra los cuatro hijos
	 * 
	 * 
	 * */
	void BorrarHijos(Nodo n);
	
	/**
	 * @brief Obtiene el nodo raiz del Quadtree. version no constante
	 */
	Nodo &getRaiz();
	   
	/**
	 * @brief Obtiene el nodo raiz del Quadtree.  version constante
	 */
	const Nodo &getRaiz()const;
	
	/**
	 * @brief Obtiene el nodo padre 
	 * @param n: nodo de entrada
	 * @return el padre del nodo 
	 */
	Nodo getPadre(Nodo n)const;
	   
	/**
	 * @brief Obtiene el el hijo i-th de un nodo
	 * @param n: nodo de entrada
	 * @param i: numero de hijo (0,1,2,3)
	 * @return el hijo i-th
	 */
	Nodo getHijo(Nodo n,int i)const;
	   
	/**
	 * @brief Obtiene la informacion del nodo
	 * @param n: nodo de entrada
	 * @return un par boolean, char con la informacion del nodo
	 */
	pair<bool,char>& getInfo(Nodo n);

        
        /**
	 * @brief Modifica la etiqueta de un nodo
	 * @param n: nodo de entrada
	 * @param p: informacion a poner como etiqueta
	 
	 */
	void setInfo(Nodo n,pair<bool,char>p );

    	
	/**
	 * @brief Elimina todos los nodos del quadtree
	 */
	void clear();
	
	/**
	 * @brief Devuelve el numero de nodos que tiene el arbol
	 */
	
	unsigned int size()const;
	
	
	/**
	 * @brief Devuelve si el arbol esta vacio
	 * @return true si es vacio false en caso contrario
	 */
	bool empty()const;
	
	
	
	
	/**
	 * @brief Operador para ver si dos Quatree son iguales
	 * @return true si los dos Quadtree son iguales, false en caso contrario
	 */
	
	bool operator==(const Quadtree& Q)const;
	
	
	
	/**
	 * @brief Operador para ver si dos Quatree son diferentes
	 * @return true si los dos Quadtree son diferentes, false en caso contrario
	 */
	
	bool operator!=(const Quadtree &Q)const;
	
      
      //*ITeradores de Quadtree.Itera en preorden
      class const_iterator;
      class iterator {
      private:
	 ArbolGeneral<pair<bool,char> >::iter_preorden it;
      public:
	 iterator(){}
	 
	 /**
	  * @brief comprueba si dos iterator son iguales
	  * @return true si son iguales
	  */
	 bool operator==(const iterator &i)const{
		 return i.it == it;
	 }
	 /**
	  * @brief comprueba si dos iterator son distintos
	  * @return true si son distintis
	  */
	 bool operator!=(const iterator &i)const{
		 return i.it != it;
	 }
      
	 /**
	  * @brief Avanza al siguiente nodo en preorden
	  * @return el propio ITerador
	  */
	 iterator & operator ++(){
		 ++it;
        return *this;
	 }
	 
	 /**
	  * @brief Obtiene la informacion del nodo al que apunta
	  */
	 pair<bool,char> &  operator*(){
		 return *it;
	 }
	 
	 /**
	  * @brief Indica si apunta a un nodo hoja
	  */
	 bool Hoja()const;
	 
         	 
	 /**
	  * @brief Obtiene 4 iteradores apuntando a los hijos
	  */	 
	 vector<iterator> GetHijos()const;
	    
	friend class Quadtree;
	friend class const_iterator;
      };
      
      
      class const_iterator {
      private:
	 ArbolGeneral<pair<bool,char> >::const_iter_preorden it;
      public:
	 const_iterator(){}
	 
	 /**
	  * @brief Convierte un iterator a un const interator
	  */
	 const_iterator(const iterator &i):it(i.it){}
	    
	 /**
	  * @brief comprueba si dos iterator son iguales
	  * @return true si son iguales
	  */
	 bool operator==(const const_iterator &i)const{
		return i.it == it;
	 }
	 /**
	  * @brief comprueba si dos iterator son distintos
	  * @return true si son distintis
	  */
	 bool operator!=(const const_iterator &i)const{
		return i.it != it;
	 }
      
	 /**
	  * @brief Avanza al siguiente nodo en preorden
	  * @return el propio ITerador
	  */
	 const_iterator & operator ++(){
		++it;
        return *this;
	 }
	 
	 /**
	  * @brief Obtiene la informacion del nodo al que apunta
	  */
	 const pair<bool,char> &  operator*()const{
		return *it;
	 }
	 
	 
	 /**
	  * @brief Indica si apunta a un nodo hoja
	  */
	 bool Hoja()const; 
	 /**
	  * @brief Obtiene 4 iteradores apuntando a los hijos
	  */	 
	 vector<const_iterator> GetHijos()const;
	    
	friend class Quadtree;
      };
      
      /**
       * @brief Inicializa un iterador al comienzo del recorrido preorden del quadtree
       * @return iterador al principio
       */
      iterator begin(){
		iterator i;
        i.it = tree.begin();
        return i;
	  }
      
      /**
       * @brief Inicializa un iterador al final del recorrido preorden del quadtree
       * @return iterador al final
       */
      iterator end(){
		iterator i;
        i.it = tree.end();
    	return i;
	  }
      
      /**
       * @brief Inicializa un iterador al comienzo del recorrido preorden del quadtree
       * @return iterador al principio
       */
      const_iterator begin()const{
		const_iterator i;
        i.it = tree.begin();
        return i;
	  }
      
      /**
       * @brief Inicializa un iterador al final del recorrido preorden del quadtree
       * @return iterador al final
       */
      const_iterator end()const{
		const_iterator i;
        i.it = tree.end();
        return i;
	  }
      
      
      /**
      * @brief Operador de extracción de flujo
      * @param in Stream de entrada
      * @param Q Árbol que leer
      * @return Referencia al stream de entrada
      
      * Lee de \e in un Quadtree y lo almacena en \e Q. 
      
      */

      friend istream& operator>>(istream& in, Quadtree & Q);

      /**
      * @brief Operador de inserción en flujo
      * @param out Stream de salida
      * @param Q Árbol que escribir
      * @return Referencia al stream de salida
      * El formato de salida es :
      *  - Un único 0 indica que el arbol es vacio
      *   -Para cualquier nodo en el Quadtree si tiene los 4 hijos se imprimira un 1 en otro
      * caso un 0. Si se imprime un 0  se imprimira tambien la etiqueta del nodo (se imprimen 
      * las etiquetas de los nodos hoja
      */
    
      friend ostream& operator<< (ostream& out, const Quadtree & Q);
    
};

#endif 
	