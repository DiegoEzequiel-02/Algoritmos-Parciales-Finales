#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tLista.h"

typedef struct{
    unsigned int nroCuenta;
    char tipoCuenta[3];
    char aplNomb[26];
    unsigned int extClave;
    float saldo;
}t_banco;

void imprimir(const void* a);
void guardarDatos(const char* nombArch, tLista* p, int (*cmp)(const void*, const void*));
int cmpClave(const void* a, const void* b);
int cmpTipoCuenta(const void* a, const void* b);
int cmpNroCuenta(const void* a, const void* b);
void crearArchivo(const char* nombArch);
void generarResultado(const char* nombArch,tLista* p);
void leerArchivo(const char* nombArch);

#endif // FUNCION_H_INCLUDED
