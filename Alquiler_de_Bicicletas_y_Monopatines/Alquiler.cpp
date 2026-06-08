#include "Alquiler.h"

Alquiler::Alquiler() {
    _codAlquiler  = 0;
    _idCliente    = 0;
    _idEmpleado   = 0;
    _idVehiculo   = 0;
    _estado       = true;
    _montoTotal   = 0.0;
    _tipoAlquiler = '1';
}

// ── Setters ────────────────────────────────────────────────────────────────────

void Alquiler::setCodAlquiler(int codAlquiler)    { _codAlquiler   = codAlquiler; }
void Alquiler::setIdCliente(int idCliente)        { _idCliente     = idCliente; }
void Alquiler::setIdEmpleado(int idEmpleado)      { _idEmpleado    = idEmpleado; }
void Alquiler::setIdVehiculo(int idVehiculo)      { _idVehiculo    = idVehiculo; }
void Alquiler::setFechaHoraInicio(FechaHora fh)  { _fechaHoraInicio = fh; }
void Alquiler::setFechaHoraFin(FechaHora fh)     { _fechaHoraFin    = fh; }
void Alquiler::setEstado(bool estado)             { _estado        = estado; }
void Alquiler::setMontoTotal(float montoTotal)    { _montoTotal    = montoTotal; }
void Alquiler::setTipoAlquiler(char tipo)         { _tipoAlquiler  = tipo; }

// ── Getters ────────────────────────────────────────────────────────────────────

int       Alquiler::getCodAlquiler()     { return _codAlquiler; }
int       Alquiler::getIdCliente()       { return _idCliente; }
int       Alquiler::getIdEmpleado()      { return _idEmpleado; }
int       Alquiler::getIdVehiculo()      { return _idVehiculo; }
FechaHora Alquiler::getFechaHoraInicio() { return _fechaHoraInicio; }
FechaHora Alquiler::getFechaHoraFin()    { return _fechaHoraFin; }
bool      Alquiler::getEstado()          { return _estado; }
float     Alquiler::getMontoTotal()      { return _montoTotal; }
char      Alquiler::getTipoAlquiler()    { return _tipoAlquiler; }

// ── Logica de negocio ──────────────────────────────────────────────────────────

void Alquiler::calcularMonto(float precioPorBloque) {
    long minutos = _fechaHoraFin.totalMinutos() - _fechaHoraInicio.totalMinutos();

    if (minutos < 0) minutos = 0;

    int bloques = (int)((minutos + 14) / 15);  // redondeo hacia arriba sin ceil
    if (bloques < 1) bloques = 1;              // minimo 1 bloque (cancelacion)

    _montoTotal = bloques * precioPorBloque;
}

// ── E/S ────────────────────────────────────────────────────────────────────────

void Alquiler::cargar() {
    int d, m, a, h, min;

    cout << "\n=== CARGAR ALQUILER ===" << endl;

    cout << "ID cliente         : "; cin >> _idCliente;
    cout << "ID empleado        : "; cin >> _idEmpleado;
    cout << "ID vehiculo        : "; cin >> _idVehiculo;

    cout << "Tipo (1=Inmediato / 2=Reserva): ";
    cin >> _tipoAlquiler;


    if (_tipoAlquiler == '1') {
        FechaHora fh;
        fh.setFechaActual();
        int hora   = fh.getHora();
        int minuto = fh.getMinuto() + 15;
        if (minuto >= 60) {
            hora++;
            minuto -= 60;
        }
        fh.setHora(hora);
        fh.setMinuto(minuto);
        _fechaHoraInicio = fh;
        cout << "\nFecha de inicio asignada automaticamente: ";
        _fechaHoraInicio.mostrar();
        cout << endl;
    } else if (_tipoAlquiler == '2') {
        cout << "\n-- Fecha y hora de inicio --" << endl;
        cout << "Dia    : "; cin >> d;
        cout << "Mes    : "; cin >> m;
        cout << "Anio   : "; cin >> a;
        cout << "Hora   : "; cin >> h;
        cout << "Minuto : "; cin >> min;
        _fechaHoraInicio = FechaHora(d, m, a, h, min);
        FechaHora actual;
        actual.setFechaActual();
        if (_fechaHoraInicio.totalMinutos() < actual.totalMinutos()) {
            cout << "ERROR: la reserva debe ser para una fecha futura." << endl;
            return;
        }
    } else {
        cout << "Tipo de alquiler invalido." << endl;
        return;
    }

    _estado     = true;
    _montoTotal = 0.0;
}

void Alquiler::mostrar() {
    cout << "\n----------------------------------------" << endl;
    cout << "Codigo Alquiler : " << _codAlquiler << endl;
    cout << "ID Cliente      : " << _idCliente   << endl;
    cout << "ID Empleado     : " << _idEmpleado  << endl;
    cout << "ID Vehiculo     : " << _idVehiculo  << endl;
    cout << "Tipo            : " << (_tipoAlquiler == '2' ? "Reserva" : "Inmediato") << endl;
    cout << "Fecha Inicio    : "; _fechaHoraInicio.mostrar(); cout << endl;
    cout << "Fecha Fin       : ";
    if (_montoTotal > 0 || !_estado) {
        _fechaHoraFin.mostrar();
    } else {
        cout << "En curso";
    }
    cout << endl;
    cout << "Estado          : " << (_estado ? "Activo" : "Finalizado") << endl;
    cout << "Monto Total     : $" << _montoTotal << endl;
    cout << "----------------------------------------" << endl;
}
