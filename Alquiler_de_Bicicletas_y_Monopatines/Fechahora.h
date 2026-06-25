
#pragma once

#include <iostream>
#include <ctime>     // necesario para obtener la fecha actual del sistema en setFechaActual()
using namespace std;

class FechaHora {
private:
    // Cada componente de la fecha y hora se guarda por separado
    int _dia;
    int _mes;
    int _anio;
    int _hora;
    int _minuto;

public:
    // Constructor por defecto: inicializa en 1/1/2000 00:00
    FechaHora();

    // Constructor con valores: permite crear una fecha especifica
    // Ejemplo: FechaHora f(5, 6, 2025, 10, 30)
    FechaHora(int dia, int mes, int anio, int hora, int minuto);

    // Toma la fecha y hora actual del sistema operativo y la guarda en los atributos
    // Se usa al registrar un alquiler inmediato
    void setFechaActual();

    // Getters: devuelven cada componente de la fecha
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    // Setters: permiten modificar cada componente por separado
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setHora(int hora);
    void setMinuto(int minuto);

    // Convierte la fecha completa a minutos totales
    // Se usa para comparar dos fechas y calcular diferencias de tiempo
    long totalMinutos();

    // Muestra la fecha por pantalla en formato: dia/mes/anio  hora:minuto
    void mostrar();
};


