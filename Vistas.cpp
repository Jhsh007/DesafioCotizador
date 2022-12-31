#include "Vistas.h"
#include <iostream>
#include "Tienda.h"
#include "Vendedor.h"

void Vistas::CrearMenuPrincipal(Tienda* t, Vendedor* v)
{
    CrearBanner("MEN\u00da PRINCIPAL");
    std::cout << t->GetNombre() << " | " << t->GetDireccion() << "\n";
    std::cout << "---------------------------------------------\n";
    std::cout << v->GetNombre() << " " << v->GetApellido() << " | " << v->GetCodigo() << "\n";
    std::cout << "---------------------------------------------\n\n";
    std::cout << "SELECCIONE UNA OPCI\u00D3N DEL MEN\u00da :\n\n";
    std::cout << "1) Historial de Cotizaciones \n";
    std::cout << "2) Realizar Cotizaci\u00f3n\n";
    std::cout << "3) Salir\n";
}

void Vistas::CrearMenuHistorial(std::vector<Cotizacion*> cotizaciones)
{
    CrearBanner("HISTORIAL DE COTIZACIONES");
    std::cout << "Presiona 3 para volver al menú principal\n";
    std::cout << "---------------------------------------------\n";
}

void Vistas::CrearMenuCotizacion()
{
    CrearBanner("COTIZAR");
    std::cout << "Presiona 3 para volver al menú principal o h para ver el historial de cotizaciones\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "PASO 1: Selecciona la prenda a cotizar:\n";
    std::cout << "1) Camisa\n";
    std::cout << "2) Pantalon\n";
    std::cout << "---------------------------------------------\n";
}

void Vistas::CrearMenuSeleccion(int tipo)
{
    if (tipo == 1) {
        CrearBanner("COTIZAR");
        std::cout << "Presiona 3 para volver al menú principal o h para ver el historial de cotizaciones\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "PASO 2.a: La camisa a cotizar, ¿Es manga corta?:\n";
        std::cout << "1) Sí\n";
        std::cout << "2) No\n";
        std::cout << "---------------------------------------------\n";
    }
    else if (tipo == 2) {
        CrearBanner("COTIZAR");
        std::cout << "Presiona 3 para volver al menú principal o h para ver el historial de cotizaciones\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "PASO 2: El pantalón a cotizar, ¿Es Chupín?:\n";
        std::cout << "1) Sí\n";
        std::cout << "2) No\n";
        std::cout << "---------------------------------------------\n";
    }
    else if (tipo == 3) {
        CrearBanner("COTIZAR");
        std::cout << "Presiona 3 para volver al menú principal o h para ver el historial de cotizaciones\n";
        std::cout << "---------------------------------------------\n";
        std::cout << "PASO 2.b: La camisa a cotizar, ¿Es cuello Mao?:\n";
        std::cout << "1) Sí\n";
        std::cout << "2) No\n";
        std::cout << "---------------------------------------------\n";
    }
}

void Vistas::CrearMenuCalidad()
{
    CrearBanner("COTIZAR");
    std::cout << "Presiona 3 para volver al menú principal o h para ver el historial de cotizaciones\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "PASO 3: Seleccione la calidad de la prenda:\n";
    std::cout << "1) Standard\n";
    std::cout << "2) Premium\n";
    std::cout << "---------------------------------------------\n";
}

void Vistas::CrearMenuValor()
{
    CrearBanner("COTIZAR");
    std::cout << "Presiona * para volver al menú principal o h para ver el historial de cotizaciones\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar:\n";
    std::cout << "---------------------------------------------\n";
}

void Vistas::CrearMenuCantidad(int cantidad)
{
    CrearBanner("COTIZAR");
    std::cout << "Presiona * para volver al menú principal o h para ver el historial de cotizaciones\n";
    std::cout << "---------------------------------------------\n\n";
    std::cout << "INFORMACIÓN\n";
    std::cout << "EXISTEN " << cantidad << " UNIDADES EN STOCK DE LA PRENDA SELECCIONADA\n\n";
    std::cout << "PASO 5: Ingrese la cantidad de unidades a cotizar:\n";
    std::cout << "---------------------------------------------\n";
}

void Vistas::CrearMenuValorCotizado(std::string codigoCotizacion, std::string fecha, int codigoVendedor, std::string prenda, std::string tipo, std::string calidad, double valor, int cantidad, double total)
{
    CrearBanner("COTIZAR");
    std::cout << "Presiona h para ver el historial de cotizaciones o cualquier tecla para ir al menú principal\n";
    std::cout << "---------------------------------------------\n\n";
    std::cout << "Número de identificación: " << codigoCotizacion << "\n";
    std::cout << "Fecha y Hora de la cotización: " << fecha << " \n";
    std::cout << "Código del vendedor: " << codigoVendedor << "\n";
    std::cout << "Prenda cotizada: " << prenda << " - " << tipo << " - " << calidad << "\n";
    std::cout << "Precio unitario: " << valor << "\n";
    std::cout << "Cantidad de unidades cotizadas: " << cantidad << "\n";
    std::cout << "Precio Final: " << total << "\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Presiona h para ver el historial de cotizaciones o cualquier tecla para ir al menú principal\n";
    std::cout << "---------------------------------------------\n";
}

void Vistas::Salir()
{
    exit(0);
}

void Vistas::CrearBanner(std::string menu)
{
    system("cls");
    std::cout << "COTIZADOR EXPRESS - " << menu << "\n";
    std::cout << "---------------------------------------------\n";
}

void Vistas::MostrarError(std::string error, std::string tipo)
{
    std::cout << error;
    if(tipo == "Cerrar")
        Salir();
}