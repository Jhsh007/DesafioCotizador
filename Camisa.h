#pragma once
#include "Prenda.h"

class Camisa : public Prenda
{
public:
	Camisa();
	void Inicializar(std::string manga, std::string cuello, std::string newCalidad, int newCantidad);

	/* Getters */
	inline std::string GetTipoManga() { return tipoManga; };
	inline std::string GetTipoCuello() { return tipoCuello; };

private:
	std::string tipoManga;
	std::string tipoCuello;

};
