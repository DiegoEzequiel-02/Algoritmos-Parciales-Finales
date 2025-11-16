#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
int main()
{
    crearArchivo("claves.txt");
    leerArchivo("claves.txt","test.txt");
    return 0;
}
