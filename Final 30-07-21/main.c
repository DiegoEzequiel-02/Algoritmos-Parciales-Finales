#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    tArbolBinBusq pRes;
    crearArbolBinBusq(&pRes);
    crearArchivos("p1.txt","p2.txt");
    bajarArchivo("p1.txt",&pRes);
    bajarArchivo("p2.txt",&pRes);
    guardarPolinomio("pr.txt",&pRes);
    vaciarArbolBinBusq(&pRes);
    return 0;
}
