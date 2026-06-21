#include "vehiculo.h"
#include <cstring>
#include <string>
#include "Utils.h"
using namespace std;

Vehiculo::Vehiculo() {}
void Vehiculo::Cargar()
{

}

void Vehiculo::Mostrar()
const{


    if(strcmp(getTipoVehiculo(),"Bicicleta"))
    {

        cout<<"Vehiculo Id : "<<getIdVehiculo()<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Tipo : "<<getTipoVehiculo()<<endl;
        cout<<"Marca :"<<getMarca()<<endl;
        cout<<"Modelo :"<<getModelo()<<endl;
        cout<<"Color :"<<getColor()<<endl;
        cout<<"Rodado :"<<getRodado()<<endl;
        cout<<"Precio:"<<getPrecio()<<endl;
        cout<<"---------------------------------"<<endl;
    }
    else if(strcmp(getTipoVehiculo(),"MonoPatin Electrico"))
    {
        cout<<"Vehiculo Id : "<<getIdVehiculo()<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Tipo : "<<getTipoVehiculo()<<endl;
        cout<<"Marca :"<<getMarca()<<endl;
        cout<<"Modelo :"<<getModelo()<<endl;
        cout<<"Color :"<<getColor()<<endl;
        cout<<"Rodado :"<<getRodado()<<endl;
        cout<<"Precio:"<<getPrecio()<<endl;
        cout<<"Cambio:"<<getCambios()<<endl;
        cout<<"Bateria :"<<getBateria()<<endl;
        cout<<"Velocidad Maxima :"<<getVelocidadMaxima()<<endl;
        cout<<"---------------------------------"<<endl;

    }
}


//setters

void Vehiculo::setIdVehiculo(int idVehiculo)//el id se lo damos con ultimoregistro+1
{
    _idVehiculo=idVehiculo;


}

void Vehiculo::setTipoVehiculo(int opciTipo)//la idea es que en el metodo cargar se den opciones nomas
{

    if(opciTipo==0)
    {

        strcpy(_tipoVehiculo,"Bicicleta");

    }
    else if(opciTipo==1)
    {

        strcpy(_tipoVehiculo,"Monopatin Electrico");
    }


}

void Vehiculo::setMarca(const string& marca)
{

    strcpy(_marca,marca.c_str());



}

void Vehiculo::setModelo(const string& modelo)
{

    strcpy(_modelo,modelo.c_str());


}

void Vehiculo::setColor(const string& color)
{
    strcpy(_color,color.c_str());


}


void Vehiculo::setRodado(int rodado)
{

    _rodado=rodado;

}

void Vehiculo:: setPrecio(float precio)
{
    _precio=precio;

}

void Vehiculo::setEstado(bool estado)
{
    _estado = estado ;
}

void Vehiculo:: setCambios(bool cambios)
{
    _cambios=cambios;
}

void Vehiculo::setBateria(const std::string& bateria)
{

    strcpy(_bateria,bateria.c_str());

}
void Vehiculo::setVelocidadMaxima(const std::string& velocidadMaxima)
{


    strcpy(_velocidadMaxima,velocidadMaxima.c_str());
}


//getters

int Vehiculo::getIdVehiculo()const
{
    return _idVehiculo;
}

const char* Vehiculo::getTipoVehiculo()const
{
    return _tipoVehiculo;
}

const char* Vehiculo::getMarca()const
{
    return _marca;
}

const char* Vehiculo::getModelo()const
{
    return _modelo;
}

const char* Vehiculo::getColor()const
{
    return _color;
}

int Vehiculo::getRodado()const
{
    return _rodado;
}

float Vehiculo::getPrecio()const
{
    return _precio;
}

bool Vehiculo::getEstado()const
{
    return _estado;
}

bool Vehiculo::getCambios()const
{
    return _cambios;
}

const char* Vehiculo::getBateria()const
{
    return _bateria;
}

const char* Vehiculo::getVelocidadMaxima()const
{
    return _velocidadMaxima;
}
