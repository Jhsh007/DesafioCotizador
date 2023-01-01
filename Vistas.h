#pragma once
#include <string>
#include "Cotizacion.h"
#include <vector>

class Vistas
{
public:
	//Funciones para mostrar los menus en consola
	void CrearMenuPrincipal(class Tienda* t, class Vendedor* v);
	void CrearMenuHistorial(std::vector<Cotizacion*> cotizaciones);
	void CrearMenuCotizacion();
	void CrearMenuSeleccion(int tipo);
	void CrearMenuCalidad();
	void CrearMenuValor();
	void CrearMenuCantidad(int cantidad);
	void CrearMenuValorCotizado(std::string codigoCotizacion, std::string fecha, int codigoVendedor, std::string prenda, std::string tipo, std::string calidad, double valor, int cantidad, double total);
	
	void Salir();
	void CrearBanner(std::string menu);
	void MostrarError(std::string error, std::string tipo);
};