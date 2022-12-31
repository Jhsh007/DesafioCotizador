#pragma once
#include <string>
#include <vector>
#include "Prenda.h"

class Tienda
{
public:
	Tienda();
	~Tienda();
	void Inicializar(std::string nombre, std::string direccion);

	/* Getters */
	inline std::string GetNombre() { return nombre_tienda; }
	inline std::string GetDireccion() { return direccion_tienda; }

private:
	/* Variables */
	std::string nombre_tienda;
	std::string direccion_tienda;
	//Vector con los tipos de camisas y pantalones
	std::vector<Prenda*> tiposPrendas;
};
