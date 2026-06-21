#include <cstring>
#include <string>
#include <iostream>
#include "Persona.h"

using namespace std;

Persona::Persona() {}

const char* Persona::getNombre()    const { return _nombre; }
const char* Persona::getApellido()  const { return _apellido; }
const char* Persona::getDni()       const { return _dni; }
const char* Persona::getTelefono()  const { return _telefono; }
const char* Persona::getDireccion() const { return _direccion; }
bool        Persona::getEstado()    const { return _estado; }

void Persona::setNombre(const std::string& nombre)       { strcpy(_nombre, nombre.c_str()); }
void Persona::setApellido(const std::string& apellido)   { strcpy(_apellido, apellido.c_str()); }
void Persona::setDni(const std::string& dni)             { strcpy(_dni, dni.c_str()); }
void Persona::setTelefono(const std::string& telefono)   { strcpy(_telefono, telefono.c_str()); }
void Persona::setDireccion(const std::string& direccion) { strcpy(_direccion, direccion.c_str()); }
void Persona::setEstado(bool estado)                     { _estado = estado; }

void Persona::Cargar()
{
    cout << "Nombre: ";
    cin.getline(_nombre, 40);
    cout << "Apellido: ";
    cin.getline(_apellido, 40);
    cout << "DNI: ";
    cin.getline(_dni,11);
    cout << "Telefono: ";
    cin.getline(_telefono,11);
    cout << "Direccion: ";
    cin.ignore(); //limpiamos lo que haya en memoria anteriormente y guarde la direccion correctamente
    cin.getline(_direccion, 100); // para poder guardar direcciones con espacio
    _estado = true;

}

void Persona::Mostrar() {


        cout << _nombre << " " << _apellido << endl;
        cout << "DNI: "       << _dni       << endl;
        cout << "Telefono: "  << _telefono  << endl;
        cout << "Direccion: " << _direccion << endl;
        cout << "Estado: " << (_estado ? "Activo" : "De baja") << endl;


}
