#pragma once
#include "Empleado.h"
#include "EmpleadoArchivo.h"

class MenuEmpleados
{
    public:
        MenuEmpleados();

        void ejecutarMenu();
        void mostrarOpciones();
        int seleccionarOpcion();
        void ejecutarOpcion(int opcion);

    private:
        EmpleadoArchivo _repoEmpleado;
};
