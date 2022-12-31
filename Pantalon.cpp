#include "Pantalon.h"

Pantalon::Pantalon(std::string newTipo, std::string newCalidad, int newCantidad)
{
	tipoBase = "Pantalon";
	tipoPantalon = newTipo;
	calidad = newCalidad;
	cantidad = newCantidad;
}