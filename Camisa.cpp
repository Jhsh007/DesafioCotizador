#include "Camisa.h"

Camisa::Camisa()
{
	tipoBase = "Camisa";
	tipoManga = "Corta";
	tipoCuello = "Moa";
	calidad = "Standard";
	cantidad = 0;
}

void Camisa::Inicializar(std::string manga, std::string cuello, std::string newCalidad, int newCantidad)
{
	tipoManga = manga;
	tipoCuello = cuello;
	calidad = newCalidad;
	cantidad = newCantidad;
}
