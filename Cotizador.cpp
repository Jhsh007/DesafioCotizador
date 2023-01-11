#include "Cotizador.h"
#include <ctime>
#include <chrono>
#include <fstream>
#include "Camisa.h"
#include "Pantalon.h"
#include <iostream>

Cotizador::Cotizador()
{
	
}

Cotizador::~Cotizador()
{
	/* Limpiar y borrar los punteros en el vector cotizaciones */
	for(Cotizacion* cot : cotizaciones){
		delete cot;
		cot = NULL;
	}
	cotizaciones.clear();
}

/* Añade a la tienda la cantidad de prendas según su tipo, tomando como base un archivo txt ya existente  */
bool Cotizador::InicializarStock(Tienda* t)
{
	//Abre el archivo stock.txt
	std::string line;
	std::fstream myfile;
	myfile.open("Stock.txt",std::fstream::in);
	if(myfile){
		std::string prendaActual;
		std::string tipo1Actual;
		std::string tipo2Actual;
		std::string calidad;
		int cantidad;
		while(getline(myfile, line)){
			std::vector<std::string> datosPrenda = SplitStr(line, "-");
			prendaActual = datosPrenda[0];
			tipo1Actual = datosPrenda[1];
			if(prendaActual == "Camisa"){
				tipo2Actual = datosPrenda[2];
				calidad = datosPrenda[3];
				cantidad = ValidarEntero(datosPrenda[4]);
				Camisa* nuevaPrenda = new Camisa(tipo1Actual, tipo2Actual, calidad, cantidad);
				t->AñadirPrenda(nuevaPrenda);
			}else if(prendaActual == "Pantalon"){
				calidad = datosPrenda[2];
				cantidad = ValidarEntero(datosPrenda[3]);
				Pantalon* nuevaPrenda = new Pantalon(tipo1Actual, calidad, cantidad);
				t->AñadirPrenda(nuevaPrenda);
			}
			datosPrenda.clear();
		}
		return true;
	}else{
		myfile.open("Stock.txt", std::fstream::out);
		if(myfile){
			t->AñadirPrenda(new Camisa("Corta", "Mao", "Standard", 100));
			myfile << "Camisa-Corta-Mao-Standard-100-\n";
			t->AñadirPrenda(new Camisa("Corta", "Mao", "Premium", 100));
			myfile << "Camisa-Corta-Mao-Premium-100-\n";
			t->AñadirPrenda(new Camisa("Corta", "Común", "Standard", 150));
			myfile << "Camisa-Corta-Común-Standard-150-\n";
			t->AñadirPrenda(new Camisa("Corta", "Común", "Premium", 150));
			myfile << "Camisa-Corta-Común-Premium-150-\n";
			t->AñadirPrenda(new Camisa("Larga", "Mao", "Standard", 75));
			myfile << "Camisa-Larga-Mao-Standard-75-\n";
			t->AñadirPrenda(new Camisa("Larga", "Mao", "Premium", 75));
			myfile << "Camisa-Larga-Mao-Premium-75-\n";
			t->AñadirPrenda(new Camisa("Larga", "Común", "Standard", 175));
			myfile << "Camisa-Larga-Común-Standard-175-\n";
			t->AñadirPrenda(new Camisa("Larga", "Común", "Premium", 175));
			myfile << "Camisa-Larga-Común-Premium-175-\n";
			t->AñadirPrenda(new Pantalon("Chupín", "Standard", 750));
			myfile << "Pantalon-Chupín-Standard-750-\n";
			t->AñadirPrenda(new Pantalon("Chupín", "Premium", 750));
			myfile << "Pantalon-Chupín-Premium-750-\n";
			t->AñadirPrenda(new Pantalon("Común", "Premium", 250));
			myfile << "Pantalon-Común-Standard-250-\n";
			t->AñadirPrenda(new Pantalon("Común", "Standard", 250));
			myfile << "Pantalon-Común-Premium-250-\n";
			std::cout << "LineaActual: " << t->GetTiposPrendas()[0]->GetCantidad() << "\n";
			return true;
		}else{
			return false;
		}
	}
}

/* Añade una cotizacion al historial (tanto en el vector cotizaciones como en el archivo txt) */
Cotizacion* Cotizador::AñadirCotizacion(int vendedor, std::string newTipoPrenda, int cantPrendas, double valorUnitario, double valorCotizado)
{
	Cotizacion* cotizacionPtr = NULL;
	/* Crear la fecha */
	time_t rawtime = std::time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	std::string fechaActual = "";
	fechaActual.append(std::to_string(timeinfo.tm_mday));
	fechaActual.append("/" + std::to_string(timeinfo.tm_mon + 1));
	fechaActual.append("/" + std::to_string(timeinfo.tm_year + 1900));
	fechaActual.append("  " + std::to_string(timeinfo.tm_hour));
	if(timeinfo.tm_min > 9)
		fechaActual.append(":" + std::to_string(timeinfo.tm_min));
	else
		fechaActual.append(":0" + std::to_string(timeinfo.tm_min));

	/* Abrir archivo */
	std::string line;
	std::fstream myfile;
	myfile.open("HistorialCotizaciones.txt", std::fstream::out | std::fstream::in | std::fstream::app);
	if(myfile){
		/* Escribir en el archivo */
		std::string codigoCotizacion = "";
		int cantCotizaciones = cotizaciones.size();
		cantCotizaciones++;
		if(cotizaciones.size() < 10){
			codigoCotizacion.append("00" + std::to_string(cantCotizaciones));
		}else if(cotizaciones.size() < 100){
			codigoCotizacion.append("0" + std::to_string(cantCotizaciones));
		}else{
			codigoCotizacion.append("" + std::to_string(cantCotizaciones));
		}
		myfile << "Cotización\n";
		myfile << codigoCotizacion << "\n";
		myfile << fechaActual << "\n";
		myfile << vendedor << "\n";
		myfile << newTipoPrenda << "\n";
		myfile << valorUnitario << "\n";
		myfile << cantPrendas << "\n";
		myfile << valorCotizado << "\n";
		myfile.close();

		//Añade el puntero al vector de cotizaciones
		cotizacionPtr = new Cotizacion(codigoCotizacion, fechaActual, vendedor, newTipoPrenda, valorUnitario, cantPrendas, valorCotizado);
		cotizaciones.push_back(cotizacionPtr);
	}
	return cotizacionPtr;
}

/* Funciones par cotizar */
double Cotizador::Cotizar(std::string tipoManga, std::string tipoCuello, std::string calidad, double precio, int cantidad){
	if(tipoManga == "Corta")
		precio -= precio * 0.1f;
	if(tipoCuello == "Mao")
		precio += precio * 0.03f;
	if(calidad == "Premium")
		precio += precio * 0.3f;
	precio *= cantidad;

	return precio;
}
double Cotizador::Cotizar(std::string tipoPantalon, std::string calidad, double precio, int cantidad){
	if(tipoPantalon == "Chupín")
		precio -= precio * 0.12f;
	if(calidad == "Premium")
		precio += precio * 0.3f;
	precio *= cantidad;

	return precio;
}

/* Abre el archivo txt con las cotizaciones realizadas y guarda la información en el vector cotizaciones */
bool Cotizador::LeerHistorial()
{
	/* Limpiar el vector y los punteros (si existen) */
	for(Cotizacion* cot : cotizaciones){
		delete cot;
		cot = NULL;
	}
	cotizaciones.clear();

	/* Abrir archivo */
	std::string line;
	std::fstream myfile;
	myfile.open("HistorialCotizaciones.txt", std::fstream::out | std::fstream::in | std::fstream::app);
	if(myfile){
		std::string codigoCotizacion = "";
		int linea = 0;
		std::string fecha = "";
		int codigo_vendedor = 0;
		std::string prenda = "";
		double valor_unitario = 0;
		int cantidadPrenda = 0;
		double valorCotizacion = 0;
		/* Leer el archivo y llenar el vector de cotizaciones */
		while(getline(myfile, line)){
			//Comenzar la lectura de una nueva cotización
			if(line == "Cotización"){
				linea = 0;
			}
			switch (linea) {
			case 1:
				codigoCotizacion = line;
				break;
			case 2:
				fecha = line;
				break;
			case 3:
				codigo_vendedor = ValidarEntero(line);
				break;
			case 4:
				prenda = line;
				break;
			case 5:
				valor_unitario = ValidarDouble(line);
				break;
			case 6:
				cantidadPrenda = ValidarEntero(line);
				break;
			case 7:
				valorCotizacion = ValidarDouble(line);
				break;
			}
			linea++;
			//Cuando se alcanzan todos los datos, se añade la cotización al historial en cotizaciones
			if(linea == 8){
				Cotizacion* cotizacionPtr = new Cotizacion(codigoCotizacion, fecha, codigo_vendedor, prenda, valor_unitario, cantidadPrenda, valorCotizacion);
				cotizaciones.push_back(cotizacionPtr);
			}
		}
		myfile.close();
		return true;
	}
	return false;
}

/* Funciones para validar la conversión de un string a número */
int Cotizador::ValidarEntero(std::string dato)
{
	try{
		int valorValidado;
		valorValidado = std::stoi(dato);
		return valorValidado;
	}catch(...){
		return -1;
	}
}
double Cotizador::ValidarDouble(std::string dato)
{
	try{
		double valorValidado;
		//valorValidado = std::stod(dato);
		valorValidado = atof(dato.c_str());
		return valorValidado;
	}catch(...){
		return -1;
	}
}

/* Construye un vector separando un string en vace a un delimitador */
std::vector<std::string> Cotizador::SplitStr(std::string str, std::string deli){
	std::vector<std::string> vectorString;
	int start = 0;
	int end = str.find(deli);
	while(end != -1){
		vectorString.push_back(str.substr(start, end - start));
		start = end + deli.size();
		end = str.find(deli, start);
	}
	return vectorString;
}