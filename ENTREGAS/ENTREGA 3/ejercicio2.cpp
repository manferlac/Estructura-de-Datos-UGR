/**
 * Ejercicio 2 - Manuel Fernández La-Chica
 */

#include <string>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

struct alumno{
    char dni[9];
    string nombre;
    string apellidos;
    string correo;
    double nota_selectividad;

    bool operator<(const alumno &alumno1) const{
        if(alumno1.nota_selectividad > nota_selectividad){
            return true;
        }else{
            return false;
        }
    }
};

void ObtenerPrioridad(const list<alumno> &alumnos, priority_queue<alumno> &pq){
    list<alumno> copia = alumnos;
    while(!copia.empty()){
        pq.push(copia.front());
        copia.pop_front();
    }
}

int main(){
    list<alumno> alumnos;
    priority_queue<alumno> pq;

    //alumno 1
    alumno a1;
    strcpy(a1.dni, "16665339B");
    a1.nombre = "Pepe";
    a1.apellidos = "Rodriguez";
    a1.correo = "pepe@gmail.com";
    a1.nota_selectividad = 5.6;
    alumnos.push_back(a1);

    //alumno 2
    alumno a2;
    strcpy(a2.dni, "98766559E");
    a2.nombre = "Rodrigo";
    a2.apellidos = "Castilla";
    a2.correo = "rodricastilla@gmail.com";
    a2.nota_selectividad = 8.1;
    alumnos.push_back(a2);

    //alumno 3
    alumno a3;
    strcpy(a3.dni, "83367182R");
    a3.nombre = "Jesus";
    a3.apellidos = "Moreno";
    a3.correo = "jesusmoreno@gmail.com";
    a3.nota_selectividad = 9.4;
    alumnos.push_back(a3);

    //alumno 4
    alumno a4;
    strcpy(a4.dni, "26998715C");
    a4.nombre = "Manuel";
    a4.apellidos = "Gonzalez";
    a4.correo = "mangonza@gmail.com";
    a4.nota_selectividad = 3.4;
    alumnos.push_back(a4);

    ObtenerPrioridad(alumnos, pq);

    cout << "ALUMNOS (de mayor a menor nota): " << endl;

    while(!pq.empty()){
        cout << pq.top().nombre << "\t - " << pq.top().nota_selectividad << endl;
        pq.pop();
    }
}