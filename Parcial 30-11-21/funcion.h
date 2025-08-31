#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tArbolBinBusq.h"

typedef struct{
    int dni;
    char apelNomb[50];
    int baja; //inician en 0
}t_alumnos;

typedef struct{
    int dni;
    long pos;
}t_indice;

void crearArchivo(const char* nombArch);
int cmpDNI(const void* a, const void* b);
void crearIndiceArbolBinBusq(const char* nombArch,const char* indice, tArbolBinBusq* arbol);
void imprimirIndice(void* d);
void imprimirAlumnos(void* d);
void baja(tArbolBinBusq* p, const char* nombArch, t_indice* d);
void mostrarAlumnos(const char* nombArch);
void menu();

#endif // FUNCION_H_INCLUDED
