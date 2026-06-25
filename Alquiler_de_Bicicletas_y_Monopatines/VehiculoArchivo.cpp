#include <iostream>
#include "vehiculo.h"
#include <cstring>
#include "VehiculoArchivo.h"
using namespace std;

VehiculoArchivo::VehiculoArchivo(const char* _nombreArchivo)
{
    strcpy(nombreArchivo,_nombreArchivo);
}

bool VehiculoArchivo::guardar(const Vehiculo &vehi)
{
    FILE *fVehi;

    fVehi=fopen(nombreArchivo,"ab");

    if(fVehi==nullptr)
    {

        return false;

    }

    fwrite(&vehi,sizeof(Vehiculo),1,fVehi);

    fclose(fVehi);

    return true;

}

Vehiculo VehiculoArchivo::leer(const int pos)
{

    Vehiculo vehi;
    FILE *fVehi;

    fVehi=fopen(nombreArchivo,"rb");

    if(fVehi==nullptr)
    {

        return vehi;

    }
    fseek(fVehi, pos * sizeof(Vehiculo), SEEK_SET);
    fread(&vehi,sizeof(Vehiculo),1,fVehi);



    fclose(fVehi);
    return vehi;
}

bool VehiculoArchivo::modificar(Vehiculo vehi, int pos)
{

    FILE *fVehi ;

    fVehi= fopen(nombreArchivo, "rb+");

    if (fVehi == nullptr)
    {
        return false;
    }

    fseek(fVehi, pos * sizeof(Vehiculo), SEEK_SET);
    bool exito = fwrite(&vehi, sizeof(Vehiculo), 1, fVehi);
    fclose(fVehi);
    return exito;



}

bool VehiculoArchivo:: bajaLogica (const int id)
{
    int posi=buscarPorId(id);


    if(posi<0)
    {
        return false;
    }
    Vehiculo vehi;
    FILE *fVehi=fopen(nombreArchivo,"rb+");

    if(fVehi==nullptr)
    {
        return false;

    }

    fseek(fVehi, posi * sizeof(Vehiculo), SEEK_SET);
    fread(&vehi,sizeof(Vehiculo),1,fVehi);


    if(vehi.getEstado()==0)
    {
        fclose(fVehi);
        return false;
    }

    vehi.setEstado(0);
    fseek(fVehi, posi * sizeof(Vehiculo), SEEK_SET);

    bool exito=fwrite(&vehi,sizeof(Vehiculo),1,fVehi);

    fclose(fVehi);

    return exito;

}

int VehiculoArchivo::buscarPorId(int id)
{

    Vehiculo vehi;

    int cantiRegistros=contarRegistros();

    for(int i=0; i<cantiRegistros; i++)
    {

        vehi=leer(i);

        if(vehi.getIdVehiculo()==id)
        {

            return i;

        }

    }

    return -1;


}


void VehiculoArchivo::listar()
{

    Vehiculo vehi;

    int cantiRegistros=contarRegistros();

    for(int i=0; i<cantiRegistros; i++)
    {
        vehi=leer(i);
        cout<<""<<endl;
        vehi.Mostrar();
        cout<<""<<endl;

    }


}


void VehiculoArchivo::listarDisponibles()
{


    Vehiculo vehi;
    int cantiRegistros=contarRegistros();



    for(int i=0; i<cantiRegistros; i++)
    {

        vehi=leer(i);
        if(vehi.getEstado()==1)
        {
            vehi.Mostrar();

        }



    }

}

void VehiculoArchivo::listarAlquilados()
{

    int cantidadRegistros=contarRegistros();
    Vehiculo vehi;

    for(int i=0; i<cantidadRegistros; i++)
    {
        vehi=leer(i);

        if(vehi.getEstado()==0)
        {

            vehi.Mostrar();

        }

    }

}


void VehiculoArchivo::listarPortipo(const string tipo)
{

    int cantidadRegistros=contarRegistros();
    Vehiculo vehi;


    for(int i=0; i<cantidadRegistros; i++)
    {
        vehi=leer(i);


        if(strcmp(vehi.getTipoVehiculo(),tipo.c_str())==0 && vehi.getEstado()==true)
        {

            vehi.Mostrar();

        }

    }

}

bool VehiculoArchivo::existeVehiculo(int id)
{
    int cantidadRegistro=contarRegistros();
    Vehiculo vehi;

    for(int i=0; i<cantidadRegistro; i++)
    {
        vehi=leer(i);

        if(vehi.getIdVehiculo()==id)
        {

            return true;
        }

    }



    return false;

}


int VehiculoArchivo::contarRegistros()
{
    FILE *fVehi = fopen(nombreArchivo, "rb");

    // Si no existe, tiene 0 registros
    if(fVehi == nullptr)
    {
        return 0;
    }

    fseek(fVehi, 0, SEEK_END);
    long contador = ftell(fVehi);
    fclose(fVehi);

    // Convertimos el resultado a int
    return (int)(contador / sizeof(Vehiculo));
}
