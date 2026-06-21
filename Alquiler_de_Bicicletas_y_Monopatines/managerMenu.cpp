#include <iostream>
#include "managerMenu.h"
#include "VehiculoArchivo.h"
#include "Vehiculo.h"
#include "Utils.h"
#include "Alquiler.h"
#include "AlquilerArchivo.h"
#include <cstring>
using namespace std;

void ManagerMenu::menuPrincipal()
{
    system("cls");
    int op;
    do
    {
        system("cls");
        cout<<"-----MENU PRINCIPAL-----"<<endl;
        cout<<"1-Gestion de Alquileres"<<endl;
        cout<<"2-Gestion de Clientes"<<endl;
        cout<<"3-Gestion de Vehiculos"<<endl;
        cout<<"4-Gestion de Empleados"<<endl;
        cout<<"5-Informes"<<endl;
        cout<<"0-Salir"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {
        case 1:
            menuAlquileres();
            break;
        case 2:
            menuClientes();
            break;
        case 3:
            menuVehiculos();
            break;
        case 4:
            menuEmpleados();
            break;
        case 5:
            menuInformes();
            break;
        case 0:
            cout<<"Saliendo del sistema"<<endl;;
            break;
        default:
            cout<<"ingresaste una opcion incorrecta..."<<endl;
            system("pause");
            break;
        }
    }
    while(op!=0);

}

void ManagerMenu::menuVehiculos()
{

    VehiculoArchivo archi;
    int op;
    do
    {
        system("cls");
        cout<<"=====MENU VEHICULO====="<<endl;
        cout<<"1-Registrar Vehiculo"<<endl;
        cout<<"2-Modificar Vehiculo"<<endl;
        cout<<"3-Dar Baja"<<endl;
        cout<<"4-Consultar Existencia"<<endl;
        cout<<"5-Listado"<<endl;
        cout<<"6-Vehiculos Disponibilidad"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"======================="<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {

        case 1:
            altaVehiculo();
            break;
        case 2:
            modificarVehiculo();
            break;
        case 3:
            bajaVehiculo();
            system("pause");
            break;
        case 4:
            consultarExistencia();
            system("pause");
            break;
        case 5:
            listadoVehiculo();
            break;
        case 6:
            archi.listarDisponibles();
            system("pause");
            break;
        case 0:
            system("cls");
            cout<<"volviendo al menu principal.."<<endl;
            break;
        default:
            cout<<"Opcion no existente..."<<endl;
            break;

        }
    }
    while(op!=0);


}

void ManagerMenu::altaVehiculo()
{
    system("cls");
    VehiculoArchivo vehiArchi;
    Vehiculo vehi;


    cout<<"=====Registrar Vehiculo====="<<endl;

    int opcionVehi;
    string marca;
    string modelo;
    string color;
    int rodado;
    int idvehiculo=vehiArchi.contarRegistros()+1;
    float precio;
    bool cambio;
    string bateria;
    string velocidadmaxima;
    char tip[30]= {};
    cout<<"Registrar Nuevo Vehiculo"<<endl;
    cout<<"==================================="<<endl;
    cout<<"0=Bicicleta / 1=MonoPatin Electrico"<<endl;
    cout<<"Tipo Vehiculo : ";
    cin>>opcionVehi;
    opVehiculo(opcionVehi);
    vehi.setTipoVehiculo(opcionVehi);

    if(opcionVehi==0) //Bicicleta
    {
        cout<<"==================================="<<endl;
        cout<<"Id Vehiculo : "<<idvehiculo<<endl;
        vehi.setIdVehiculo(idvehiculo);
        cout<<"Marca : ";
        marca=cargarCadena(30);
        vehi.setMarca(marca);
        cout<<"Modelo : ";
        modelo=cargarCadena(30);
        vehi.setModelo(modelo);
        cout<<"Color : ";
        color=cargarCadena(20);
        vehi.setColor(color);
        cout<<"-Rodados : 12/14/16/20/24/26/29"<<endl;
        cout<<"Rodado : ";
        cin>>rodado;
        strcpy(tip,vehi.getTipoVehiculo());
        validacionRodado(rodado,tip);
        vehi.setRodado(rodado);
        cout<<"Precio : ";
        cin>>precio;
        validarPrecio(precio);
        vehi.setPrecio(precio);
        cout<<"- Si=1 / No=0 -"<<endl;
        cout<<"Cambios : ";
        cin>>cambio;
        validarCambios(cambio);
        vehi.setCambios(cambio);
        vehi.setBateria("0");
        vehi.setVelocidadMaxima("0");
        vehi.setEstado(1);

    }
    else if(opcionVehi==1)  //Monopatin Electrico
    {
        cout<<"==================================="<<endl;
        cout<<"Id Vehiculo : "<<idvehiculo<<endl;
        vehi.setIdVehiculo(idvehiculo);
        cout<<"Marca : ";
        marca=cargarCadena(30);
        vehi.setMarca(marca);
        cout<<"Modelo : ";
        modelo=cargarCadena(30);
        vehi.setModelo(modelo);
        cout<<"Color : ";
        color=cargarCadena(20);
        vehi.setColor(color);
        cout<<"-Rodados : 6/8/10 "<<endl;
        cout<<"Rodado : ";
        cin>>rodado;
        strcpy(tip,vehi.getTipoVehiculo());
        validacionRodado(rodado,tip);
        vehi.setRodado(rodado);
        cout<<"Precio : ";
        cin>>precio;
        validarPrecio(precio);
        vehi.setPrecio(precio);
        vehi.setCambios(false);
        cin.ignore();
        cout<<"Bateria : ";
        bateria=cargarCadena(4);
        vehi.setBateria(bateria);
        cout<<"Velocidad Maxima : ";
        velocidadmaxima=cargarCadena(4);
        vehi.setVelocidadMaxima(velocidadmaxima);
        vehi.setEstado(1);
    }

    bool sn;
    cout<<"Queres registrar el vehiculo? "<<"Si=1/No=0"<<endl;
    cin>>sn;
    cin.ignore();
    if(sn)
    {
        if(vehiArchi.guardar(vehi))
        {

            cout<<"Registrado correctamente"<<endl;
            return;

        }
        else
        {

            cout<<"No se Registrado correctamente"<<endl;
            return;
        }

    }
    else if(!sn)
    {

        cout<<"Registro no realizado"<<endl;
        cout<<"volviendo al menu vehiculos..."<<endl;

        system("cls");
        return;

    }

}

void ManagerMenu::listadoVehiculo()
{
    system("cls");
    VehiculoArchivo vehiArchi;
    int op;
    string tipo;

    do
    {
        system("cls");
        cout<<"=====Menu Listados====="<<endl;
        cout<<"1-Listar"<<endl;
        cout<<"2-Listar Disponibles"<<endl;
        cout<<"3-Listar Alquilados"<<endl;
        cout<<"4-Listar Por Tipo"<<endl;
        cout<<"5-Buscar por Id"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"========================"<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {
        case 1:
            vehiArchi.listar();
            system("pause");
            break;
        case 2:
            vehiArchi.listarDisponibles();
            system("pause");
            break;
        case 3:
            vehiArchi.listarAlquilados();
            system("pause");
            break;
        case 4:
            cout<<"Ingrese tipo : ";
            tipo=cargarCadena(20);
            vehiArchi.listarPortipo(tipo);
            system("pause");
            break;
        case 5:
            busIdVehiculo();
            break;
        case 0:
            break;
        default:
            cout<<"Ingresaste un opcion no valida..."<<endl;
            system("pause");
            break;

        }
    }
    while(op!=0);




}

void ManagerMenu::busIdVehiculo()
{

    int id;
    cout<<"Ingrese Id Del Vehiculo: ";
    cin>>id;
    Vehiculo vehi;
    VehiculoArchivo vehiArchi;
    int pos=vehiArchi.buscarPorId(id);
    vehi=vehiArchi.leer(pos);
    vehi.Mostrar();
    system("pause");
}



void ManagerMenu::consultarExistencia()
{
    int nu;
    cout<<"ingrese Id del Vehiculo:";
    cin>>nu;
    VehiculoArchivo vehi;
    bool existe=vehi.existeVehiculo(nu);
    if(existe)
    {
        cout<<"el Vehiculo existe"<<endl;
    }
    else
    {
        cout<<"el Vehiculo no existe"<<endl;
    }


}

void ManagerMenu::modificarVehiculo()
{
    system("cls");
    VehiculoArchivo vehiArchi;
    Vehiculo vehi;
    int id;
    string marca;
    string modelo;
    string color;
    int rodado;
    float precio;
    bool cambio;
    string bateria;
    string velocidadmaxima;
    char tip[30]= {};


    cout<<"Ingrese Id del Vehiculo : ";
    cin>>id;
    int pos=vehiArchi.buscarPorId(id);

    if (pos == -1)
    {
        cout << "Vehiculo no encontrado." << endl;
        return;
    }


    vehi=vehiArchi.leer(pos);
    bool op;


    cout << "Editar -> 1=Campos especificos / 0=Dar De Alta" << endl;
    cout << "Seleccione una opcion : ";
    cin >> op;

    if (op ==1)
    {
        system("cls");

        if (strcmp(vehi.getTipoVehiculo(),"Bicicleta")==0)
        {
            system("cls");
            int subOp;
            cout << "================================" << endl;
            cout << "Id Vehiculo : " << vehi.getIdVehiculo() << endl;
            cout << "Tipo : " << vehi.getTipoVehiculo() << endl;
            cout << "===============================" << endl;
            cout << "1 - Editar Marca (Actual: " << vehi.getMarca() << ")" << endl;
            cout << "2 - Editar Modelo (Actual: " << vehi.getModelo() << ")" << endl;
            cout << "3 - Editar Color (Actual: " << vehi.getColor() << ")" << endl;
            cout << "4 - Editar Rodado (Actual: " << vehi.getRodado() << ")" << endl;
            cout << "5 - Editar Precio (Actual: " << vehi.getPrecio() << ")" << endl;
            cout << "6 - Editar Cambios (Actual: " << vehi.getCambios() << ")" << endl;
            cout << "Seleccione que campo modificar: ";
            cin >> subOp;

            // Evaluamos solo la opción elegida
            switch (subOp)
            {
            case 1:
                cout << "Nueva Marca : ";
                marca = cargarCadena(30);
                vehi.setMarca(marca);
                break;
            case 2:
                cout << "Nuevo Modelo : ";
                modelo =cargarCadena(30);
                vehi.setModelo(modelo);
                break;
            case 3:
                cout << "Nuevo Color : ";
                color = cargarCadena(20);
                vehi.setColor(color);
                break;
            case 4:
                cout << "-Rodados : 12/14/16/20/24/26/29" << endl;
                cout << "Nuevo Rodado : ";
                cin >> rodado;
                strcpy(tip, vehi.getTipoVehiculo());
                validacionRodado(rodado, tip);
                vehi.setRodado(rodado);
                break;
            case 5:
                cout << "Nuevo Precio : ";
                cin >> precio;
                validarPrecio(precio);
                vehi.setPrecio(precio);
                break;
            case 6:
                cout << "- Si=1 / No=0 -" << endl;
                cout << "Nuevos Cambios : ";
                cin >> cambio;
                validarCambios(cambio);
                vehi.setCambios(cambio);
                break;
            default:
                cout << "Opcion no valida." << endl;
                return; // Salimos si la opción es incorrecta para no guardar nada viejo
            }

            // Valores por defecto
            vehi.setBateria("0");
            vehi.setVelocidadMaxima("0");
            vehi.setEstado(1);
        }
        else if (strcmp(vehi.getTipoVehiculo(),"Monopatin Electrico")==0)
        {
            int subOp;
            cout << "===================================" << endl;
            cout << "Id Vehiculo : " << vehi.getIdVehiculo() << endl;
            cout << "Tipo : " << vehi.getTipoVehiculo() << endl;
            cout << "===================================-" << endl;
            cout << "1 - Editar Marca (Actual: " << vehi.getMarca() << ")" << endl;
            cout << "2 - Editar Modelo (Actual: " << vehi.getModelo() << ")" << endl;
            cout << "3 - Editar Color (Actual: " << vehi.getColor() << ")" << endl;
            cout << "4 - Editar Rodado (Actual: " << vehi.getRodado() << ")" << endl;
            cout << "5 - Editar Precio (Actual: " << vehi.getPrecio() << ")" << endl;
            cout << "6 - Editar Bateria (Actual: " << vehi.getBateria() << ")" << endl;
            cout << "7 - Editar Vel. Maxima (Actual: " << vehi.getVelocidadMaxima() << ")" << endl;
            cout << "Seleccione que campo modificar: ";
            cin >> subOp;

            switch (subOp)
            {
            case 1:
                cout << "Nueva Marca : ";
                marca = cargarCadena(30);
                vehi.setMarca(marca);
                break;
            case 2:
                cout << "Nuevo Modelo : ";
                modelo = cargarCadena(30);
                vehi.setModelo(modelo);
                break;
            case 3:
                cout << "Nuevo Color : ";
                color = cargarCadena(20);
                vehi.setColor(color);
                break;
            case 4:
                cout << "-Rodados : 6/8/10 " << endl;
                cout << "Nuevo Rodado : ";
                cin >> rodado;
                strcpy(tip, vehi.getTipoVehiculo());
                validacionRodado(rodado, tip);
                vehi.setRodado(rodado);
                break;
            case 5:
                cout << "Nuevo Precio : ";
                cin >> precio;
                validarPrecio(precio);
                vehi.setPrecio(precio);
                break;
            case 6:
                cout << "Nueva Bateria : ";
                bateria = cargarCadena(4);
                vehi.setBateria(bateria);
                break;
            case 7:
                cout << "Nueva Velocidad Maxima : ";
                velocidadmaxima = cargarCadena(4);
                vehi.setVelocidadMaxima(velocidadmaxima);
                break;
            default:
                cout << "Opcion no valida." << endl;
                return;
            }
            // Valores por defecto fijos del monopatín
            vehi.setCambios(false);
            vehi.setEstado(1);
        }
    }
    else if (op == 0)
    {
        // Acá ponés tu lógica para cambiar solo el estado

        cout << "Cambio de Estado a Activo : ";
        if(vehi.getEstado()==0)
        {

            vehi.setEstado(1);

        }
        else
        {

            cout<<"El Vehiculo Ya Se Encuentra Activo";
            system("pause");
            return;
        }

    }




    bool sn;
    cout<<"Queres Guardar el Vehiculo Modificado? "<<"Si=1/No=0"<<endl;
    cin>>sn;
    if(sn==1)
    {
        if(vehiArchi.modificar(vehi,pos))
        {

            cout<<"Vehiculo Modificado Guardado Correctamente"<<endl;
            system("pause");

        }
        else
        {

            cout<<"El Vehiculo Modificado No Se Guardado "<<endl;
            system("pause");
        }

    }
    else if(sn==0)
    {

        cout<<"Registro no realizado"<<endl;
        cout<<"volviendo al menu vehiculos..."<<endl;

        system("cls");
        return;

    }


}

void ManagerMenu::bajaVehiculo()
{

    VehiculoArchivo vehiArchi;

    int id;

    cout<<"Ingrese Id del Vehiculo : ";
    cin>>id;
    bool exito=vehiArchi.bajaLogica(id);

    if(exito)
    {
        cout<<"Vehiculo dado de baja correctamente"<<endl;

    }
    else
    {

        cout<<"el vehiculo ya se encuentra dado de baja"<<endl;

    }




}


void ManagerMenu::menuInformes()
{
    int op;

    do
    {
        system("cls");
        cout<<"=====Menu Informe====="<<endl;
        cout<<"1-Recaudacion Mensual"<<endl;
        cout<<"2-Vehiculo Mas Alquilado"<<endl;
        cout<<"3-Cliente Con Mayor Alquileres"<<endl;
        cout<<"4-Cantidad De Alquileres Por Tipo Vehiculo"<<endl;
        cout<<"5-Recaudacion Por Tipo Vehiculo"<<endl;
        cout<<"6-Top 5 Clientes"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"======================="<<endl;
        cout<<"Ingrese Opcion : ";



    }
    while(op!=0);


}

void ManagerMenu::menuAlquileres()
{
    AlquilerArchivo archi;
    int op;
    do
    {
        system("cls");
        cout<<"=====MENU ALQUILERES====="<<endl;
        cout<<"1-Registro de alquiler"<<endl;
        cout<<"2-Reserva de alquiler"<<endl;
        cout<<"3-Devolucion"<<endl;
        cout<<"4-Cancelacion de reserva"<<endl;
        cout<<"5-Listado de alquileres"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"=========================="<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {
        case 1:
            registrarAlquiler();
            system("pause");
            break;
        case 2:
            registrarReserva();
            system("pause");
            break;
        case 3:
            devolucion();
            system("pause");
            break;
        case 4:
            cancelarReserva();
            system("pause");
            break;
        case 5:
            listadosAlquiler();

            break;
        case 0:
            cout<<"volviendo al menu principal.."<<endl;
            break;
        default:
            cout<<"Opcion no existente..."<<endl;
            system("pause");
            break;
        }
    }
    while(op!=0);
}

void ManagerMenu::listadosAlquiler()
{
    AlquilerArchivo archi;

    int subop;

    do
    {
        system("cls");
        cout<<"=====MENU LISTADO ALQUILER====="<<endl;;
        cout<<"1-Todos"<<endl;
        cout<<"2-Activos"<<endl;
        cout<<"3-Finalizados"<<endl;
        cout<<"4-Por fecha"<<endl;
        cout<<"5-Por cliente"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"================================"<<endl;
        cout<<"Ingrese Opcion : ";

        cin>>subop;
        switch(subop)
        {
        case 1:
            archi.listar();
            system("pause");
            break;
        case 2:
            archi.listarActivos();
            system("pause");
            break;
        case 3:
            archi.listarFinalizados();
            system("pause");
            break;
        case 4:
        {
            int d, m, a;
            cout<<"Dia  (0=cualquiera): ";
            cin>>d;
            cout<<"Mes  (0=cualquiera): ";
            cin>>m;
            cout<<"Anio (0=cualquiera): ";
            cin>>a;
            archi.listarPorFecha(d, m, a);
            system("pause");
            break;
        }
        case 5:
        {
            int id;
            cout<<"ID cliente: ";
            cin>>id;
            archi.listarPorCliente(id);
            system("pause");
            break;
        }
        case 0:
            system("cls");
            cout<<"volviendo al menu principal.."<<endl;
            break;
        default:
            cout<<"Opcion no valida."<<endl;

            system("pause");
            break;

        }

    }
    while(subop!=0);

}

void ManagerMenu::registrarAlquiler()
{
    system("cls");
    AlquilerArchivo archi;
    ClienteArchivo clienArchi;
    Cliente clien;
    VehiculoArchivo vehiArchi;
    Vehiculo vehi;
    int idCliente, idEmpleado,idAut;
    cout<<"=====Vehiculos Disponibles====="<<endl;
    vehiArchi.listarDisponibles();
    cout<<endl;
    cout<<"Cod Alquiler : "<<archi.contarRegistros()+1<<endl;
    cout<<"=====Registro de Alquiler====="<<endl;
    cout<<"ID cliente  : ";
    cin>>idCliente;
    cout<<"ID empleado : ";
    cin>>idEmpleado;
    cout << "ID vehiculo : ";
    cin >> idAut;

    ///Trae el Cliente en base al id
    int posClien=clienArchi.buscarPorID(idCliente);
    clien=clienArchi.leer(posClien);

    ///Trae el Vehiculo en base al id
    int posVehi=vehiArchi.buscarPorId(idAut);
    vehi=vehiArchi.leer(posVehi);


    if(validarCliente(idCliente) && validarEmpleado(idEmpleado)&& validarVehiculo(idAut))
    {

        Alquiler a;
        a.setCodAlquiler(archi.contarRegistros()+1);
        a.setIdCliente(idCliente);
        a.setIdEmpleado(idEmpleado);



        a.setIdVehiculo(idAut);

        a.setFechaHoraInicio(pedirFechaInicio(1));

        a.setEstado(true);

        a.setMontoTotal(0);

        clien.setEstado(0);
        vehi.setEstado(0);

        int sn;
        cout<<"Queres registrar el alquiler?"<<"Si=1/No=0"<<endl;
        cin>>sn;
        cin.ignore();
        if(sn)
        {
            if(archi.guardar(a))
            {
                clienArchi.modificar(clien,posClien);
                vehiArchi.modificar(vehi,posVehi);
                cout<<"Alquiler registrado correctamente."<<endl;
            }
            else
            {
                cout<<"No se pudo registrar el alquiler."<<endl;
            }
        }
        else if(!sn)
        {

            cout<<"Registro no realizado"<<endl;
            cout<<"volviendo al menu alquiler..."<<endl;

            system("cls");
            return;

        }
    }
}

void ManagerMenu::registrarReserva()
{
    system("cls");
    AlquilerArchivo archi;
    ClienteArchivo clienArchi;
    Cliente clien;
    VehiculoArchivo vehiArchi;
    Vehiculo vehi;
    int idCliente, idEmpleado,idAut;

    cout<<"Cod. de Reserva : "<<archi.contarRegistros()+1<<endl;
    cout<<"=====Reserva de Alquiler====="<<endl;
    cout<<"ID cliente  : ";
    cin>>idCliente;
    cout<<"ID empleado : ";
    cin>>idEmpleado;
    cout << "ID vehiculo : ";
    cin >> idAut;
    ///Trae el Cliente en base al id
    int posClien=clienArchi.buscarPorID(idCliente);
    clien=clienArchi.leer(posClien);
    ///Trae el Vehiculo en base al id
    int posVehi=vehiArchi.buscarPorId(idAut);
    vehi=vehiArchi.leer(posVehi);

    if(validarCliente(idCliente) && validarEmpleado(idEmpleado))
    {
        Alquiler a;
        a.setCodAlquiler(archi.contarRegistros()+1);
        a.setIdCliente(idCliente);
        a.setIdEmpleado(idEmpleado);

        a.setIdVehiculo(idAut);

        a.setFechaHoraInicio(pedirFechaInicio(2));

        a.setEstado(true);

        a.setMontoTotal(0);


        clien.setEstado(0);
        vehi.setEstado(0);

        int sn;
        cout<<"Queres registrar el alquiler?"<<"Si=1/No=0"<<endl;
        cin>>sn;
        cin.ignore();
        if(sn)
        {
            if(archi.guardar(a))
            {
                clienArchi.modificar(clien,posClien);
                vehiArchi.modificar(vehi,posVehi);
                cout<<"Alquiler registrado correctamente."<<endl;
            }
            else
            {
                cout<<"No se pudo registrar el alquiler."<<endl;
            }
        }
        else if(!sn)
        {

            cout<<"Registro no realizado"<<endl;
            cout<<"volviendo al menu alquiler..."<<endl;

            system("cls");
            return;

        }
    }
}

void ManagerMenu::devolucion()
{
    system("cls");
    AlquilerArchivo archi;
    ClienteArchivo clienArchi;
    Cliente clien;
    ///
    Vehiculo vehi;
    VehiculoArchivo vehiArchi;
    ///
    int id;
    float precio;


    cout<<"=====Devolucion====="<<endl;
    cout<<"Codigo de alquiler a devolver: ";
    cin>>id;
    int pos = archi.buscarPorID(id);

    if(pos == -1)
    {
        cout<<"No se encontro el alquiler."<<endl;
        return;
    }


    Alquiler a = archi.leer(pos);

    if(a.getEstado() == false)
    {
        cout<<"El alquiler ya esta finalizado."<<endl;
        return;
    }
    ///////////Trae al cliente por su id//////////////
    int idClien=a.getIdCliente();
    int posClien=clienArchi.buscarPorID(idClien);
    clien=clienArchi.leer(posClien);
    /////////////Trae al Vehiculo por su id///////////
    int idAut=a.getIdVehiculo();
    int posVehi=vehiArchi.buscarPorId(idAut);
    vehi=vehiArchi.leer(posVehi);

    FechaHora fin;
    fin.setFechaActual();
    cout<<"Precio por bloque (15 min): ";
    ///
    vehi= vehiArchi.leer(posVehi);
    precio= vehi.getPrecio();
    cout<<precio<<endl;
    ///
    a.setFechaHoraFin(fin);
    a.calcularMonto(precio);
    a.setEstado(false);
    clien.setEstado(1);
    vehi.setEstado(1);
    archi.modificar(a, pos);
    clienArchi.modificar(clien,posClien);
    vehiArchi.modificar(vehi,posVehi);
    cout<<"=== DEVOLUCION REGISTRADA ==="<<endl;
    a.mostrar();
}

void ManagerMenu::cancelarReserva()
{
    system("cls");
    AlquilerArchivo archi;
    ClienteArchivo clienArchi;
    Cliente clien;
    VehiculoArchivo vehiArchi;
    Vehiculo vehi;
    int id;
    float precio;

    cout<<"=====Cancelacion de Reserva====="<<endl;
    cout<<"Codigo de reserva a cancelar: ";
    cin>>id;
    int pos = archi.buscarPorID(id);

    if(pos == -1)
    {
        cout<<"No se encontro el alquiler."<<endl;
        return;
    }

    Alquiler a = archi.leer(pos);
    ///////Trae al cliente por el id/////////
    int idClien=a.getIdCliente();
    int posClien=clienArchi.buscarPorID(idClien);
    clien=clienArchi.leer(posClien);

    //////Trae al vehiculo por el id/////////
    int idAut=a.getIdVehiculo();
    int posVehi=vehiArchi.buscarPorId(idAut);
    vehi=vehiArchi.leer(posVehi);


    if(a.getEstado() == false)
    {
        cout<<"La reserva ya esta finalizada."<<endl;
        return;
    }

    FechaHora fin = a.getFechaHoraInicio();
    a.setFechaHoraFin(fin);
    cout<<"Precio por bloque (15 min): ";
    vehi= vehiArchi.leer(posVehi);
    precio= vehi.getPrecio();
    cout<<precio<<endl;

    a.calcularMonto(precio);
    a.setEstado(false);
    clien.setEstado(1);
    vehi.setEstado(1);
    archi.modificar(a, pos);
    clienArchi.modificar(clien,posClien);
    vehiArchi.modificar(vehi,posVehi);
    cout<<"=== CANCELACION REGISTRADA ==="<<endl;
    a.mostrar();
}


void ManagerMenu::menuClientes()
{

    ClienteArchivo clienArchi;
    int op;
    do
    {
        system("cls");
        cout<<"=====MENU CLIENTE====="<<endl;
        cout<<"1-Registrar Cliente"<<endl;
        cout<<"2-Modificar Cliente"<<endl;
        cout<<"3-Baja Cliente"<<endl;
        cout<<"4-Consulta"<<endl;
        cout<<"5-Listados"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"======================="<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {

        case 1:
            altaCliente();

            break;
        case 2:
            modificarCliente();
            break;
        case 3:
            bajaCliente();
            system("pause");
            break;
        case 4:
            consultaCliente();
            system("pause");
            break;
        case 5:
            listadoCliente();
            system("pause");
            break;
        case 0:
            system("cls");
            cout<<"volviendo al menu principal.."<<endl;
            break;
        default:
            cout<<"Opcion no existente..."<<endl;
            break;

        }
    }
    while(op!=0);


}



void ManagerMenu::altaCliente()
{
    system("cls");

    string nombre,apellido,dni,telefono,direccion,email;
    ClienteArchivo clienArchi;
    Cliente clien;
    cout<<"=====Registrar Cliente====="<<endl;
    cout<<"Id Cliente : "<<clienArchi.contarRegistros()+1<<endl;
    clien.setIdCliente(clienArchi.contarRegistros()+1);
    cout<<"Nombre : ";
    nombre=cargarCadena(40);
    clien.setNombre(nombre);
    cout<<"Apellido : ";
    apellido=cargarCadena(40);
    clien.setApellido(apellido);
    cout<<"Dni : ";
    dni=cargarCadena(11);
    validarDni(dni,clienArchi);
    clien.setDni(dni);
    cout<<"Telefono : ";
    telefono=cargarCadena(11);
    clien.setTelefono(telefono);
    cout<<"Direccion : ";
    direccion=cargarCadena(100);
    clien.setDireccion(direccion);
    cout<<"Email : ";
    email=cargarCadena(51);
    validarEmail(email);
    clien.setEmail(email);
    cout<<"============================"<<endl;
    int sn;

    cout<<"Queres registrar al Cliente? "<<"Si=1/No=0"<<endl;
    cin>>sn;
    cin.ignore();
    if(sn)
    {
        if(clienArchi.guardar(clien))
        {

            cout<<"Registrado correctamente"<<endl;
            system("pause");
            return;
        }
        else
        {

            cout<<"No se Registrado correctamente"<<endl;
            system("pause");
            return;
        }


    }
    else if(!sn)
    {

        cout<<"Registro no realizado"<<endl;
        cout<<"volviendo al menu cliente..."<<endl;

        system("cls");
        return;

    }

}

void ManagerMenu::modificarCliente()
{
    string nombre,apellido,dni,telefono,direccion,email;
    int id;
    bool existe;
    system("cls");
    ClienteArchivo clienArchi;
    Cliente clien;

    cout<<"Ingrese Id del Cliente : ";
    cin>>id;
    int posClien=clienArchi.buscarPorID(id);

    if (posClien == -1)
    {
        cout << "Cliente no encontrado." << endl;
        return;
    }


    clien=clienArchi.leer(posClien);
    bool op;


    cout << "Editar -> 1=Campos especificos / 0=Dar De Alta" << endl;
    cout << "Seleccione una opcion : ";
    cin >> op;

    if(op==1)
    {

        system("cls");
        int subOp;
        cout << "================================" << endl;
        cout << "Id Cliente : " << clien.getIdCliente() << endl;
        cout << "===============================" << endl;
        cout << "1 - Editar Nombre (Actual: " << clien.getNombre() << ")" << endl;
        cout << "2 - Editar Apellido (Actual: " << clien.getApellido() << ")" << endl;
        cout << "3 - Editar Dni (Actual: " << clien.getDni() << ")" << endl;
        cout << "4 - Editar Telefono (Actual: " << clien.getTelefono() << ")" << endl;
        cout << "5 - Editar Direccion  (Actual: " << clien.getDireccion() << ")" << endl;
        cout << "6 - Editar Emails (Actual: " << clien.getEmail() << ")" << endl;
        cout << "0 - Volver"<<endl;
        cout << "Seleccione que campo modificar: ";
        cin >> subOp;

        // Evaluamos solo la opción elegida
        switch (subOp)
        {
        case 1:
            cout << "Nuevo Nombre : ";
            nombre = cargarCadena(40);
            clien.setNombre(nombre);
            break;
        case 2:
            cout << "Nuevo Apellido : ";
            apellido =cargarCadena(40);
            clien.setApellido(apellido);
            break;
        case 3:
            cout << "Nuevo Dni : ";
            dni=cargarCadena(11);

            validarDni(dni,clienArchi);
            clien.setDni(dni);
            break;
        case 4:
            cout << "Nuevo Telefono : ";
            telefono=cargarCadena(11);
            clien.setTelefono(telefono);
            break;
        case 5:
            cout << "Nuevo Dirrecion : ";
            direccion=cargarCadena(100);
            clien.setDireccion(direccion);
            break;
        case 6:
            cout << "Nuevos Email : ";
            email=cargarCadena(51);
            validarEmail(email);
            clien.setEmail(email);
            break;
        default:
            cout << "Opcion no valida." << endl;
            return;
        }


    }
    else if(op == 0)
    {


        cout << "Cambio de Estado a Activo : "<<endl;
        if(clien.getEstado()==0)
        {

            clien.setEstado(1);


        }
        else
        {

            cout<<"El Cliente Ya Se Encuentra Activo"<<endl;
            system("pause");
            return;
        }

    }

    bool sn;
    cout<<"Queres Guardar el Cliente Modificado? "<<"Si=1/No=0"<<endl;
    cin>>sn;
    if(sn==1)
    {
        if(clienArchi.modificar(clien,posClien))
        {

            cout<<"Cliente Modificado Guardado Correctamente"<<endl;
            system("pause");

        }
        else
        {

            cout<<"El Cliente Modificado No Se Guardado "<<endl;
            system("pause");
        }

    }
    else if(sn==0)
    {

        cout<<"Registro no realizado"<<endl;
        cout<<"volviendo al menu Cliente..."<<endl;

        system("cls");
        return;

    }







}


void ManagerMenu::bajaCliente()
{

    ClienteArchivo clienArchi;
    int id;

    cout<<"Ingrese Id del Cliente : ";
    cin>>id;
    bool exito=clienArchi.bajaLogica(id);

    if(exito)
    {
        cout<<"Cliente dado de baja correctamente"<<endl;

    }
    else
    {

        cout<<"el Cliente ya se encuentra dado de baja"<<endl;

    }




}

void ManagerMenu:: consultaCliente()
{

    int op;

    do
    {
        system("cls");
        cout<<"=====MENU CONSULTA CLIENTE====="<<endl;;
        cout<<"1-Buscar Por Id"<<endl;
        cout<<"2-Buscar Por Dni"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"================================"<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {
        case 1:
            busIdCliente();
            break;
        case 2:
            busDniCliente();
            break;
        case 0:
            system("cls");
            cout<<"volviendo al menu principal.."<<endl;
            break;
            cout<<"Opcion no existente..."<<endl;
            break;
        }
    }
    while(op!=0);


}

void ManagerMenu::busDniCliente()
{

    string dni;
    cout<<"Ingrese Dni Del Cliente: ";
    cin>>dni;
    Cliente clie;
    ClienteArchivo clieArchi;
    int pos=clieArchi.buscarPorDNI(dni);
    clie=clieArchi.leer(pos);
    clie.Mostrar();
    system("pause");
}


void ManagerMenu::busIdCliente()
{

    int id;
    cout<<"Ingrese Id Del Cliente: ";
    cin>>id;
    Cliente clie;
    ClienteArchivo clieArchi;
    int pos=clieArchi.buscarPorID(id);
    clie=clieArchi.leer(pos);
    clie.Mostrar();
    system("pause");


}


void ManagerMenu::listadoCliente()
{

    ClienteArchivo clieArchi;
    int op;

    do
    {
        system("cls");
        cout<<"=====MENU CONSULTA CLIENTE====="<<endl;;
        cout<<"1-Listar Todos"<<endl;
        cout<<"2-Listar Activos"<<endl;
        cout<<"3-Listar No Activos"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"================================"<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {
        case 1:
            clieArchi.listar();

            system("pause");
            break;
        case 2:
            clieArchi.listarActivos();
            system("pause");
            break;
        case 3:
            clieArchi.listarInactivos();
            system("pause");
            break;
        case 0:
            system("cls");
            cout<<"volviendo al menu principal.."<<endl;

            break;
            cout<<"Opcion no existente..."<<endl;
            break;
        }
    }
    while(op!=0);


}


void ManagerMenu::menuEmpleados()
{

    EmpleadoArchivo empArchi;

    int op;

    do
    {
        system("cls");
        cout<<"=====MENU EMPLEADO====="<<endl;;
        cout<<"1-Buscar por Id"<<endl;
        cout<<"2-Listado Empleados"<<endl;
        cout<<"3-Empleados Activos"<<endl;
        cout<<"4-Listar Por Turno"<<endl;
        cout<<"0-Volver"<<endl;
        cout<<"======================="<<endl;
        cout<<"Ingrese Opcion : ";
        cin>>op;

        switch(op)
        {
        case 1:
            buscarPorId();
            system("pause");
            break;
        case 2:empArchi.listar();
            system("pause");
            break;
        case 3:empArchi.listarActivos();
            system("pause");
            break;
            case 4:listaPorTurno();
            system("pause");
            break;
        case 0:

            system("cls");
            cout<<"volviendo al menu principal.."<<endl;

            break;
            cout<<"Opcion no existente..."<<endl;
            break;
        }
    }
    while(op!=0);




}

void ManagerMenu::buscarPorId()
{

    EmpleadoArchivo empArchi;
    Empleado empl;
    int id;
    cout<<"Ingrese id del Empleado:"<<endl;
    cin>>id;
    int posEmple=empArchi.buscarPorID(id);
    empl=empArchi.leer(posEmple);
    empl.Mostrar();

}


void ManagerMenu::listaPorTurno(){

    EmpleadoArchivo empArchi;
    Empleado empl;
    string turno;
    cout<<"Ingrese El Turno : "<<" Mañana/Tarde "<<endl;
    turno=cargarCadena(8);
    empArchi.listarPorTurno(turno);


}
