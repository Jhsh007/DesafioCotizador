#pragma once
#include "Prenda.h"

class Pantalon : public Prenda
{
public:
	Pantalon();
	void Inicializar(std::string newTipo, std::string newCalidad, int newCantidad);

	/* Getters */
	inline std::string GetTipoPantalon() { return tipoPantalon; };

private:
	std::string tipoPantalon;

};