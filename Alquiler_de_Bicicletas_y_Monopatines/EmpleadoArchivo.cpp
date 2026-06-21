#include "EmpleadoArchivo.h"
#include <cstring>

EmpleadoArchivo::EmpleadoArchivo()
{
    strcpy(_nombreArchivo, "archivoEmpleado.dat");
}

bool EmpleadoArchivo::guardar(Empleado empl)
{
    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
    {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return false;
    }
    bool ok = fwrite(&empl, sizeof empl, 1, p);
    fclose(p);
    return ok;
}

Empleado EmpleadoArchivo::leer(int pos)
{
    Empleado empl;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return empl;
    }
    fseek(p, pos * sizeof empl, SEEK_SET);
    fread(&empl, sizeof empl, 1, p);
    fclose(p);
    return empl;
}

void EmpleadoArchivo::listar()
{
    Empleado empl;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    cout << "_______ LISTADO DE EMPLEADOS _______" << endl;
    while (fread(&empl, sizeof empl, 1, p) == 1)
    {
        empl.Mostrar();
        cout << "____________________________________" << endl;
    }
    fclose(p);
}

void EmpleadoArchivo::listarActivos()
{
    Empleado empl;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    cout << "_______ EMPLEADOS ACTIVOS _______" << endl;
    while (fread(&empl, sizeof empl, 1, p) == 1)
    {
        if (empl.getEstado())
        {
            empl.Mostrar();
        }
    }
    fclose(p);
}

void EmpleadoArchivo::listarPorTurno(string turno)
{
    Empleado empl;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    while (fread(&empl, sizeof empl, 1, p) == 1)
    {
        if (strcmp(empl.getTurno(),turno.c_str())==0 && empl.getEstado()==true)
        {
            empl.Mostrar();
        }
    }
    fclose(p);
}

int EmpleadoArchivo::buscarPorID(int id)
{
    Empleado empl;
    int pos = 0;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;
    while (fread(&empl, sizeof empl, 1, p) == 1)
    {
        if (empl.getIdEmpleado() == id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool EmpleadoArchivo::existeEmpleado(int id)
{
    return buscarPorID(id) != -1;
}

int EmpleadoArchivo::contarRegistros()
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    long tam = ftell(p);
    fclose(p);
    return tam / sizeof(Empleado);
}
