#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    tLista p;
    crearLista(&p);
    crearArchivoClientes("Clientes.dat");
    crearArchivoProductos("Productos.dat");
    crearArchivoReglas("Reglas.txt");
    bajarReglasALista("Reglas.txt",&p);
    crearOfertas("Clientes.dat","Productos.dat","Ofertas.txt",&p);
    vaciarLista(&p);
    return 0;
}
