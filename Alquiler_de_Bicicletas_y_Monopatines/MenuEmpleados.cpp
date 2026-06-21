#include "MenuEmpleados.h"
#include <iostream>

using namespace std;

MenuEmpleados::MenuEmpleados() {}

void MenuEmpleados::ejecutarMenu()
{
    int opcion;
    do
    {
        system("cls");
        mostrarOpciones();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);

        if(opcion != 0)
        {
            system("pause");
        }
    }
    while(opcion != 0);
}

void MenuEmpleados::mostrarOpciones()
{
    cout << "-------------------------------------" << endl;
    cout << "1. CONSULTA POR ID" << endl;
    cout << "2. LISTADO EMPLEADOS" << endl;
    cout << "3. VISUALIZACION DE EMPLEADOS ACTIVOS" <<endl;
    cout << "4. LISTADO POR TURNO (MANANA O TARDE)" << endl;
    cout << "0. SALIR" << endl;
    cout << "-------------------------------------" << endl;
}

int MenuEmpleados::seleccionarOpcion()
{
    int opcion;

    do
    {
        cout << "Ingrese opcion: ";
        cin >> opcion;
        if(opcion < 0 || opcion >4)
        {
            cout << "Opcion incorrecta..." << endl;
        }
    }
    while(opcion < 0 || opcion >4);
    return opcion;
}

void MenuEmpleados::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
    {
        int idBuscar;
        bool idValido = false;

        do
        {
            cout << "Ingrese ID del empleado: ";
            cin >> idBuscar;
            if(idBuscar > 0)
            {
                idValido = true;
            }
            else
            {
                cout << "Error: El ID debe ser un numero positivo" << endl;
            }
        }
        while(!idValido);

        int pos = _repoEmpleado.buscarPorID(idBuscar);

        if(pos >=0)
        {
            Empleado empl = _repoEmpleado.leer(pos);
            cout << "-------------------------------------" << endl;
            cout << "         EMPLEADO ENCONTRADO         " << endl;
            cout << "-------------------------------------" << endl;
            empl.Mostrar();
        }
        else
        {
            cout << "El empleado con el ID " << idBuscar << " no existe en el sistema." << endl;
        }
        break;
    }
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 0:

        break;
    }
}
