// DesafioCTienda.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <locale>
#include "Presentador.h"

int main()
{
    //Aceptar simbolos del español
    setlocale(LC_CTYPE, "spanish");

    //Objeto presentador el cual maneja todo el sistema
    Presentador p;

    //Inicializar datos base y comenzar el programa
    p.InicializarTienda("Tienda1", "Kr 9 #55-10");
    p.InicializarVendedor(1516, "Juan", "Mart\u00EDnez");
    p.IniciarMenus();
}