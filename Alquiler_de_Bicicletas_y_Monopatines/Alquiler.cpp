#include "Alquiler.h"
#include "Utils.h"

Alquiler::Alquiler() {
    _codAlquiler  = 0;
    _idCliente    = 0;
    _idEmpleado   = 0;
    _idVehiculo   = 0;
    _estado       = true;
    _montoTotal   = 0.0;
}

// ── Setters ────────────────────────────────────────────────────────────────────

void Alquiler::setCodAlquiler(int codAlquiler)    { _codAlquiler     = codAlquiler; }
void Alquiler::setIdCliente(int idCliente)        { _idCliente       = idCliente; }
void Alquiler::setIdEmpleado(int idEmpleado)      { _idEmpleado      = idEmpleado; }
void Alquiler::setIdVehiculo(int idVehiculo)      { _idVehiculo      = idVehiculo; }
void Alquiler::setFechaHoraInicio(FechaHora fh)  { _fechaHoraInicio = fh; }
void Alquiler::setFechaHoraFin(FechaHora fh)     { _fechaHoraFin    = fh; }
void Alquiler::setEstado(bool estado)             { _estado          = estado; }
void Alquiler::setMontoTotal(float montoTotal)    { _montoTotal      = montoTotal; }

// ── Getters ────────────────────────────────────────────────────────────────────

int       Alquiler::getCodAlquiler()     { return _codAlquiler; }
int       Alquiler::getIdCliente()       { return _idCliente; }
int       Alquiler::getIdEmpleado()      { return _idEmpleado; }
int       Alquiler::getIdVehiculo()      { return _idVehiculo; }
FechaHora Alquiler::getFechaHoraInicio() { return _fechaHoraInicio; }
FechaHora Alquiler::getFechaHoraFin()    { return _fechaHoraFin; }
bool      Alquiler::getEstado()          { return _estado; }
float     Alquiler::getMontoTotal()      { return _montoTotal; }

// ── Logica de negocio ──────────────────────────────────────────────────────────

void Alquiler::calcularMonto(float precioPorBloque) {
    _montoTotal = Utils::calcularMonto(_fechaHoraInicio, _fechaHoraFin, precioPorBloque);
}

// ── E/S ────────────────────────────────────────────────────────────────────────

void Alquiler::cargar(int tipo) {
    cout << "\n=== CARGAR ALQUILER ===" << endl;

    cout << "ID cliente  : "; cin >> _idCliente;
    cout << "ID empleado : "; cin >> _idEmpleado;
    cout << "ID vehiculo : "; cin >> _idVehiculo;

    _fechaHoraInicio = Utils::pedirFechaInicio(tipo);

    _estado     = true;
    _montoTotal = 0.0;
}

void Alquiler::mostrar() {
    cout << "\n----------------------------------------" << endl;
    cout << "Codigo Alquiler : " << _codAlquiler << endl;
    cout << "ID Cliente      : " << _idCliente   << endl;
    cout << "ID Empleado     : " << _idEmpleado  << endl;
    cout << "ID Vehiculo     : " << _idVehiculo  << endl;
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
