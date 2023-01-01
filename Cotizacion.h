#pragma once
#include <string>

class Cotizacion
{
public:
	Cotizacion(std::string codigoCotizacion, std::string fecha, int codigo_vendedor, std::string newPrenda, double valor_unitario, int cantidadPrenda, double valorCotizacion);

	void CrearCotizacion(std::string codigoCotizacion, std::string fecha, int codigo_vendedor, std::string newPrenda, double valor_unitario, int cantidadPrenda, double valorCotizacion);

	/* Getters */
	inline std::string GetCodigoIdentificacion() { return codigoIdentificacion; };
	inline std::string GetFecha() { return fechaHora; };
	inline int GetCodigoVendedor() { return codigoVendedor; };
	inline std::string GetPrenda() { return prenda; };
	inline double GetValorUnitario() { return valorUnitario; };
	inline int GetCantidad() { return cantidadCotizada; };
	inline double GetTotal() { return totalCotizado; };

private:
	std::string codigoIdentificacion;
	std::string fechaHora;
	int codigoVendedor;
	std::string prenda;
	double valorUnitario;
	int cantidadCotizada;
	double totalCotizado;

};