#include "Cotizador.h"
#include "Cotizacion.h"
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
//	myfile.open("Stock.txt", std::fstream::out | std::fstream::in | std::fstream::app);
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
			std::cout << datosPrenda.size() << "\n";
			tipo1Actual = datosPrenda[1];
			if(prendaActual == "Camisas"){
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
		valorValidado = std::stod(dato);
		return valorValidado;
	}catch(...){
		return -1;
	}
}

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