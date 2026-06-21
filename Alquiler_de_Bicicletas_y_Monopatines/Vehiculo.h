#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Vehiculo{

private:
    int _idVehiculo;
    char _tipoVehiculo [30];
    char _marca[30];
    char  _modelo[30];
    char _color[20];
    int _rodado;
    float _precio;
    bool _estado;
    //atributo de la bici
    bool _cambios;

    //atributo del monopatin
    char _bateria [4];
    char _velocidadMaxima[4];

public:

 //constructores
   Vehiculo();

//metodos

    void Cargar();
    void Mostrar()const;

    //setters
    void setIdVehiculo(int idVehiculo);
    void setTipoVehiculo(int opciTipo);
    void setMarca(const string& marca);
    void setModelo(const string& modelo);
    void setColor(const string& color);
    void setRodado(int rodado);
    void setPrecio(float precio);
    void setEstado(bool estado);
    void setCambios(bool cambios);
    void setBateria(const string& bateria);
    void setVelocidadMaxima(const string& velocidadMaxima);
    //getters
    int getIdVehiculo()const;
    const char* getTipoVehiculo()const;
    const char* getMarca()const;
    const char* getModelo()const;
    const char* getColor()const;
    int getRodado()const;
    float getPrecio()const;
    bool getEstado()const;
    bool getCambios()const;
    const char* getBateria()const;
   const char* getVelocidadMaxima()const;


};
