#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    tArbolBinBusq p;
    crearArbolBinBusq(&p);
    crearArchivo("alumnos.dat");
    cargarArbol("alumnos.dat",&p);
    recorrerEnOrdenArbolBinBusq(&p,NULL,imprimir);
    buscarAlumnoPorDNIYGenerarInforme(&p);
    vaciarArbolBinBusq(&p);
    return 0;
}
