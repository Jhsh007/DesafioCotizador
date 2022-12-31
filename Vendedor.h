#pragma once
#include <string>

class Vendedor
{
public:
	Vendedor();
	void Inicializar(int codigo, std::string nombre, std::string apellido);
	/* Getters */
	inline int GetCodigo() { return codigo_vendedor; }
	inline std::string GetNombre() { return nombre_vendedor; }
	inline std::string GetApellido() { return apellido_vendedor; }

private:
	int codigo_vendedor;
	std::string nombre_vendedor;
	std::string apellido_vendedor;

};