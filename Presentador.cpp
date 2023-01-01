#include "Presentador.h"
#include <iostream>

Presentador::Presentador()
{
	vista = new Vistas();
	cotizador = new Cotizador();
	tienda = new Tienda();
	vendedor = new Vendedor();
	
	prenda = "";
	tipo_manga = "";
	tipo_cuello = "";
	tipo_pantalon = "";
	calidad = "";
	precio = 0;
	cantidad = 0;
	cantidadDisponible = 0;
	total = 0;
	currentMenu = "MenuPrincipal";
}

bool Presentador::InicializarTienda(std::string nombre, std::string direccion)
{
	if(tienda){
		tienda->Inicializar(nombre, direccion);
		if(cotizador && cotizador->InicializarStock(tienda)){
			return true;
		}else{
			if(vista)
				vista->MostrarError("No se pudo leer el stock, contacte al administrador.", "Cerrar");
			return false;
		}
	}else{
		return false;
	}
}

void Presentador::InicializarVendedor(int codigo, std::string nombre, std::string apellido)
{
	if(vendedor)
		vendedor->Inicializar(codigo, nombre, apellido);
}

void Presentador::IniciarMenus()
{
	if(cotizador && cotizador->LeerHistorial()){
		//Crear menu principal en la vista
		vista->CrearMenuPrincipal(tienda, vendedor);

		std::string opcionElegida;
		std::cin >> opcionElegida;
		HandleMenus(opcionElegida);
	}
}

void Presentador::HandleMenus(std::string opcionElegida)
{
	bool isValid = false;
	int opcion = -1;
	double opcionD = -1;

	if(currentMenu == "MenuPrincipal"){
		//Validar la opción elegida por el usuario
		opcion = cotizador->ValidarEntero(opcionElegida);
		if(opcion > 0 && opcion < 4){
			isValid = true;
		}else{
			MostrarError(opcionElegida, "Opción invalida, seleccione 1, 2 o 3\n");
		}if(isValid){// Si la opción es valida pasar a la pantalla indicada
			switch (opcion){
			case 1:
				vista->CrearMenuHistorial(cotizador->GetCotizaciones());
				currentMenu = "MenuHistorial";
				break;
			case 2:
				vista->CrearMenuCotizacion();
				currentMenu = "MenuCotizacion";
				break;
			case 3:
				vista->Salir();
				break;
			}
		}
	}else if(currentMenu == "MenuHistorial"){
		//Validar la opción elegida por el usuario
		opcion = cotizador->ValidarEntero(opcionElegida);
		if (opcion == 3) {// Si la opción es 3 volver al menú
			isValid = true;
			vista->CrearMenuPrincipal(tienda, vendedor);
			currentMenu = "MenuPrincipal";
		}else{
			MostrarError(opcionElegida, "Opción invalida, seleccione 3 para volver al menú\n");
		}
	}

	/* Si la opción es valida, esperar por la siguiente opción del usuario */
	if(isValid){
		std::cin >> opcionElegida;
		HandleMenus(opcionElegida);
	}
}

/* Maneja el error cuando el usuario ingresa una opción erronea */
void Presentador::MostrarError(std::string opcionElegida, std::string error)
{
	std::cout << error;
	std::cin >> opcionElegida;
	HandleMenus(opcionElegida);
}
