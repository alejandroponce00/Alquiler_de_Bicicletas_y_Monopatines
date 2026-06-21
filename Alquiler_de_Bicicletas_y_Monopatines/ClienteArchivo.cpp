#include "ClienteArchivo.h"
#include <cstring>
#include <string>

ClienteArchivo::ClienteArchivo() {
    strcpy(_nombreArchivo, "archivoCliente.dat");
}

bool ClienteArchivo::guardar(Cliente clien) {

    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) { cout << "Error: No se pudo abrir el archivo." << endl; return false; }
    int escribio = fwrite(&clien, sizeof (clien), 1, p);
    fclose(p);
    return escribio == 1;
}

Cliente ClienteArchivo::leer(int pos) {
    Cliente clien;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) { cout << "Error: No se pudo abrir el archivo." << endl; return clien; }
    fseek(p, pos * sizeof clien, SEEK_SET);
    fread(&clien, sizeof clien, 1, p);
    fclose(p);
    return clien;
}

bool ClienteArchivo::modificar(Cliente clien, int pos) {
    FILE *p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) { cout << "Error: No se pudo abrir el archivo." << endl; return false; }
    fseek(p, pos * sizeof clien, SEEK_SET);
    bool ok = fwrite(&clien, sizeof (clien), 1, p);
    fclose(p);
    return ok;
}


bool ClienteArchivo::bajaLogica(const int id) {
    // 1. Buscamos la posición del cliente
    int posi = buscarPorID(id);
    if (posi < 0) return false;

    // 2. Leemos el cliente de esa posición
    Cliente clie = leer(posi);

    // 3. Cambiamos el estado a falso (0)
    clie.setEstado(0);

    // 4. Abrimos el archivo, nos paramos en su lugar y sobreescribimos
    FILE *fClie = fopen(_nombreArchivo, "rb+");
    if (fClie == nullptr) return false;

    fseek(fClie, posi * sizeof(Cliente), SEEK_SET);
    bool exito = (fwrite(&clie, sizeof(Cliente), 1, fClie) == 1);

    fclose(fClie);
    return exito;
}

void ClienteArchivo::listar() {
    Cliente clien;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) { cout << "Error: No se pudo abrir el archivo." << endl; return; }
    cout << "_______ LISTADO DE CLIENTES _______" << endl;
    while (fread(&clien, sizeof (clien), 1, p) == 1) { clien.Mostrar(); cout << "___________________________________" << endl; }
    fclose(p);
}

void ClienteArchivo::listarActivos() {
    Cliente clien;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) { cout << "Error: No se pudo abrir el archivo." << endl; return; }
    cout << "_______ CLIENTES ACTIVOS _______" << endl;
    while (fread(&clien, sizeof clien, 1, p) == 1) { if (clien.getEstado()) { clien.Mostrar(); } }
    fclose(p);
}

void ClienteArchivo::listarInactivos() {
    Cliente clien;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) { cout << "Error: No se pudo abrir el archivo." << endl; return; }
    cout << "_______ CLIENTES INACTIVOS _______" << endl;
    while (fread(&clien, sizeof clien, 1, p) == 1) { if (clien.getEstado()==0) { clien.Mostrar(); } }
    fclose(p);
}

int ClienteArchivo::buscarPorID(int id) {
    Cliente clien; int pos = 0;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;
    while (fread(&clien, sizeof (clien), 1, p) == 1) {
        if (clien.getIdCliente() == id) { fclose(p); return pos; }
        pos++;
    }
    fclose(p);
    return -1;
}

int ClienteArchivo::buscarPorDNI(string dni) {
    Cliente clien; int pos = 0;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;
    while (fread(&clien, sizeof clien, 1, p) == 1) {
        if (strcmp(dni.c_str(),clien.getDni())==0) { fclose(p); return pos; }
        pos++;
    }
    fclose(p);
    return -1;
}

bool ClienteArchivo::existeDNI(string dni) {
    return buscarPorDNI(dni) != -1;
}

int ClienteArchivo::contarRegistros() {
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    long tam = ftell(p);
    fclose(p);
    return tam / sizeof(Cliente);
}
