#pragma once
#include <iostream>
#include <cstdio>
#include "Cliente.h"

using namespace std;

class ClienteArchivo
{
    public:
        ClienteArchivo();

        bool guardar(Cliente clien);
        Cliente leer(int pos);
        bool modificar(Cliente clien, int pos);
        bool bajaLogica(int id);
        void listar();
        void listarActivos();
        void listarInactivos();
        int buscarPorID(int id);
        int buscarPorDNI(string dni);
        bool existeDNI(string dni);
        int contarRegistros();

    private:
        char _nombreArchivo[30];
};
