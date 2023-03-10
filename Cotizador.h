#pragma once
#include <string>
#include <vector>
#include "Tienda.h"
#include "Cotizacion.h"

class Cotizador
{
public:
	Cotizador();
	~Cotizador();
	/* A?ade a la tienda la cantidad de prendas seg?n su tipo, tomando como base un archivo txt ya existente  */
	bool InicializarStock(Tienda* t);

	/* Funciones par cotizar */
	double Cotizar(std::string tipoManga, std::string tipoCuello, std::string calidad, double precio, int cantidad);
	double Cotizar(std::string tipoPantalon, std::string calidad, double precio, int cantidad);

	/* Abre el archivo txt con las cotizaciones realizadas y guarda la informaci?n en el vector cotizaciones */
	bool LeerHistorial();

	/* A?ade una cotizacion al historial (tanto en el vector cotizaciones como en el archivo txt) */
	Cotizacion* A?adirCotizacion(int vendedor, std::string newTipoPrenda, int cantPrendas, double valorUnitario, double valorCotizado);

	/* Funciones para validar la conversi?n de un string a n?mero */
	int ValidarEntero(std::string dato);
	double ValidarDouble(std::string dato);

	std::vector<std::string> SplitStr(std::string str, std::string deli);

	/* Getters */
	inline std::vector<Cotizacion*> GetCotizaciones() { return cotizaciones; };

private:
	//Historial de cotizaciones
	std::vector<Cotizacion*> cotizaciones;
};