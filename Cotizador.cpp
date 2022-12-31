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

/* A�ade a la tienda la cantidad de prendas seg�n su tipo, tomando como base un archivo txt ya existente  */
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
				t->A�adirPrenda(nuevaPrenda);
			}else if(prendaActual == "Pantalon"){
				calidad = datosPrenda[2];
				cantidad = ValidarEntero(datosPrenda[3]);
				Pantalon* nuevaPrenda = new Pantalon(tipo1Actual, calidad, cantidad);
				t->A�adirPrenda(nuevaPrenda);
			}
			datosPrenda.clear();
		}
		return true;
	}else{
		myfile.open("Stock.txt", std::fstream::out);
		if(myfile){
			t->A�adirPrenda(new Camisa("Corta", "Mao", "Standard", 100));
			myfile << "Camisa-Corta-Mao-Standard-100-\n";
			t->A�adirPrenda(new Camisa("Corta", "Mao", "Premium", 100));
			myfile << "Camisa-Corta-Mao-Premium-100-\n";
			t->A�adirPrenda(new Camisa("Corta", "Com�n", "Standard", 150));
			myfile << "Camisa-Corta-Com�n-Standard-150-\n";
			t->A�adirPrenda(new Camisa("Corta", "Com�n", "Premium", 150));
			myfile << "Camisa-Corta-Com�n-Premium-150-\n";
			t->A�adirPrenda(new Camisa("Larga", "Mao", "Standard", 75));
			myfile << "Camisa-Larga-Mao-Standard-75-\n";
			t->A�adirPrenda(new Camisa("Larga", "Mao", "Premium", 75));
			myfile << "Camisa-Larga-Mao-Premium-75-\n";
			t->A�adirPrenda(new Camisa("Larga", "Com�n", "Standard", 175));
			myfile << "Camisa-Larga-Com�n-Standard-175-\n";
			t->A�adirPrenda(new Camisa("Larga", "Com�n", "Premium", 175));
			myfile << "Camisa-Larga-Com�n-Premium-175-\n";
			t->A�adirPrenda(new Pantalon("Chup�n", "Standard", 750));
			myfile << "Pantalon-Chup�n-Standard-750-\n";
			t->A�adirPrenda(new Pantalon("Chup�n", "Premium", 750));
			myfile << "Pantalon-Chup�n-Premium-750-\n";
			t->A�adirPrenda(new Pantalon("Com�n", "Premium", 250));
			myfile << "Pantalon-Com�n-Standard-250-\n";
			t->A�adirPrenda(new Pantalon("Com�n", "Standard", 250));
			myfile << "Pantalon-Com�n-Premium-250-\n";
			std::cout << "LineaActual: " << t->GetTiposPrendas()[0]->GetCantidad() << "\n";
			return true;
		}else{
			return false;
		}
	}
}

/* Funciones para validar la conversi�n de un string a n�mero */
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