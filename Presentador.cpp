#include "Presentador.h"
#include <iostream>
#include "Camisa.h"
#include "Pantalon.h"

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
	}else if (currentMenu == "MenuCotizacion"){
		if(opcionElegida == "h"){// Si la opción es h, ir al menú de historial
			isValid = true;
			vista->CrearMenuHistorial(cotizador->GetCotizaciones());
			currentMenu = "MenuHistorial";
		}else{
			//Validar la opción elegida por el usuario
			opcion = cotizador->ValidarEntero(opcionElegida);
			if(opcion > 0 && opcion < 4){
				isValid = true;
			}else{
				MostrarError(opcionElegida, "Opción invalida, seleccione 1, 2 o 3\n");
			}
			if(isValid){// Si la opción es valida pasar a la pantalla indicada
				switch (opcion){
				case 1:
					vista->CrearMenuSeleccion(opcion);
					currentMenu = "MenuSeleccion";
					prenda = "Camisa";
					break;
				case 2:
					vista->CrearMenuSeleccion(opcion);
					currentMenu = "MenuSeleccion";
					prenda = "Pantalon";
					break;
				case 3:
					vista->CrearMenuPrincipal(tienda, vendedor);
					currentMenu = "MenuPrincipal";
					break;
				}
			}
		}
	}else if(currentMenu == "MenuSeleccion"){
		if(opcionElegida == "h"){// Si la opción es h, ir al menú de historial
			isValid = true;
			vista->CrearMenuHistorial(cotizador->GetCotizaciones());
			currentMenu = "MenuHistorial";
		}else{
			//Validar la opción elegida por el usuario
			opcion = cotizador->ValidarEntero(opcionElegida);
			if(opcion > 0 && opcion < 4){
				isValid = true;
			}else{
				MostrarError(opcionElegida, "Opción invalida, seleccione 1, 2 o 3\n");
			}
			if(isValid){// Si la opción es valida pasar a la pantalla indicada
				switch (opcion) {
				case 1:
					if(prenda == "Camisa"){
						vista->CrearMenuSeleccion(3);
						currentMenu = "MenuSeleccionCamisa";
						tipo_manga = "Corta";
					}else{
						vista->CrearMenuCalidad();
						currentMenu = "MenuCalidad";
						tipo_pantalon = "Chupín";
					}
					break;
				case 2:
					if(prenda == "Camisa"){
						vista->CrearMenuSeleccion(3);
						currentMenu = "MenuSeleccionCamisa";
						tipo_manga = "Larga";
					}else{
						vista->CrearMenuCalidad();
						currentMenu = "MenuCalidad";
						tipo_pantalon = "Común";
					}
					break;
				case 3:
					vista->CrearMenuPrincipal(tienda, vendedor);
					currentMenu = "MenuPrincipal";
					break;
				}
			}
		}
	}else if(currentMenu == "MenuSeleccionCamisa"){
		if(opcionElegida == "h"){// Si la opción es h, ir al menú de historial
			isValid = true;
			vista->CrearMenuHistorial(cotizador->GetCotizaciones());
			currentMenu = "MenuHistorial";
		}else{
			//Validar la opción elegida por el usuario
			opcion = cotizador->ValidarEntero(opcionElegida);
			if(opcion > 0 && opcion < 4){
				isValid = true;
			}else{
				MostrarError(opcionElegida, "Opción invalida, seleccione 1, 2 o 3\n");
			}
			if(isValid){// Si la opción es valida pasar a la pantalla indicada
				switch(opcion){
				case 1:
					vista->CrearMenuCalidad();
					currentMenu = "MenuCalidad";
					tipo_cuello = "Mao";
					break;
				case 2:
					vista->CrearMenuCalidad();
					currentMenu = "MenuCalidad";
					tipo_cuello = "Común";
					break;
				case 3:
					vista->CrearMenuPrincipal(tienda, vendedor);
					currentMenu = "MenuPrincipal";
					break;
				}
			}
		}
	}else if(currentMenu == "MenuCalidad"){
		if(opcionElegida == "h"){// Si la opción es h, ir al menú de historial
			isValid = true;
			vista->CrearMenuHistorial(cotizador->GetCotizaciones());
			currentMenu = "MenuHistorial";
		}else{
			//Validar la opción elegida por el usuario
			opcion = cotizador->ValidarEntero(opcionElegida);
			if(opcion > 0 && opcion < 4){
				isValid = true;
			}else{
				MostrarError(opcionElegida, "Opción invalida, seleccione 1, 2 o 3\n");
			}
			if(isValid){// Si la opción es valida pasar a la pantalla indicada
				switch(opcion){
				case 1:
					vista->CrearMenuValor();
					currentMenu = "MenuValor";
					calidad = "Standard";
					break;
				case 2:
					vista->CrearMenuValor();
					currentMenu = "MenuValor";
					calidad = "Premium";
					break;
				case 3:
					vista->CrearMenuPrincipal(tienda, vendedor);
					currentMenu = "MenuPrincipal";
					break;
				}
			}
		}
	}else if(currentMenu == "MenuValor"){
		//Validar la opción elegida por el usuario
		if(opcionElegida == "*"){// Si la opción es *, volver al menú
			isValid = true;
			vista->CrearMenuPrincipal(tienda, vendedor);
			currentMenu = "MenuPrincipal";
		}else if(opcionElegida == "h"){// Si la opción es h, ir al menú de historial
			isValid = true;
			vista->CrearMenuHistorial(cotizador->GetCotizaciones());
			currentMenu = "MenuHistorial";
		}else{
			opcionD = cotizador->ValidarDouble(opcionElegida);
			if(opcionD > 0){
				isValid = true;
			}else{
				MostrarError(opcionElegida, "Opción invalida, escriba un número o escriba * para volver al menú.\n");
			}
			if(isValid){// Si la opción es valida pasar a la pantalla indicada
				precio = opcionD;
				cantidadDisponible = 0;

				//Prenda* tipoPrendaActual = new Prenda();
				if(prenda == "Camisa"){	
					Prenda* tipoPrendaActual = tienda->GetTipoPrenda(tipo_manga, tipo_cuello, calidad);
					if(tipoPrendaActual){
						cantidadDisponible = tipoPrendaActual->GetCantidad();
						delete tipoPrendaActual;
						tipoPrendaActual = NULL;
					}else{
						cantidadDisponible = -1;
					}
				}else{
					Prenda* tipoPrendaActual = tienda->GetTipoPrenda(tipo_pantalon, calidad);
					if(tipoPrendaActual){
						cantidadDisponible = tipoPrendaActual->GetCantidad();
						delete tipoPrendaActual;
						tipoPrendaActual = NULL;
					}
					else {
						cantidadDisponible = -1;
					}
				}
				vista->CrearMenuCantidad(cantidadDisponible);
				currentMenu = "MenuCantidad";
			}
		}
	}else if(currentMenu == "MenuCantidad"){
		if(opcionElegida == "*"){// Si la opción es * volver al menú
			isValid = true;
			vista->CrearMenuPrincipal(tienda, vendedor);
			currentMenu = "MenuPrincipal";
		}else if(opcionElegida == "h"){// Si la opción es h, ir al menú de historial
			isValid = true;
			vista->CrearMenuHistorial(cotizador->GetCotizaciones());
			currentMenu = "MenuHistorial";
		}else{
			//Validar la opción elegida por el usuario
			opcion = cotizador->ValidarEntero(opcionElegida);
			if(opcion > 0){
				isValid = true;
			}else{
				MostrarError(opcionElegida, "Opción invalida, escriba un número o escriba * para volver al menú.\n");
			}
			if(isValid){// Si la opción es valida pasar a la pantalla indicada
				if(opcion <= cantidadDisponible){
					Cotizacion* cotizacionCreada = new Cotizacion();
					std::string tipo;
					cantidad = opcion;
					/* Crear la cotización de acuerdo al tipo de prenda */
					if(prenda == "Camisa"){
						tipo = tipo_manga;
						if(tipo_cuello != ""){
							tipo.append(" - " + tipo_cuello);
						}
						total = cotizador->Cotizar(tipo_manga, tipo_cuello, calidad, precio, cantidad);
						std::string tipoPrenda = prenda + " - " + tipo + " - " + calidad;
						cotizacionCreada = cotizador->AñadirCotizacion(vendedor->GetCodigo(), tipoPrenda, cantidad, precio, total);
					}else{
						if (tipo_pantalon != "")
							tipo = tipo_pantalon;
						total = cotizador->Cotizar(tipo_pantalon, calidad, precio, cantidad);
						std::string tipoPrenda = prenda + " - " + tipo + " - " + calidad;
						cotizacionCreada = cotizador->AñadirCotizacion(vendedor->GetCodigo(), tipoPrenda, cantidad, precio, total);
					}
					// Crear el siguiente menú
					vista->CrearMenuValorCotizado(cotizacionCreada->GetCodigoIdentificacion(), cotizacionCreada->GetFecha(), vendedor->GetCodigo(), prenda, tipo, calidad, precio, cantidad, total);
					currentMenu = "MenuCotizado";
				}else{
					MostrarError(opcionElegida, "Opción invalida, escriba una cantidad igual o inferior a la cantidad máxima en stock.\n");
				}
			}
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
