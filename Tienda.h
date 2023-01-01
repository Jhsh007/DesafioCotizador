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
	//Añade un tipo de prenda al vector tiposPrendas
	void AñadirPrenda(Prenda* prenda);
	/* Devuelve un puntero a la prenda adecuada de acuerdo al tipo requerido */
	Prenda* GetTipoPrenda(std::string tipo1, std::string tipo2, std::string calidad);
	Prenda* GetTipoPrenda(std::string tipo, std::string calidad);

	/* Getters */
	inline std::string GetNombre() { return nombre_tienda; }
	inline std::string GetDireccion() { return direccion_tienda; }
	inline std::vector<Prenda*> GetTiposPrendas() { return tiposPrendas; }
	

private:
	/* Variables */
	std::string nombre_tienda;
	std::string direccion_tienda;
	//Vector con los tipos de camisas y pantalones
	std::vector<Prenda*> tiposPrendas;
};
