#include "Presentador.h"
#include <iostream>

Presentador::Presentador()
{
	vista = new Vistas();
	tienda = new Tienda();
	vendedor = new Vendedor();
	prenda = "";
	tipo_manga = "";
	tipo_cuello = "";
	tipo_pantalon = "";
	calidad = "";
	precio = 0;
	cantidad = 0;
	cantidadDisponible = 0;
	total = 0;
	currentMenu = "MenuPrincipal";
}

Presentador::~Presentador()
{
	delete vista;
	vista = NULL;
	delete tienda;
	tienda = NULL;
	delete vendedor;
	vendedor = NULL;
}

bool Presentador::InicializarTienda(std::string nombre, std::string direccion)
{
	tienda->Inicializar(nombre, direccion);
	return true;
}

void Presentador::InicializarVendedor(int codigo, std::string nombre, std::string apellido)
{
	vendedor->Inicializar(codigo, nombre, apellido);
}

void Presentador::IniciarMenus()
{
	//Crear menu principal en la vista
	vista->CrearMenuPrincipal(tienda, vendedor);

	std::string opcionElegida;
	std::cin >> opcionElegida;
	//HandleMenus(opcionElegida);
}
