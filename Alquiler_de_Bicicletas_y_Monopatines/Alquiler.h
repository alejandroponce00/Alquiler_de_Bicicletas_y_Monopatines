#ifndef ALQUILER_H
#define ALQUILER_H

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
    bool      _estado;       // true = activo | false = finalizado
    float     _montoTotal;

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

    // Getters
    int       getCodAlquiler();
    int       getIdCliente();
    int       getIdEmpleado();
    int       getIdVehiculo();
    FechaHora getFechaHoraInicio();
    FechaHora getFechaHoraFin();
    bool      getEstado();
    float     getMontoTotal();

    void calcularMonto(float precioPorBloque);

    void cargar(int tipo);
    void mostrar();
};

#endif
