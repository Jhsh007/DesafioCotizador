#include "Cotizacion.h"

Cotizacion::Cotizacion()
{
	codigoIdentificacion = "";
	fechaHora = "";
	codigoVendedor = 0;
	prenda = "";
	valorUnitario = 0;
	cantidadCotizada = 0;
	totalCotizado = 0;
}

Cotizacion::Cotizacion(std::string codigoCotizacion, std::string fecha, int codigo_vendedor, std::string newPrenda, double valor_unitario, int cantidadPrenda, double valorCotizacion)
{
	codigoIdentificacion = codigoCotizacion;
	fechaHora = fecha;
	codigoVendedor = codigo_vendedor;
	prenda = newPrenda;
	valorUnitario = valor_unitario;
	cantidadCotizada = cantidadPrenda;
	totalCotizado = valorCotizacion;
}

void Cotizacion::CrearCotizacion(std::string codigoCotizacion, std::string fecha, int codigo_vendedor, std::string newPrenda, double valor_unitario, int cantidadPrenda, double valorCotizacion)
{
	codigoIdentificacion = codigoCotizacion;
	fechaHora = fecha;
	codigoVendedor = codigo_vendedor;
	prenda = newPrenda;
	cantidadCotizada = cantidadPrenda;
	totalCotizado = valorCotizacion;
}
