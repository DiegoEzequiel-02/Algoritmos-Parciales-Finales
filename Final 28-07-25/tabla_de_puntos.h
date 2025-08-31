#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED
#include "tLista.h"
typedef struct{
    char iniciales[4];
    unsigned puntaje;
}t_puntaje;

typedef struct{
    t_lista tabla;
    unsigned tam;
}t_tabla_puntos;

void crear_tabla_puntos(t_tabla_puntos* p, unsigned tam);
int agregar_puntaje(t_tabla_puntos* p, const t_puntaje* dato);
void imprimir_tabla_puntos(t_tabla_puntos* p);
void vaciar_tabla_puntos(t_tabla_puntos* p);
#endif //PUNTAJE_H_INCLUDED
