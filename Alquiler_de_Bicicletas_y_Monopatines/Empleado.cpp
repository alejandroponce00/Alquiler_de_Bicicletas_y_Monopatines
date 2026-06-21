#include <cstring>
#include <string>
#include <iostream>
#include "Utils.h"
#include "Empleado.h"
#include "Persona.h"

using namespace std;

Empleado::Empleado()
{

}

int Empleado::getIdEmpleado() const{
    return _idEmpleado;
}

const char* Empleado::getPuesto() const{
    return _puesto;
}

const char* Empleado::getTurno() const{
    return _turno;
}

void Empleado::setIdEmpleado(int idEmpleado){
    _idEmpleado = idEmpleado;
}

void Empleado::setPuesto(const std::string& puesto){
    strcpy(_puesto, puesto.c_str());
}

void Empleado::setTurno(const std::string& turno){
    strcpy(_turno, turno.c_str());
}

void Empleado::Cargar()
{

    Persona::Cargar();


    std::string temporal;

    cout << "Ingrese ID Empleado: ";
    cin >> _idEmpleado;
    cin.ignore();

    cout << "Ingrese Puesto (Máx 14 letras): ";
    temporal = cargarCadena(14);
    setPuesto(temporal);

    cout << "Ingrese Turno (Máx 7 letras): ";
    temporal = cargarCadena(7);
    setTurno(temporal);


    setEstado(true);
}
void Empleado::Mostrar()
{

    Persona::Mostrar();


    cout << "ID Empleado: " << _idEmpleado << endl;
    cout << "Puesto:      " << _puesto << endl;
    cout << "Turno:       " << _turno << endl;


    cout << "Estado:      " << (getEstado() ? "Activo" : "Dado de baja") << endl;
    cout << "==============================================" << endl;
}
