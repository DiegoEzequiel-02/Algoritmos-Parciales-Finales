#ifndef TPILA_H_INCLUDED
#define TPILA_H_INCLUDED
#include "tNodo.h"

void crearPila(tPila* p);
int apilar(tPila* p, const void* d, unsigned cantBytes);
int desapilar (tPila* p, void* d, unsigned cantBytes);
int pilaLlena(tPila* p, unsigned cantBytes);
int pilaVacia(tPila* p);
int vaciarPila(tPila *p);
#endif // TPILA_H_INCLUDED
