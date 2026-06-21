#pragma once
class ManagerMenu{

public:
    //menu
    void menuPrincipal();
    void menuClientes();
    void menuVehiculos();
    void menuEmpleados();
    void menuAlquileres();
    void menuInformes();
    //cliente
    void altaCliente();
    void modificarCliente();
    void bajaCliente();
    void consultaCliente();
    void listadoCliente();
    void busIdCliente();
    void busDniCliente();
    //vehiculo
    void altaVehiculo();
    void modificarVehiculo();
    void bajaVehiculo();
    void consultarExistencia();
    void listadoVehiculo();
    void busIdVehiculo();
    //alquileres
    void registrarAlquiler();
    void registrarReserva();
    void devolucion();
    void cancelarReserva();
    void listadosAlquiler();
    //empleado
    void buscarPorId();
    void listaPorTurno();









};
