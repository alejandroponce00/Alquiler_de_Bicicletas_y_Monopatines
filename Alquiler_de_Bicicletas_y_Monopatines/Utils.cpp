#include "Utils.h"
#include <cstring>


float calMonto(FechaHora inicio, FechaHora fin, float precioPorBloque) {
    long minutos = fin.totalMinutos() - inicio.totalMinutos();
    if (minutos < 0) minutos = 0;
    int bloques = minutos / 15;
    if (minutos % 15 != 0) {
        bloques++;
    }
    if (bloques < 1) bloques = 1;
    return bloques * precioPorBloque;
}

FechaHora pedirFechaInicio(int tipo) {
    if (tipo == 1) {
        FechaHora fh;
        fh.setFechaActual();
        cout << "Fecha de inicio asignada automaticamente: ";
        fh.mostrar();
        cout << endl;
        return fh;
    } else if (tipo == 2) {
        int d, m, a, h, min;
        cout << "\n-- Fecha y hora de inicio --" << endl;
        cout << "Dia    : "; cin >> d;
        cout << "Mes    : "; cin >> m;
        cout << "Anio   : "; cin >> a;
        cout << "Hora   : "; cin >> h;
        cout << "Minuto : "; cin >> min;
        FechaHora fh(d, m, a, h, min);
        FechaHora actual;
        actual.setFechaActual();
        if (fh.totalMinutos() < actual.totalMinutos()) {
            cout << "ERROR: la reserva debe ser para una fecha futura." << endl;
            return actual;
        }

        return fh;
    } else {
        cout << "Opcion invalida." << endl;
        FechaHora fh;
        return fh;
    }
}

bool validarCliente(int &id) {
    ClienteArchivo clieArchi;
    int op;

    int posClie = clieArchi.buscarPorID(id);

    //  SI EL CLIENTE NO EXISTE:
    if (posClie == -1) {
        cout << "Error: el cliente no existe." << endl;
        cout << "Quiere registrar este Cliente? (Si=1 / No=0): ";
        cin >> op;

        if (op == 1) {
            ManagerMenu menu;
            menu.altaCliente(); // El Empleado lo registra normalmente por teclado

            // Averiguamos cuántos registros hay ahora en el archivo
            int totalRegistros = clieArchi.contarRegistros();

            if (totalRegistros > 0) {
                // Leemos el último cliente de la lista (posición total - 1)
                Cliente ultimoCliente = clieArchi.leer(totalRegistros - 1);

                // Le asignamos el ID autogenerado a nuestra variable del alquiler
                id = ultimoCliente.getIdCliente();


                return true;
            } else {
                cout << "Error: No se pudo completar el registro del cliente." << endl;
                return false;
            }
        }
        return false;
    }

    // SI EL CLIENTE EXISTE PERO ESTÁ DADO DE BAJA:
    Cliente clie = clieArchi.leer(posClie);
    if (clie.getEstado() == false) {
        cout << "Error: el cliente esta dado de baja." << endl;
        return false;
    }

    // SI EL CLIENTE EXISTE Y ESTÁ ACTIVO:
    return true;
}


bool validarEmpleado(int id) {
    EmpleadoArchivo archivo;
    int pos = archivo.buscarPorID(id);
    if (pos == -1) {
        cout << "Error: el empleado no existe." << endl;
        return false;
    }
    Empleado e = archivo.leer(pos);
    if (e.getEstado() == false) {
        cout << "Error: el empleado esta dado de baja." << endl;
        return false;
    }
    return true;
}

void validarEmail(string &email) {
    regex patron(R"(^[\w.+-]+@[\w-]+(\.[a-zA-Z]{2,})+$)");
    while (!regex_match(email, patron)) {
        cout << "Email incorrecto. Por favor, ingresalo de nuevo: ";
        email=cargarCadena(51); // Modifica la variable original en cada intento
    }
}

// ── Metodos de validacion para Vehiculo ─────────────────────────────────────────

string cargarCadena(int maximo) {
   string texto;

    // 1. Si la consola se tildó o falló previamente en los menús, la destrabamos
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n'); // Borra cualquier residuo que bloquee el flujo
    }

    // 2. Quitamos el peek() problemático. Si viene un Enter del menú anterior,
    // usamos una lógica estándar para consumir el salto de línea residual.
    while (cin.peek() == '\n') {
        cin.ignore();
    }

    // 3. Leemos de forma segura la línea de texto completa
    getline(cin, texto);

    // 4. Si el texto supera el tamaño máximo, obliga al reingreso
    while ((int)texto.length() > maximo - 1) {
        cout << "Maximo " << maximo - 1 << " caracteres. Reingrese: ";
        getline(cin, texto);
    }

    return texto;
}

void opVehiculo(int &op) {
    while (op != 0 && op != 1) {
        cout << "Ingresaste una opcion incorrecta, vuelva a ingresar: ";
        cin >> op;
    }
}

void validacionRodado(int &rodado, char* tipoVehiculo) {
    if (strcmp(tipoVehiculo, "Bicicleta") == 0) {
        bool valido = (rodado == 12 || rodado == 14 || rodado == 16 || rodado == 20 ||
                       rodado == 24 || rodado == 26 || rodado == 29);
        while (!valido) {
            cout << "Ingresaste un rodado no valido..." << endl;
            cout << "Reingrese el Rodado : ";
            cin >> rodado;
            valido = (rodado == 12 || rodado == 14 || rodado == 16 || rodado == 20 ||
                      rodado == 24 || rodado == 26 || rodado == 29);
        }
    } else if (strcmp(tipoVehiculo, "Monopatin Electrico") == 0) {
        bool valido = (rodado == 6 || rodado == 8 || rodado == 10);
        while (!valido) {
            cout << "Ingresaste un rodado no valido..." << endl;
            cout << "Reingrese el Rodado : ";
            cin >> rodado;
            valido = (rodado == 6 || rodado == 8 || rodado == 10);
        }
    }
}

void validarPrecio(float &precio) {
    while (precio <= 0) {
        cout << "No puede ser menor o igual a 0.." << endl;
        cout << "Reingrese el Precio : ";
        cin >> precio;
    }
}

void validarCambios(bool &cambio) {
    while (cambio != 0 && cambio != 1) {
        cout << "Ingresaste una opcion no valida..." << endl;
        cout << "Si=1 / No=0 " << endl;
        cout << "Reingrese opcion : ";
        cin >> cambio;
    }
}

bool validarVehiculo(int id){
    VehiculoArchivo vehiArchi;
    int pos = vehiArchi.buscarPorId(id);
    if (pos == -1) {
        cout << "Error: el vehiculo no existe ." << endl;
        return false;
    }
    Vehiculo vehi = vehiArchi.leer(pos);
    if (vehi.getEstado() == false) {
        cout << "Error: el vehiculo esta dado de baja o alquilado." << endl;
        return false;
    }
    return true;



}

void validarDni(string &dni, ClienteArchivo clienArchi){

   while(dni == "" || clienArchi.existeDNI(dni)){

        if(dni == "") {
            cout << "El DNI no puede estar vacio..." << endl;
        } else {
            cout << "Ingresaste un Dni ya registrado..." << endl;
        }

        cout << "Vuelve a ingresar Dni: ";
        dni = cargarCadena(11);
    }
}








