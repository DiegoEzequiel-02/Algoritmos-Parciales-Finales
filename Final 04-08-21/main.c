#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
int main()
{
    tArbolBinBusq arbol;
    crearArbolBinBusq(&arbol);
    crearArchivo("vehiculos.dat");
    leerArchivo("vehiculos.dat",&arbol);
    recorrerEnOrdenArbolBinBusq(&arbol,imprimir);
    return 0;
}
