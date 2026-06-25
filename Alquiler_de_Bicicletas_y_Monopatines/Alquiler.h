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
    FechaHora _fechaHoraInicio;// objeto de otra clase como atributo
    FechaHora _fechaHoraFin;// objeto de otra clase como atributo
    bool      _estado;       // true = activo | false = finalizado
    float     _montoTotal;

public:
    Alquiler();//constructor

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


