// DesafioCTienda.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
#include <iostream>
#include <locale>
#include "Presentador.h"

int main()
{
    //Aceptar simbolos del espa�ol
    setlocale(LC_CTYPE, "spanish");

    //Objeto presentador el cual maneja todo el sistema
    Presentador p;

    //Inicializar datos base y comenzar el programa
    p.InicializarTienda("Tienda1", "Kr 9 #55-10");
    p.InicializarVendedor(1516, "Juan", "Mart\u00EDnez");
    p.IniciarMenus();
}