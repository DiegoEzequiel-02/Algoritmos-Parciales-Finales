#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    tLista p;
    crearLista(&p);
    crearArchivo("datos.txt");
    leerArchivo("datos.txt",&p);
    mapLista(&p,imprimir);
    vaciarLista(&p);
    return 0;
}
