#pragma once
#include <iostream>
#include <regex>
#include "FechaHora.h"
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"
#include "VehiculoArchivo.h"
using namespace std;


    float calMonto(FechaHora inicio, FechaHora fin, float precioPorBloque);
    FechaHora pedirFechaInicio(int tipo); // 1=inmediato, 2=reserva

    bool validarEmpleado(int id);



    // Metodos de validacion para Vehiculo
    string cargarCadena(int maximo);
    void   opVehiculo(int &op);
    void   validacionRodado(int &rodado, char* tipoVehiculo);
    void   validarPrecio(float &precio);
    void   validarCambios(bool &cambio);
    bool validarVehiculo(int id);

    //metodos cliente
    void validarEmail(string &email);
    bool validarCliente(int id);
    void validarDni(string &dni,ClienteArchivo clienArchi);
