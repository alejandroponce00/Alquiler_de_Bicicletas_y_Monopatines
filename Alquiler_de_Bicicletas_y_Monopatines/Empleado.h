#pragma once
#include <string>
#include "Persona.h"

class Empleado: public Persona
{
    public:
       Empleado();

       int getIdEmpleado() const;
       const char* getPuesto() const;
       const char* getTurno() const;

       void setIdEmpleado(int idEmpleado);
       void setPuesto(const std::string& puesto);
       void setTurno(const std::string& turno);

       void Cargar();
       void Mostrar();

    private:
        int _idEmpleado;
        char _puesto[15];
        char _turno[8];
};
