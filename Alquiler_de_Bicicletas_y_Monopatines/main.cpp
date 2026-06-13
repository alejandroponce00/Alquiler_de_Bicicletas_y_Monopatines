#include <iostream>
using namespace std;
#include <cstdio>
#include "Alquiler.h"
#include "AlquilerArchivo.h"

int main() {
    AlquilerArchivo archivo;
    int opcion;

    do {
        cout << "\n===== GESTION DE ALQUILERES =====" << endl;
        cout << "1 - Registro de alquiler" << endl;
        cout << "2 - Reserva de alquiler" << endl;
        cout << "3 - Devolucion" << endl;
        cout << "4 - Cancelacion de reserva" << endl;
        cout << "5 - Listado de alquileres" << endl;
        cout << "0 - Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Alquiler a;
                a.setCodAlquiler(archivo.contarRegistros() + 1);
                a.cargar(1);
                archivo.guardar(a);
                break;
            }
            case 2: {
                Alquiler a;
                a.setCodAlquiler(archivo.contarRegistros() + 1);
                a.cargar(2);
                archivo.guardar(a);
                break;
            }
            case 3: {
                int id;
                float precio;
                cout << "Codigo de alquiler a devolver: "; cin >> id;
                int pos = archivo.buscarPorID(id);
                if (pos == -1) {
                    cout << "No se encontro el alquiler." << endl;
                } else {
                    Alquiler a = archivo.leer(pos);
                    if (a.getEstado() == false) {
                        cout << "El alquiler ya esta finalizado." << endl;
                    } else {
                        FechaHora fin;
                        fin.setFechaActual();
                        cout << "Precio por bloque (15 min): "; cin >> precio;
                        a.setFechaHoraFin(fin);
                        a.calcularMonto(precio);
                        a.setEstado(false);
                        archivo.modificar(a, pos);
                        cout << "\n=== DEVOLUCION REGISTRADA ===" << endl;
                        a.mostrar();
                    }
                }
                break;
            }
            case 4: {
                int id;
                float precio;
                cout << "Codigo de reserva a cancelar: "; cin >> id;
                int pos = archivo.buscarPorID(id);
                if (pos == -1) {
                    cout << "No se encontro el alquiler." << endl;
                } else {
                    Alquiler a = archivo.leer(pos);
                    if (a.getEstado() == false) {
                        cout << "La reserva ya esta finalizada." << endl;
                    } else {
                        FechaHora fin = a.getFechaHoraInicio();
                        a.setFechaHoraFin(fin);
                        cout << "Precio por bloque (15 min): "; cin >> precio;
                        a.calcularMonto(precio);
                        a.setEstado(false);
                        archivo.modificar(a, pos);
                    }
                }
                break;
            }
            case 5: {
                int subopcion;
                cout << "\n-- Listado de alquileres --" << endl;
                cout << "1 - Todos" << endl;
                cout << "2 - Activos" << endl;
                cout << "3 - Finalizados" << endl;
                cout << "4 - Por fecha" << endl;
                cout << "5 - Por cliente" << endl;
                cout << "Seleccione una opcion: ";
                cin >> subopcion;

                switch (subopcion) {
                    case 1: {
                        archivo.listar();
                        break;
                    }
                    case 2: {
                        archivo.listarActivos();
                        break;
                    }
                    case 3: {
                        archivo.listarFinalizados();
                        break;
                    }
                    case 4: {
                        int d, m, ano;
                        cout << "Dia  (0 = cualquiera): "; cin >> d;
                        cout << "Mes  (0 = cualquiera): "; cin >> m;
                        cout << "Anio (0 = cualquiera): "; cin >> ano;
                        archivo.listarPorFecha(d, m, ano);
                        break;
                    }
                    case 5: {
                        int id;
                        cout << "ID cliente: "; cin >> id;
                        archivo.listarPorCliente(id);
                        break;
                    }
                    default: {
                        cout << "Opcion invalida." << endl;
                        break;
                    }
                }
                break;
            }
            case 0: {
                cout << "Saliendo..." << endl;
                break;
            }
            default: {
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
        }
    } while (opcion != 0);

    return 0;
}
