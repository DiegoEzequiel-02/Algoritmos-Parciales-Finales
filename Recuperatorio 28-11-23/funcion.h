#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tCola.h"

typedef struct{
    char desc[21];
    unsigned int stock;
    float precio;
}t_productos;

typedef struct{
    int cod_ped;
    int cod_prod;
    int cant;
}t_pedidos;


#endif // FUNCION_H_INCLUDED
