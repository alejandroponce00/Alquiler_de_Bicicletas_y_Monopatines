#pragma once
#include <string>
#include "Persona.h"

class Cliente: public Persona
{
    public:
        Cliente();

       int getIdCliente() const;
       const char* getEmail() const;

       void setIdCliente(int idCliente);
       void setEmail(const std::string& email);

       void Cargar();
       void Mostrar();

    private:
        int _idCliente;
        char _email[51];
};
