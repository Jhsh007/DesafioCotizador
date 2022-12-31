#include "Cotizacion.h"

Cotizacion::Cotizacion()
{
	codigoIdentificacion = "XXX";
	fechaHora = "";
	codigoVendedor = 0;
	prenda = "";
	cantidadCotizada = 0;
	totalCotizado = 0;
}

void Cotizacion::CrearCotizacion(std::string codigoCotizacion, std::string fecha, int codigo_vendedor, std::string newPrenda, int cantidadPrenda, double valorCotizacion)
{
	codigoIdentificacion = codigoCotizacion;
	fechaHora = fecha;
	codigoVendedor = codigo_vendedor;
	prenda = newPrenda;
	cantidadCotizada = cantidadPrenda;
	totalCotizado = valorCotizacion;
}
