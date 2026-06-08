#include "FechaHora.h"

FechaHora::FechaHora() : _dia(1), _mes(1), _anio(2000), _hora(0), _minuto(0) {}

FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto)
    : _dia(dia), _mes(mes), _anio(anio), _hora(hora), _minuto(minuto) {}

void FechaHora::setFechaActual() {
    time_t ahora = time(NULL);
    tm* t = localtime(&ahora);
    _dia    = t->tm_mday;
    _mes    = t->tm_mon + 1;
    _anio   = t->tm_year + 1900;
    _hora   = t->tm_hour;
    _minuto = t->tm_min;
}

int FechaHora::getDia()    { return _dia; }
int FechaHora::getMes()    { return _mes; }
int FechaHora::getAnio()   { return _anio; }
int FechaHora::getHora()   { return _hora; }
int FechaHora::getMinuto() { return _minuto; }

void FechaHora::setDia(int dia)       { _dia    = dia; }
void FechaHora::setMes(int mes)       { _mes    = mes; }
void FechaHora::setAnio(int anio)     { _anio   = anio; }
void FechaHora::setHora(int hora)     { _hora   = hora; }
void FechaHora::setMinuto(int minuto) { _minuto = minuto; }

long FechaHora::totalMinutos() {
    long dias = (long)_anio * 365 + _mes * 30 + _dia;
    return dias * 24 * 60 + _hora * 60 + _minuto;
}


void FechaHora::mostrar() {
    cout << _dia  << "/"
         << _mes  << "/"
         << _anio << "  "
         << _hora << ":"
         << _minuto;
}
