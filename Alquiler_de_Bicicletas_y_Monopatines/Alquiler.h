#pragma once

#include <iostream>
#include "FechaHora.h"
using namespace std;

class Alquiler {
private:
    int       _codAlquiler;
    int       _idCliente;
    int       _idEmpleado;
    int       _idVehiculo;
    FechaHora _fechaHoraInicio;
    FechaHora _fechaHoraFin;
    bool      _estado;         // true = activo | false = finalizado
    float     _montoTotal;
    char      _tipoAlquiler;   // '1' = Inmediato | '2' = Reserva

public:
    Alquiler();

    // Setters
    void setCodAlquiler(int codAlquiler);
    void setIdCliente(int idCliente);
    void setIdEmpleado(int idEmpleado);
    void setIdVehiculo(int idVehiculo);
    void setFechaHoraInicio(FechaHora fh);
    void setFechaHoraFin(FechaHora fh);
    void setEstado(bool estado);
    void setMontoTotal(float montoTotal);
    void setTipoAlquiler(char tipo);

    // Getters
    int       getCodAlquiler();
    int       getIdCliente();
    int       getIdEmpleado();
    int       getIdVehiculo();
    FechaHora getFechaHoraInicio();
    FechaHora getFechaHoraFin();
    bool      getEstado();
    float     getMontoTotal();
    char      getTipoAlquiler();

    // Calcula el monto en bloques de 15 minutos segun el precio del vehiculo.
    // Minimo: 1 bloque (aplica en cancelacion tambien).
    void calcularMonto(float precioPorBloque);

    void cargar();
    void mostrar();
};


