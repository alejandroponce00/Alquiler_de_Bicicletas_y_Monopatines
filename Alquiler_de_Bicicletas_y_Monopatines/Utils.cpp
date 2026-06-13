#include "Utils.h"

float Utils::calcularMonto(FechaHora inicio, FechaHora fin, float precioPorBloque) {
    long minutos = fin.totalMinutos() - inicio.totalMinutos();
    if (minutos < 0) minutos = 0;
    int bloques = (int)((minutos + 14) / 15);
    if (bloques < 1) bloques = 1;
    return bloques * precioPorBloque;
}

FechaHora Utils::pedirFechaInicio(int tipo) {
    if (tipo == 1) {
        FechaHora fh;
        fh.setFechaActual();
        cout << "Fecha de inicio asignada automaticamente: ";
        fh.mostrar();
        cout << endl;
        return fh;
    } else if (tipo == 2) {
        int d, m, a, h, min;
        cout << "\n-- Fecha y hora de inicio --" << endl;
        cout << "Dia    : "; cin >> d;
        cout << "Mes    : "; cin >> m;
        cout << "Anio   : "; cin >> a;
        cout << "Hora   : "; cin >> h;
        cout << "Minuto : "; cin >> min;
        FechaHora fh(d, m, a, h, min);
        FechaHora actual;
        actual.setFechaActual();
        if (fh.totalMinutos() < actual.totalMinutos()) {
            cout << "ERROR: la reserva debe ser para una fecha futura." << endl;
            return actual;
        }
        return fh;
    } else {
        cout << "Opcion invalida." << endl;
        FechaHora fh;
        return fh;
    }
}
