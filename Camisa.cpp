#include "Camisa.h"

Camisa::Camisa(std::string manga, std::string cuello, std::string newCalidad, int newCantidad)
{
	tipoBase = "Camisa";
	tipoManga = manga;
	tipoCuello = cuello;
	calidad = newCalidad;
	cantidad = newCantidad;
}

/*void Camisa::Inicializar(std::string manga, std::string cuello, std::string newCalidad, int newCantidad)
{
	tipoManga = manga;
	tipoCuello = cuello;
	calidad = newCalidad;
	cantidad = newCantidad;
}*/
