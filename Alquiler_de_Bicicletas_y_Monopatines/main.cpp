#include <iostream>
#include "Alquiler.h"
#include "AlquilerArchivo.h"
#include "FechaHora.h"

using namespace std;

int main() {

    AlquilerArchivo archivo;
    int opcion;

    do {

        system("cls");

        cout << "==============================" << endl;
        cout << "      MENU ALQUILERES" << endl;
        cout << "==============================" << endl;
        cout << "1 - Registrar alquiler" << endl;
        cout << "2 - Listar todos" << endl;
        cout << "3 - Listar activos" << endl;
        cout << "4 - Listar finalizados" << endl;
        cout << "5 - Buscar alquiler por codigo" << endl;
        cout << "6 - Finalizar alquiler" << endl;
        cout << "7 - Listar por cliente" << endl;
        cout << "8 - Listar por fecha" << endl;
        cout << "9 - Cantidad de registros" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

        case 1:
        {
            Alquiler a;
            a.setCodAlquiler(archivo.contarRegistros() + 1);//para asignar el id automaticamente
            a.cargar();
            archivo.guardar(a);
            system("pause");
        }
        break;

        case 2:
        {
            archivo.listar();
            system("pause");
        }
        break;

        case 3:
        {
            archivo.listarActivos();
            system("pause");
        }
        break;

        case 4:
        {
            archivo.listarFinalizados();
            system("pause");
        }
        break;

        case 5:
        {
            int codigo;

            cout << "Codigo de alquiler: ";
            cin >> codigo;

            int pos = archivo.buscarPorID(codigo);
            if(pos >= 0) {
                archivo.leer(pos).mostrar();
            }
            else {
                cout << "No existe ese alquiler." << endl;
            }

            system("pause");
        }
        break;

        case 6:
        {
            int codigo;
            float precioBloque;

            cout << "Codigo de alquiler a finalizar: ";
            cin >> codigo;

            int pos = archivo.buscarPorID(codigo);

            if(pos >= 0) {

                Alquiler a = archivo.leer(pos);

                FechaHora fin;
                fin.setFechaActual();

                a.setFechaHoraFin(fin);

                cout << "Precio por bloque de 15 minutos: $";
                cin >> precioBloque;

                a.calcularMonto(precioBloque);

                a.setEstado(false);

                archivo.modificar(a, pos);

                cout << endl;
                cout << "Alquiler finalizado correctamente." << endl;
                cout << "Monto total: $" << a.getMontoTotal() << endl;
            }
            else {
                cout << "No existe ese alquiler." << endl;
            }

            system("pause");
        }
        break;

        case 7:
        {
            int idCliente;

            cout << "ID Cliente: ";
            cin >> idCliente;

            archivo.listarPorCliente(idCliente);

            system("pause");
        }
        break;

        case 8:
        {
            int dia, mes, anio;

            cout << "Dia (0=todos): ";
            cin >> dia;

            cout << "Mes (0=todos): ";
            cin >> mes;

            cout << "Anio (0=todos): ";
            cin >> anio;

            archivo.listarPorFecha(dia, mes, anio);

            system("pause");
        }
        break;

        case 9:
        {
            cout << "Cantidad de registros: "
                 << archivo.contarRegistros()
                 << endl;

            system("pause");
        }
        break;

        case 0:
            cout << "Fin del programa." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
            system("pause");
        }

    } while(opcion != 0);

    return 0;
}
