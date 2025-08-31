#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tLista.h"
#include "tabla_de_puntos.h"

void imprimir(const void* a);
int cmpPuntajes(const void*a, const void* b);
void crearArchivo(const char* nombArch);
void leerArchivo(const char* nombArch);

#endif // FUNCION_H_INCLUDED
