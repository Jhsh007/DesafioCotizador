#pragma once
#include "Prenda.h"

class Pantalon : public Prenda
{
public:
	Pantalon(std::string newTipo, std::string newCalidad, int newCantidad);
	//void Inicializar(std::string newTipo, std::string newCalidad, int newCantidad);

	/* Getters */
	inline std::string GetTipoPantalon() { return tipoPantalon; };

private:
	std::string tipoPantalon;

};