#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    tLista lista;
    crearLista(&lista);
    crearArchivo("cuentas.txt");
    guardarDatos("cuentas.txt",&lista,cmpNroCuenta);
    mapLista(&lista,imprimir);
    eliminarUltimosNdeLaLista(&lista,4);
    printf("Lista actualizada\n");
    mapLista(&lista,imprimir);
    generarResultado("resultadoCuentas.bin",&lista);
    printf("ARCHIVO RESULTADO\n");
    leerArchivo("resultadoCuentas.bin");
    vaciarLista(&lista);
}
