#include "Tienda.h"
#include <iostream>
#include "Camisa.h"
#include "Pantalon.h"

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

//Añade un tipo de prenda al vector tiposPrendas
void Tienda::AñadirPrenda(Prenda* prenda)
{
	tiposPrendas.push_back(prenda);
}

/* Devuelve un puntero a la prenda adecuada de acuerdo al tipo requerido */
Prenda* Tienda::GetTipoPrenda(std::string tipo1, std::string tipo2, std::string calidad)
{
	for(Prenda* tipoPrenda : tiposPrendas){
		Camisa* camisa = static_cast<Camisa*>(tipoPrenda);
		if(camisa){
			if(camisa->GetTipoManga() == tipo1 && camisa->GetTipoCuello() == tipo2 && camisa->GetCalidad() == calidad){
				std::cout << camisa->GetCantidad() << " cantidad\n";
				return camisa;
			}
		}
	}
	return nullptr;
}
Prenda* Tienda::GetTipoPrenda(std::string tipo1, std::string calidad)
{
	for(Prenda* tipoPrenda : tiposPrendas){
		Pantalon* pantalon = static_cast<Pantalon*>(tipoPrenda);
		if(pantalon){
			if (pantalon->GetTipoPantalon() == tipo1 && pantalon->GetCalidad() == calidad) {
				std::cout << pantalon->GetCantidad() << " cantidad\n";
				return pantalon;
			}
		}
	}
	return nullptr;
}
