#include "Pantalon.h"

Pantalon::Pantalon()
{
	tipoBase = "Pantalon";
	tipoPantalon = "Chup�n";
	calidad = "Standard";
	cantidad = 0;
}

void Pantalon::Inicializar(std::string newTipo, std::string newCalidad, int newCantidad)
{
	tipoPantalon = newTipo;
	calidad = newCalidad;
	cantidad = newCantidad;
}