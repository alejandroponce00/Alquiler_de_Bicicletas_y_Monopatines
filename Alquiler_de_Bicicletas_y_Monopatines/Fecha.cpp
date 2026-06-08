#include <iostream>
#include "Fecha.h"
#include <ctime>
using namespace std;



void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::Cargar(){

    cout << "Dia: ";
    cin >> _dia;

    cout << "Mes: ";
    cin >> _mes;

    cout << "Anio: ";
    cin >> _anio;
}

void Fecha::Mostrar(){

    cout << _dia << "/"
         << _mes << "/"
         << _anio << endl;
}
string Fecha::obtenerFechaActual() {
    // 1. Obtener el tiempo actual del sistema en segundos
    time_t tiempoActual = time(nullptr);

    // 2. Convertir a la estructura de tiempo local (año, mes, día, etc.)
    tm* infoTiempo = localtime(&tiempoActual);

    // 3. Crear un búfer de caracteres para almacenar el texto formateado
    char buffer[11]; // "AAAA-MM-DD" requiere 10 caracteres + el terminador nulo '\0'

    // 4. Formatear la fecha ( %Y = Año de 4 dígitos, %m = Mes de 2 dígitos, %d = Día de 2 dígitos )
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", infoTiempo);

    // 5. Imprimir en pantalla antes de salir de la función
    cout << "Fecha del sistema: " << buffer << endl;

    // 6. Retornar el resultado convertido automáticamente a std::string
    return string(buffer);
}
