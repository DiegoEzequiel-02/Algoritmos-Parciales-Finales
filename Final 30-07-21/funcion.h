#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tArbolBinBusq.h"

typedef struct{
    int potencia;
    int coeficiente;
}t_polinomio;

int cmpPotencia(const void* a, const void* b);
void crearArchivos(const char* nombArch1, const char* nombArch2);
void bajarArchivo(const char* nombArch, tArbolBinBusq* p);
void guardarDato(void* dato, void* arch);
void guardarPolinomio(const char* nombArch, tArbolBinBusq* p);

#endif // FUNCION_H_INCLUDED
