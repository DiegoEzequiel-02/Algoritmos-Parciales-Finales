#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tLista.h"
typedef struct{
    int dni;
    char nombreApl[25];
    int tiempo; //(en segundos)
}t_maraton;

void imprimir(const void* a);
int cmpTiempo(const void* a, const void* b);
void crearArchivo(const char* nombArch);
void leerArchivo(const char* nombArch,tLista* p);

#endif // FUNCION_H_INCLUDED
