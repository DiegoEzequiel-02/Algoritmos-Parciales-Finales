#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
int main()
{
    tCola productos, pedidos;
    crearCola(&productos);
    crearCola(&pedidos);
    crearArchProductos("productos.dat");
    leerProductos("productos.dat",&productos);
    leerPedidos("pedidos.txt",&pedidos);
    procesarPedidos("productos.dat","pedidos.txt");
    return 0;
}
