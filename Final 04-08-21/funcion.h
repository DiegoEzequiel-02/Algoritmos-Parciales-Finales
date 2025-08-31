#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tArbolBinBusq.h"

typedef struct{
    char dominio[7];
    int antig;
    int kms;
}t_vehiculos;

typedef struct{
    int antig;
    int repes;
    int kms;
}t_contar;

void imprimir(const void* a);
void crearArchivo(const char* nombArch);
int cmpAntig(const void*a, const void*b);
void imprimir(const void* a);
void leerArchivo(const char* nombArch, tArbolBinBusq* p);
#endif // FUNCION_H_INCLUDED
