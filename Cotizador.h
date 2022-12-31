#pragma once
#include <string>
#include "Tienda.h"
#include "Cotizacion.h"
#include <vector>

class Cotizador
{
public:
	Cotizador();
	~Cotizador();
	/* Añade a la tienda la cantidad de prendas según su tipo, tomando como base un archivo txt ya existente  */
	bool InicializarStock(Tienda* t);

	/* Abre el archivo txt con las cotizaciones realizadas y guarda la información en el vector cotizaciones */
	std::vector<Cotizacion*> LeerHistorial();

	/* Añade una cotizacion al historial (tanto en el vector cotizaciones como en el archivo txt) */
	Cotizacion* AñadirCotizacion(int vendedor, std::string newTipoPrenda, int cantPrendas, double valorUnitario, double valorCotizado);

	/* Funciones para validar la conversión de un string a número */
	int ValidarEntero(std::string dato);
	double ValidarDouble(std::string dato);

	std::vector<std::string> SplitStr(std::string str, std::string deli);

	/* Getters */
	inline std::vector<Cotizacion*> GetCotizaciones() { return cotizaciones; };

private:
	//Historial de cotizaciones
	std::vector<Cotizacion*> cotizaciones;
};