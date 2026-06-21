#include "FechaHora.h"

// Inicializa con una fecha por defecto para evitar valores basura en memoria
FechaHora::FechaHora() : _dia(1), _mes(1), _anio(2000), _hora(0), _minuto(0) {}

// Inicializa con los valores que se pasan como parametro
FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto)
    : _dia(dia), _mes(mes), _anio(anio), _hora(hora), _minuto(minuto) {}

// Obtiene la fecha y hora actual del sistema usando la libreria ctime
// time(NULL) devuelve los segundos transcurridos desde 1/1/1970
// localtime convierte esos segundos a dia, mes, anio, hora y minuto
void FechaHora::setFechaActual() {
    time_t ahora = time(NULL);
    tm* t = localtime(&ahora);
    _dia    = t->tm_mday;
    _mes    = t->tm_mon + 1;   // tm_mon va de 0 a 11, por eso se suma 1
    _anio   = t->tm_year + 1900; // tm_year cuenta desde 1900
    _hora   = t->tm_hour;
    _minuto = t->tm_min;
}

// Getters
int FechaHora::getDia()    { return _dia; }
int FechaHora::getMes()    { return _mes; }
int FechaHora::getAnio()   { return _anio; }
int FechaHora::getHora()   { return _hora; }
int FechaHora::getMinuto() { return _minuto; }

// Setters
void FechaHora::setDia(int dia)       { _dia    = dia; }
void FechaHora::setMes(int mes)       { _mes    = mes; }
void FechaHora::setAnio(int anio)     { _anio   = anio; }
void FechaHora::setHora(int hora)     { _hora   = hora; }
void FechaHora::setMinuto(int minuto) { _minuto = minuto; }

// Convierte la fecha entera a un numero de minutos
// Esto permite comparar dos fechas y calcular cuanto tiempo paso entre ellas
// Ejemplo: si inicio da 1.000.000 minutos y fin da 1.000.090, la diferencia es 90 minutos
long FechaHora::totalMinutos() {
    long dias = (long)_anio * 365 + _mes * 30 + _dia;
    return dias * 24 * 60 + _hora * 60 + _minuto;
}

// Muestra la fecha en formato: dia/mes/anio  hora:minuto
void FechaHora::mostrar() {
    cout << _dia  << "/"
         << _mes  << "/"
         << _anio << "  "
         << _hora << ":"
         << _minuto;
}
