#pragma once
#include "vehiculo.h"

class VehiculoArchivo{
private:
    char nombreArchivo [30];

public:
//constructor
VehiculoArchivo(const char* _nombreArchivo ="VehiculoArchivo.dat");
//metodos
bool guardar (const Vehiculo &vehi);
Vehiculo leer(const int pos);
bool modificar(Vehiculo vehi, int pos);
bool bajaLogica (const int id);
void listar();
void listarDisponibles();
void listarAlquilados();
void listarPortipo(const string tipo);
int buscarPorId(int id);
bool existeVehiculo(int id);
int contarRegistros();

};
