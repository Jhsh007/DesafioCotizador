#include "Vendedor.h"

Vendedor::Vendedor()
{
	codigo_vendedor = 0;
	nombre_vendedor = "Vendedor";
	apellido_vendedor = "Vendedor";
}

void Vendedor::Inicializar(int codigo, std::string nombre, std::string apellido)
{
	codigo_vendedor = codigo;
	nombre_vendedor = nombre;
	apellido_vendedor = apellido;
}
