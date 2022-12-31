#pragma once
#include <string>

class Cotizacion
{
public:
	Cotizacion();

	void CrearCotizacion(std::string codigoCotizacion, std::string fecha, int codigo_vendedor, std::string newPrenda, int cantidadPrenda, double valorCotizacion);

	/* Getters */
	inline std::string GetCodigoIdentificacion() { return codigoIdentificacion; };
	inline std::string GetFecha() { return fechaHora; };
	inline int GetCodigoVendedor() { return codigoVendedor; };
	inline std::string GetPrenda() { return prenda; };
	inline int GetCantidad() { return cantidadCotizada; };
	inline double GetTotal() { return totalCotizado; };

private:
	std::string codigoIdentificacion;
	std::string fechaHora;
	int codigoVendedor;
	std::string prenda;
	int cantidadCotizada;
	double totalCotizado;

};