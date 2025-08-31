#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
#include "tLista.h"

typedef struct{
    char codLote[5];
    int idProducto;
    char resultadoControl[10];
}t_planta;

void crearLote(const char* nombArch);
void leerArchivo(const char* nombArch,tLista* observados, tLista* aprobados, int porcFallas);
void guardarAprobados(const char* nombArch,tLista* aprobados);
void guardarObservados(const char* nombArch,tLista* observados);
void imprimir(const void* a);
void leerYMostrar(const char* nombArch);
void leerSalida(const char* nombArch);
void menu();

#endif // FUNCION_H_INCLUDED
