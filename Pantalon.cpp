#include "Pantalon.h"

Pantalon::Pantalon(std::string newTipo, std::string newCalidad, int newCantidad)
{
	tipoBase = "Pantalon";
	tipoPantalon = newTipo;
	calidad = newCalidad;
	cantidad = newCantidad;
}

/*void Pantalon::Inicializar(std::string newTipo, std::string newCalidad, int newCantidad)
{
	tipoPantalon = newTipo;
	calidad = newCalidad;
	cantidad = newCantidad;
}*/