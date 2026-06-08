#pragma once
#include <iostream>
using namespace std;
class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();

    void Cargar();
    void Mostrar();


    // Retorna la fecha actual en formato texto (AAAA-MM-DD)
    string obtenerFechaActual();
};
