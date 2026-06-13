#pragma once

#include <iostream>
#include "FechaHora.h"
using namespace std;

class Utils {
public:
    static float     calcularMonto(FechaHora inicio, FechaHora fin, float precioPorBloque);
    static FechaHora pedirFechaInicio(int tipo); // 1=inmediato, 2=reserva
};

