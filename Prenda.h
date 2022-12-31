#pragma once
#include <string>

class Prenda
{
public:
	inline std::string GetTipoBase() { return tipoBase; };
	inline std::string GetCalidad() { return calidad; };
	inline int GetCantidad() { return cantidad; };

protected:
	std::string tipoBase;
	std::string calidad;
	int cantidad;

};
