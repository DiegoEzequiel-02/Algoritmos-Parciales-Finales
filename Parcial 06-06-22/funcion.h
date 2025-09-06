#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include <stdbool.h>
#include "tLista.h"

typedef struct{
    char usuario[21];
    char nombre[51];
    char apellido[51];
    int nivel;
}t_cliente;

typedef struct{
    char codigo[16];
    char descripcion[51];
    float precio;
}t_producto;

typedef struct{
    int nivel;
    float porcDescuento;
    float topeDescuento;
    float minimoParaEnvioGratis;
}t_reglas;

typedef struct{
    char usuario[21];
    char producto[16];
    float precio;
    bool envioGratis;
}t_oferta;

void crearArchivoReglas(const char* nombArch);
void crearArchivoClientes(const char* nombArch);
void crearArchivoProductos(const char* nombArch);
void imprimir(void* a);
int cmpNivel(const void* a, const void* b);
void bajarReglasALista(const char* nombArch, tLista* p);
void crearOfertas(const char* client, const char* prods, const char* finTxT,tLista *p);

#endif // FUNCION_H_INCLUDED
