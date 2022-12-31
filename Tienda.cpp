#include "Tienda.h"

Tienda::Tienda()
{
	nombre_tienda = "Tienda";
	direccion_tienda = "Dirección";
}

Tienda::~Tienda()
{
	//Eliminar los punteros
	for(Prenda* ptr : tiposPrendas){
		delete ptr;
		ptr = NULL;
	}
}

void Tienda::Inicializar(std::string nombre, std::string direccion)
{
	nombre_tienda = nombre;
	direccion_tienda = direccion;
}