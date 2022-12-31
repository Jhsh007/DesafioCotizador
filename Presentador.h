#pragma once
#include "Vistas.h"
#include "Cotizador.h"
#include "Tienda.h"
#include "Vendedor.h"

class Presentador
{
public:
	Presentador();
	~Presentador();
	/* Inicializadores */
	bool InicializarTienda(std::string nombre, std::string direccion);
	void InicializarVendedor(int codigo, std::string nombre, std::string apellido);
	void IniciarMenus();

	/* Recibe un string del usuario y cambia al menú correspondiente en vistas */
	void HandleMenus(std::string opcionElegida);
	/* Maneja el error cuando el usuario ingresa una opción erronea */
	void MostrarError(std::string opcionElegida, std::string error);

private:
	//Maneja las funciones para mostrar datos en consola
	Vistas* vista;
	//Maneja las funciones para procesar los datos del programa
	//Cotizador cotizador;

	/* Tienda y Vendedor */
	Tienda* tienda;
	Vendedor* vendedor;

	/* Variables */
	std::string prenda;
	std::string tipo_manga;
	std::string tipo_cuello;
	std::string tipo_pantalon;
	std::string calidad;
	double precio;
	int cantidad;
	int cantidadDisponible;
	double total;
	std::string currentMenu;

};