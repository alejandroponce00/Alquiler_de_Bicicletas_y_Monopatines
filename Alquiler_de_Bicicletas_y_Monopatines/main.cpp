#include <iostream>
#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include "Utils.h"
#include "managerMenu.h"

using namespace std;

int main(){
    ManagerMenu menu1;
    menu1.menuPrincipal();




    return 0;
}




















/*int opcion;
    EmpleadoArchivo emplArchi;


    cout << "1 - Registrar Empleado de Forma Automatica" << endl;
    cout << "Seleccione opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            system("cls");
            cout << "======= ALTA DE EMPLEADO =======" << endl;

            Empleado emp;
            cout<<"Id Empleado: "<<emplArchi.contarRegistros()+1<<endl;
            cout<<"=================================="<<endl;

            cout << "Nombre: ";
            emp.setNombre(cargarCadena(40));

            cout << "Apellido: ";
            emp.setApellido(cargarCadena(40));

            cout << "DNI: ";
            emp.setDni(cargarCadena(11));

            cout << "Telefono: ";
            emp.setTelefono(cargarCadena(11));

            cout << "Direccion: ";
            emp.setDireccion(cargarCadena(100));

            cout << "Puesto: ";
            emp.setPuesto(cargarCadena(15));

            cout << "Turno: ";
            emp.setTurno(cargarCadena(8));

            int nuevoId = emplArchi.contarRegistros()+1;
            emp.setIdEmpleado(nuevoId);

            cout << "ID Asignado Automaticamente: " << nuevoId << endl;

            emp.setEstado(true);


            if (emplArchi.guardar(emp)) {
                cout << endl << "¡Empleado guardado con exito!" << endl;
            } else {
                cout << endl << "Error: No se pudo escribir en el archivo." << endl;
            }

            system("pause");
            break;
        }


    }*/
