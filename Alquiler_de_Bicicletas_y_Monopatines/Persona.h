#pragma once
#include <string>

class Persona
{
    public:
        Persona ();

        const char* getNombre() const;
        const char* getApellido() const;
        const char* getDni() const;
        const char* getTelefono() const;
        const char* getDireccion() const;
        bool getEstado() const;

        void setNombre(const std::string& nombre);
        void setApellido(const std::string& apellido);
        void setDni(const std::string& dni);
        void setTelefono(const std::string& telefono);
        void setDireccion(const std::string& direccion);
        void setEstado(bool estado);

        void Cargar();
        void Mostrar();

    private:
        char _nombre[40];
        char _apellido[40];
        char _dni[11];
        char _telefono[11];
        char _direccion[100];
        bool _estado;
};
