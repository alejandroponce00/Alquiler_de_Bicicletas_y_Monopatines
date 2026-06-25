#pragma once
#include <iostream>
#include <cstdio>
#include "Alquiler.h"
using namespace std;

class AlquilerArchivo {
private:
    char _nombreArchivo[30];

public:
    AlquilerArchivo();

    // Guarda un alquiler nuevo al final del archivo
    bool guardar(Alquiler alqui);

    // Lee el alquiler en la posicion indicada (base 0)
    Alquiler leer(int pos);

    // Sobreescribe el registro en pos (para devolución / cancelación)
    bool modificar(Alquiler alqui, int pos);

    // Listados
    void listar();
    void listarActivos();
    void listarFinalizados();
    void listarPorFecha(int dia, int mes, int anio);  // 0 = ignorar ese campo
    void listarPorCliente(int idCliente);

    // Busca por codigo de alquiler, retorna posicion o -1 si no existe
    int buscarPorID(int id);

    // Cantidad total de registros
    int contarRegistros();
};

