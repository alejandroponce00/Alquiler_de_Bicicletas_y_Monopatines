#include "AlquilerArchivo.h"
#include <cstring>

AlquilerArchivo::AlquilerArchivo() {
    strcpy(_nombreArchivo, "archivoAlquiler.dat");
}

// ── GUARDAR ────────────────────────────────────────────────────────────────────
// "ab" =  agrega al final sin borrar lo existente

bool AlquilerArchivo::guardar(Alquiler alqui) {
    FILE *p = fopen(_nombreArchivo, "ab");//abre el archvo
    if (p == NULL) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return false;
    }
    bool ok = fwrite(&alqui, sizeof(Alquiler), 1, p);
    if (ok == true) {
        cout << "Alquiler guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar el alquiler." << endl;
    }
    fclose(p);
    return ok;
}

// ── LEER ───────────────────────────────────────────────────────────────────────
// "rb" = lectura binaria

Alquiler AlquilerArchivo::leer(int pos) {
    Alquiler alqui;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return alqui;
    }
    fseek(p, pos * sizeof(Alquiler), SEEK_SET);
    fread(&alqui, sizeof(Alquiler), 1, p);
    fclose(p);
    return alqui;
}

// ── MODIFICAR ──────────────────────────────────────────────────────────────────
// "r+b" = lectura/escritura binaria sin borrar el archivo

bool AlquilerArchivo::modificar(Alquiler alqui, int pos) {
    FILE *p = fopen(_nombreArchivo, "r+b");
    if (p == NULL) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return false;
    }
    fseek(p, pos * sizeof(Alquiler), SEEK_SET);
    bool ok = fwrite(&alqui, sizeof(Alquiler), 1, p);
    if (ok == false) {
       cout << "Error al modificar el alquiler." << endl;
    }
    fclose(p);
    return ok;
}

// ── LISTADOS ───────────────────────────────────────────────────────────────────

void AlquilerArchivo::listar() {
    int total = contarRegistros();
    if (total == 0) {
        cout << "No hay alquileres registrados." << endl;
        return;
    }
    cout << "\n===== LISTADO COMPLETO DE ALQUILERES =====" << endl;
    for (int i = 0; i < total; i++) {
        leer(i).mostrar();
    }
}

void AlquilerArchivo::listarActivos() {
    int total = contarRegistros();
    bool hayRegistros = false;

    cout << "\n===== ALQUILERES ACTIVOS =====" << endl;
    for (int i = 0; i < total; i++) {
        Alquiler a = leer(i);
        if (a.getEstado() == true) {
            a.mostrar();
            hayRegistros = true;
        }
    }
    if (hayRegistros == false) {
        cout << "No hay alquileres activos." << endl;
    }
}

void AlquilerArchivo::listarFinalizados() {
    int total = contarRegistros();
    bool hayRegistros = false;

    cout << "\n===== ALQUILERES FINALIZADOS =====" << endl;
    for (int i = 0; i < total; i++) {
        Alquiler a = leer(i);
        if (a.getEstado() == false) {
            a.mostrar();
            hayRegistros = true;
        }
    }
    if (hayRegistros == false) {
        cout << "No hay alquileres finalizados." << endl;
    }
}

void AlquilerArchivo::listarPorFecha(int dia, int mes, int anio) {
    int total = contarRegistros();
    bool hayRegistros = false;

    cout << "\n===== ALQUILERES POR FECHA =====" << endl;
    for (int i = 0; i < total; i++) {
        Alquiler a  = leer(i);
        FechaHora fh = a.getFechaHoraInicio();

        bool coincide = true;
        if (dia  != 0 && fh.getDia()  != dia)  coincide = false;
        if (mes  != 0 && fh.getMes()  != mes)  coincide = false;
        if (anio != 0 && fh.getAnio() != anio) coincide = false;

        if (coincide == true) {
            a.mostrar();
            hayRegistros = true;
        }
    }
    if (hayRegistros == false) {
        cout << "No se encontraron alquileres para la fecha indicada." << endl;
    }
}

void AlquilerArchivo::listarPorCliente(int idCliente) {
    int total = contarRegistros();
    bool hayRegistros = false;

    cout << "\n===== ALQUILERES DEL CLIENTE " << idCliente << " =====" << endl;
    for (int i = 0; i < total; i++) {
        Alquiler a = leer(i);
        if (a.getIdCliente() == idCliente) {
            a.mostrar();
            hayRegistros = true;
        }
    }
    if (hayRegistros == false) {
        cout << "No se encontraron alquileres para ese cliente." << endl;
    }
}

// ── BUSQUEDA ───────────────────────────────────────────────────────────────────

int AlquilerArchivo::buscarPorID(int id) {
    int total = contarRegistros();
    for (int i = 0; i < total; i++) {
        if (leer(i).getCodAlquiler() == id) {
            return i;
        }
    }
    return -1;
}

// ── UTILIDADES ─────────────────────────────────────────────────────────────────

int AlquilerArchivo::contarRegistros() {
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    long tamArchivo = ftell(p);
    fclose(p);

    if (tamArchivo <= 0) return 0;
    return (int)(tamArchivo / sizeof(Alquiler));
}
