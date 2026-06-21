#pragma once
#include <iostream>
#include <cstdio>
#include "Empleado.h"

using namespace std;

class EmpleadoArchivo
{
    public:
        EmpleadoArchivo();

        bool guardar(Empleado empl);  // solo para pruebas
        Empleado leer(int pos);
        void listar();
        void listarActivos();
        void listarPorTurno(string turno);
        int buscarPorID(int id);
        bool existeEmpleado(int id);
        int contarRegistros();

    private:
        char _nombreArchivo[30];
};
