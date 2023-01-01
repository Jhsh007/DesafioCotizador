# DesafioCotizador
Prueba de C++ para Quark Academy
/********************************************************************************/
Para ejecutar el programa puede descargar la carpeta Debug, y dar doble click al archivo DesafioCotizador.exe.

Para usar el programa solo se deben seguir las instrucciones en pantalla.
/********************************************************************************/

NOTAS:
* Hay dos archivos importantes para la ejecución del programa, Stock.txt e HistorialCotizaciones.txt.
* Si bien ambos archivos estan incluidos, el modificarlos o eliminarlos evitara el uso esperado de la aplicación.
* La aplicación continuara funcionando en caso de que alguno de estos archivos falte, sin embargo, de no encontrarse el archivo
Stock.txt, el programa le pedira al usuario que contacte al administrador, evitandole usar las funciones del programa; y en el
caso del archivo HistorialCotizaciones.txt, el programa creara un archivo en blanco. En ambos casos la información contenida
debe estar en un formato especifico para ser reconocida por el programa.
* Si el archivo Stock.txt no se encuentra, o si está vacio se puede crear/modificar con la siguiente información:
Camisa-Corta-Mao-Standard-100-
Camisa-Corta-Mao-Premium-100-
Camisa-Corta-Común-Standard-150-
Camisa-Corta-Común-Premium-150-
Camisa-Larga-Mao-Standard-75-
Camisa-Larga-Mao-Premium-75-
Camisa-Larga-Común-Standard-175-
Camisa-Larga-Común-Premium-175-
Pantalon-Chupín-Standard-750-
Pantalon-Chupín-Premium-750-
Pantalon-Común-Standard-250-
Pantalon-Común-Premium-250-
--- Todo sin espacios e incluyendo todos los guiones y cuidando los saltos de linea. ---
* Si se quiere modificar el archivo HistorialCotizaciones.txt se debe seguir el siguiente formato:
Cotización
"Código de la cotización"
"fecha"
"Código vendedor"
"Tipo de prenda"
"Valor unitario"
"Cantidad"
"Valor cotizado"
--- A continuación un ejemplo(Se debe utilizar la palabra Cotización antes de los datos específicos) ---
Cotización
001
1/1/2023  12:46
1516
Pantalon - Chupín - Standard
15.77
25
346.94

/********************************************************************************/
