#include <cstring>
#include <string>
#include <iostream>
#include "Persona.h"
#include "Cliente.h"

using namespace std;

Cliente::Cliente()
{
    _idCliente = 0;
    _email[0] = '\0';
    setEstado(true);
}

int Cliente::getIdCliente() const
{
    return _idCliente;
}

const char* Cliente::getEmail() const
{
    return _email;
}

void Cliente::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

void Cliente::setEmail(const std::string& email)
{
    strcpy(_email, email.c_str());
}



void Cliente::Mostrar()
{

        cout << "ID Cliente: " << _idCliente << endl;
    cout<<"=============================================="<<endl;
        Persona::Mostrar();
        cout << "Email: " << _email << endl;
    cout<<"=============================================="<<endl;

}
