/**
 * Ejercicio 5 - Manuel Fernández La-Chica
 y
 * Ejercicio 6 - Manuel Fernández La-Chica
 */

#include <map>
#include <utility>
#include <list>

using namespace std;

class Matriculas{
  private:
    multimap<string, string> matriculados;
  public:
    void Insertar(const string &dni, const string &cod_asig){
      pair<string, string> matricula;
      matriculados.insert(pair<string, string> (dni, cod_asig));
    }

    void Matriculas::Borrar(const string &dni, const string &cod_asig){
      bool encontrado = false;
      multimap<string, string>::iterator it = matriculados.begin();
      for( ; it!= matriculados.end() && !encontrado; ++it){
        if ((*it).first==dni && (*it).second==cod_asig) {
          matriculados.erase(it);
          encontrado = true;
        }
      }
    }


//Ejercicio6

class iterator{
  private:
    multimap<string, string>::iterator punt;
  public:
    iterator(){}
    iterator(const iterator &copy){
      punt = copy.punt;
    }
    iterator &operator++(){
      punt++;
      return *this;
    }
    iterator &operator--(){
      punt--;
      return *this;
    }
    bool operator==(const iterator &it){
      return it.punt == punt;
    }
    bool iterator!=(const iterator &it){
      return it.punt!=punt;
    }
    string operator*(){
      return (*punt).second;
    }
    friend class Matriculas;
};

list<string> GetAlumnos(const string &cod_asig){
  list<string> alumnos;
  multimap<string, string>::iterator it = matriculados.begin();

  for( ; it!=matriculados.end(); ++it){
    if ((*it).second==cod_asig) {
      alumnos.push_back(it);
    }
  }
}

list<string> GetAsignaturas(const string &dni){
  list<string> asignaturas;
  multimap<string, string>::iterator it=matriculados.begin();

  for( ; it!=matriculados.end(); ++it){
    if ((*it).first == dni) {
      asignaturas.push_back(it);
    }
  }
}

};
