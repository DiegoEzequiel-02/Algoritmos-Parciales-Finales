#ifndef FUNCION_H_INCLUDED
#include "tArbolBinBusq.h"

typedef struct{
    char nombre[51];
    int dni;
    char estado;
}t_alumnos;

typedef struct{
    int valor; //dni
    long pos;
}t_indice;

void crearArchivo(const char* nombArch);
int cmpDNI(const void*a, const void*b);
void crearIndice(const char* nombArch, tArbolBinBusq* ind);
void guardarDatos(void* dato, unsigned tam, void* file);
void grabarArbol(const char* nombArch, tArbolBinBusq* ind);
void baja(tArbolBinBusq* p, const char* nombArch);
void mostrarAlumnos(const char* nombArch);
void imprimirAlumno(const void* a);
void mostrarIndice(const char* nombArch);
void imprimirIndice(void* a, unsigned n, void* params);
void menu();

#endif // FUNCION_H_INCLUDED
